/*
 * Synchronization primitives.
 * See synch.h for specifications of the functions.
 */

#include <types.h>
#include <lib.h>
#include <synch.h>
#include <thread.h>
#include <curthread.h>
#include <machine/spl.h>

////////////////////////////////////////////////////////////
//
// Semaphore.

struct semaphore *
sem_create(const char *namearg, int initial_count)
{
	struct semaphore *sem;

	sem = kmalloc(sizeof(struct semaphore));
	if (sem == NULL) {
		return NULL;
	}

	sem->name = kstrdup(namearg);
	if (sem->name == NULL) {
		kfree(sem);
		return NULL;
	}

	sem->count = initial_count;
	return sem;
}

void
sem_destroy(struct semaphore *sem)
{
	int spl;
	assert(sem != NULL);

	spl = splhigh();
	assert(thread_hassleepers(sem)==0);
	splx(spl);

	/*
	 * Note: while someone could theoretically start sleeping on
	 * the semaphore after the above test but before we free it,
	 * if they're going to do that, they can just as easily wait
	 * a bit and start sleeping on the semaphore after it's been
	 * freed. Consequently, there's not a whole lot of point in 
	 * including the kfrees in the splhigh block, so we don't.
	 */

	kfree(sem->name);
	kfree(sem);
}

void 
P(struct semaphore *sem)
{
	int spl;
	assert(sem != NULL);

	/*
	 * May not block in an interrupt handler.
	 *
	 * For robustness, always check, even if we can actually
	 * complete the P without blocking.
	 */
	assert(in_interrupt==0);

	spl = splhigh();
	while (sem->count==0) {
		thread_sleep(sem);
	}
	assert(sem->count>0);
	sem->count--;
	splx(spl);
}

void
V(struct semaphore *sem)
{
	int spl;
	assert(sem != NULL);
	spl = splhigh();
	sem->count++;
	assert(sem->count>0);
	thread_wakeup(sem);
	splx(spl);
}











////////////////////////////////////////////////////////////
//
// Lock.

struct lock *
lock_create(const char *name)
{
	struct lock *lock;

	lock = kmalloc(sizeof(struct lock));
	if (lock == NULL) {
		return NULL;
	}

	lock->name = kstrdup(name);
	if (lock->name == NULL) {
		kfree(lock);
		return NULL;
	}
	
	// add stuff here as needed
	
	// initialize held & holder
	lock->holder = NULL;
	lock->is_locked = 0;
	
	return lock;
}

void
lock_destroy(struct lock *lock)
{
	assert(lock != NULL);

	// add stuff here as needed
	
	kfree(lock->name);
	kfree(lock);
}


// Get the lock. Only one thread can hold the lock at the same time.
void
lock_acquire(struct lock *lock)
{
	int spl;
	assert(lock != NULL);
	assert(in_interrupt == 0);
	
	spl = splhigh();
	
	while(lock->is_locked == 1) {
	    thread_sleep(lock);
	}
	
	assert(lock->is_locked == 0);
	lock->is_locked = 1;
	
	assert(lock->holder == NULL);
	
	lock->holder = curthread;
	

    splx(spl);
}


// Free the lock. Only the thread holding the lock may do this.
void
lock_release(struct lock *lock)
{
    int spl;
	assert(lock != NULL);
	spl = splhigh();
    
    assert(lock->is_locked == 1);
    lock->is_locked = 0;
    
    assert(lock_do_i_hold(lock) == 1);
    lock->holder = NULL;
    
    thread_wakeup_single(lock);

	splx(spl);
}


// Return true if current thread holds the lock; false otherwise
int
lock_do_i_hold(struct lock *lock)
{   
    int spl, same;
    
	assert(lock != NULL);
	spl = splhigh();
	
	if (lock->holder == curthread) {
	    same = 1;
	}
	else {
	    same = 0;
	}

    splx(spl);
    
    return same;
}







////////////////////////////////////////////////////////////
//
// CV


struct cv *
cv_create(const char *name)
{
	struct cv *cv;

	cv = kmalloc(sizeof(struct cv));
	if (cv == NULL) {
		return NULL;
	}

	cv->name = kstrdup(name);
	if (cv->name==NULL) {
		kfree(cv);
		return NULL;
	}
	
	// add stuff here as needed
	
	//this_lock = NULL;
	
	return cv;
}

void
cv_destroy(struct cv *cv)
{
	assert(cv != NULL);

	// add stuff here as needed
	
	kfree(cv->name);
	kfree(cv);
}




// Release the supplied lock, go to sleep, and, after waking up again,
// re-acquire the lock
void
cv_wait(struct cv *cv, struct lock *lock)
{
    int spl;
    
    assert(cv != NULL);
    assert(lock != NULL);
    assert(lock_do_i_hold(lock) == 1);
    
    spl = splhigh();
    
    lock_release(lock);
    
    thread_sleep(cv);
    
    lock_acquire(lock);
    
    splx(spl);
}




// Wake up one thread that's sleeping on this CV
void
cv_signal(struct cv *cv, struct lock *lock)
{
    int spl;
    
    assert(cv != NULL);
    assert(lock != NULL);
    
    spl = splhigh();
    
    thread_wakeup_single(cv);
    
    splx(spl);
}




// Wake up all threads sleeping on this CV
void
cv_broadcast(struct cv *cv, struct lock *lock)
{
    int spl;
    
    assert(cv != NULL);
    assert(lock != NULL);
    
    spl = splhigh();
    
    thread_wakeup(cv);
    
    splx(spl);
}
