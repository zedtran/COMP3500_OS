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
	//kprintf("SEM YOU WANT TO DESTROY: %s\n",sem->name); 
    //kprintf("CURTHREAD: %s\n",curthread->t_name);
    //kprintf("ATTEMPTING DESTROY ON: %s\tTHREAD SLEEPER COUNT: %d\n",sem->name, thread_hassleepers(sem));
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

	// initialize holder and is_locked
	lock->holder = NULL;
	lock->is_locked = 0;

	return lock;
}

void
lock_destroy(struct lock *lock)
{
	assert(lock != NULL);
	kfree(lock->name);
	kfree(lock);
}

/*
 * Get the lock. Only one thread can hold the lock at the same time.
 */
void
lock_acquire(struct lock *lock)
{
	int spl;

    // make sure lock exists
	assert(lock != NULL);
	// turn off interrupt handler
	assert(in_interrupt == 0);

	spl = splhigh();

	// put thread to sleep while locked
	while(lock->is_locked == 1) {
	    thread_sleep(lock);
	}

	// if is_locked is 0, set to 1
	assert(lock->is_locked == 0);
	lock->is_locked = 1;

	// if holder is NULL, make the holder the current thread
	assert(lock->holder == NULL);
	lock->holder = curthread;

    splx(spl);
}

/*
 * Free the lock. Only the thread holding the lock may do this.
 */
void
lock_release(struct lock *lock)
{
	int spl;

	// make sure lock isn't NULL and turn interrupts off
	assert(lock != NULL);
	spl = splhigh();

	// release lock if already is_locked
	assert(lock->is_locked == 1);
    lock->is_locked = 0;

	// set holder to NULL if lock_do_i_hold is set
    assert(lock_do_i_hold(lock) == 1);
    lock->holder = NULL;

	// wake up thread
    thread_wakeup_single(lock);

	splx(spl);
}

/*
 * Return true if current thread holds the lock; false otherwise.
 */
int
lock_do_i_hold(struct lock *lock)
{
	// intitalize spl and same
	// same is the variable used for the return where 1=holding and 0=not
    int spl, same;

	assert(lock != NULL);
	spl = splhigh();

	// if the holder is the same as the current thread, return 1
	if (lock->holder == curthread) {
	    same = 1;
	}
	// return 0 if holder isn't the same as the current thread
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

	return cv;
}

void
cv_destroy(struct cv *cv)
{
	assert(cv != NULL);
	kfree(cv->name);
	kfree(cv);
}

/*
 * Release the supplied lock, go to sleep, and
 * after waking up again, re-aquire the lock.
 */
void
cv_wait(struct cv *cv, struct lock *lock)
{
    int spl;

	// make sure cv and lock exist
    assert(cv != NULL);
    assert(lock != NULL);

	// check if thread holds the lock
    assert(lock_do_i_hold(lock) == 1);

    spl = splhigh();

	// release the lock
    lock_release(lock);

	// put thread to sleeping
    thread_sleep(cv);

	// give lock to thread
    lock_acquire(lock);

    splx(spl);
}

/*
 * Wake up one thread that's sleeping on this CV.
 */
void
cv_signal(struct cv *cv, struct lock *lock)
{
    int spl;

	// make sure cv and lock exist
    assert(cv != NULL);
    assert(lock != NULL);

    spl = splhigh();

	// wakeup thread
    thread_wakeup_single(cv);

    splx(spl);
}

/*
 * Wake up all threads sleeping on this CV
 */
void
cv_broadcast(struct cv *cv, struct lock *lock)
{
    int spl;

	// make sure cv and lock exist
    assert(cv != NULL);
    assert(lock != NULL);

    spl = splhigh();

	// wake up all sleeping threads in list
    thread_wakeup(cv);

    splx(spl);
}
