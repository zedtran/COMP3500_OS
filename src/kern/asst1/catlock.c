/*
 * catlock.c
 *
 * 30-1-2003 : GWA : Stub functions created for CS161 Asst1.
 *
 * NB: Please use LOCKS/CV'S to solve the cat syncronization problem in
 * this file.
 */

/*
 *
 * Includes
 *
 */

#include <types.h>
#include <lib.h>
#include <test.h>
#include <thread.h>
#include <synch.h>
#include <scheduler.h>


/*
 *
 * Constants
 *
 */

/*
 * Number of food bowls.
 */

#define NFOODBOWLS 2

/*
 * Number of cats.
 */

#define NCATS 6

/*
 * Number of mice.
 */

#define NMICE 2


struct lock *cat_mouse_lock;
struct lock *bowl_lock[NFOODBOWLS];
struct lock *finished_count_lock;

int cats_currently_eating = 0;
int num_finished = 0;

/*
 *
 * Function Definitions
 *
 */


// print statements in a function
static void
lock_eat(const char *who, int num, int bowl, int iteration)
{
    kprintf("%s: %d starts eating: bowl %d, iteration %d\n", who, num,
        bowl, iteration);
    clocksleep(1);
    kprintf("%s: %d ends eating: bowl %d, iteration %d\n", who, num,
        bowl, iteration);
}

// picking a bowl and syncronizing access to bowl
static void
try_eat_some_bowl(const char *who, int num, int iteration)
{
    // gets random bowl
    int bowl = (int)(random() % NFOODBOWLS) + 1;

    // wait for lock on random bowl, eat from it, then return
    lock_acquire(bowl_lock[bowl]);
    lock_eat(who, num, bowl, iteration);
    lock_release(bowl_lock[bowl]);
}


/*
 * catlock()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long catnumber: holds the cat identifier from 0 to NCATS -
 *      1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using locks/cv's.
 *
 */

static
void
catlock(void * unusedpointer,
        unsigned long catnumber) {
        /*
         * Avoid unused variable warnings.
         */

        (void) unusedpointer;
        (void) catnumber;

        int i;

        for(i = 0; i < 4;) {
        
            // must acquire lock
            lock_acquire(cat_mouse_lock);

            if(cats_currently_eating == 0 || cats_currently_eating == 1) {
                // Eating
                cats_currently_eating++;
                lock_release(cat_mouse_lock);
                try_eat_some_bowl("cat", catnumber, i);

                // Finished eating
                lock_acquire(cat_mouse_lock);
                cats_currently_eating--;
                lock_release(cat_mouse_lock);

                // increment iterator
                ++i;
            }
            
            else {
                // release if can't eat
                lock_release(cat_mouse_lock);
            }
            
            thread_yield();
        }

        // cat is finished eating
        lock_acquire(finished_count_lock);
        
        ++num_finished;
        
        lock_release(finished_count_lock);
}


/*
 * mouselock()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long mousenumber: holds the mouse identifier from 0 to
 *              NMICE - 1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using locks/cv's.
 *
 */

static
void
mouselock(void * unusedpointer,
          unsigned long mousenumber) {
        /*
         * Avoid unused variable warnings.
         */

        (void) unusedpointer;
        (void) mousenumber;

        int i;

        for(i = 0; i < 4;) {
        
            lock_acquire(cat_mouse_lock);

            // cats eating gets set to 3 so that cat's can no longer access bowl
            // as only 2 can eat at a time
            if(cats_currently_eating == 0 || cats_currently_eating >= 3) {
               
                
                cats_currently_eating = (cats_currently_eating == 0) ? 3 :
                    (cats_currently_eating + 1);
                    
                lock_release(cat_mouse_lock);
                
                try_eat_some_bowl("mouse", mousenumber, i);

                // finished eating
                lock_acquire(cat_mouse_lock);
                
                cats_currently_eating = (cats_currently_eating == 3) ? 0 :
                    (cats_currently_eating - 1);
                    
                lock_release(cat_mouse_lock);

                ++i;
            }
            
            else {
            
                lock_release(cat_mouse_lock);
                
            }
            
            thread_yield();
        }

        // mouse is finished
        lock_acquire(finished_count_lock);
        ++num_finished;
        lock_release(finished_count_lock);
}


/*
 * catmouselock()
 *
 * Arguments:
 *      int nargs: unused.
 *      char ** args: unused.
 *
 * Returns:
 *      0 on success.
 *
 * Notes:
 *      Driver code to start up catlock() and mouselock() threads.  Change
 *      this code as necessary for your solution.
 */

int
catmouselock(int nargs,
             char ** args) {
             
        int index, error;

        /*
         * Avoid unused variable warnings.
         */
        (void) nargs;
        (void) args;

        // initialize locks
        cat_mouse_lock = lock_create("cat_mouse_lock");
        assert(cat_mouse_lock != NULL);
        
        finished_count_lock = lock_create("finished_count_lock");
        assert(finished_count_lock != NULL);
        
        
        for (index = 0; index < NFOODBOWLS; ++index) {
            bowl_lock[index] = lock_create("bowl_lock");
            assert(bowl_lock[index] != NULL);
        }
        
        cats_currently_eating = 0;
        num_finished = 0;

        // start catlock threads
        for (index = 0; index < NCATS; index++) {

                error = thread_fork("catlock thread",
                                    NULL,
                                    index,
                                    catlock,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {

                        panic("catlock: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }

        // start mouselock threads
        for (index = 0; index < NMICE; index++) {

                error = thread_fork("mouselock thread",
                                    NULL,
                                    index,
                                    mouselock,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {

                        panic("mouselock: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }

        // wait for everyone to finished
        while(num_finished < (NCATS + NMICE)) {
            thread_yield();
        }

        // destroy locks
        lock_destroy(cat_mouse_lock);
        lock_destroy(finished_count_lock);
        for(index = 0; index < NFOODBOWLS; ++index) {
            lock_destroy(bowl_lock[index]);
        }

        return 0;
}

/*
 * End of catlock.c
 */
