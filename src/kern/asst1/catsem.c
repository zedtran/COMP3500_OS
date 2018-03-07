/*
 * catsem.c
 *
 * 30-1-2003 : GWA : Stub functions created for CS161 Asst1.
 *
 * NB: Please use SEMAPHORES to solve the cat syncronization problem in
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

/*
 * Number to represent "play around" and "eat food" to be called during clocksleep().
 */

#define NMAXTIME 3



/*
 * Defining boolean type (not native to C)
 */
#define true 1
#define false 0
typedef char bool;


/* 
*   TODO: 
*   (1) Ensure clocksleep() has random param
*   (2) Fix comments
*   (3) Modularize reused code 
*   
*   WORKING NOTES:
*   -- Fixed issue where my_dish needed to include "volatile" identifier
*   -- Current issue: Last cat doesn't leave
*
*/


/*
 *
 * Function Definitions
 *
 */


 /*
  *
  * Global variables
  *
  */
  static const char catNames

// SEMAPHORES
struct semaphore *cats_queue; // 0 initially -- locks other cats
struct semaphore *mice_queue; // 0 initially -- locks other mice
struct semaphore *mutex; // 1 initially -- locks to either a cat or a mouse
struct semaphore *dish_mutex; // 1 initially -- locks two animals of the same type
struct semaphore *done; // 0 initially --helps with bowl assignments before and after eating

struct semaphore *sim_count;


volatile int mice_wait_count;
volatile int cats_wait_count;


volatile bool all_dishes_available;
volatile bool dish1_taken;
volatile bool dish2_taken;


volatile bool no_cat_eat; // first cat
volatile bool no_mouse_eat; // first mouse


/*
 * catsem()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long catnumber: holds the cat identifier from 0 to NCATS - 1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using semaphores.
 *
 */

static
void
catsem(void * unusedpointer,
       unsigned long catnumber)
{
        /*
         * Avoid unused variable warnings.
         */

        volatile bool first_cat_eat;
        volatile bool another_cat_eat;
        volatile int my_dish;
        int i;


        (void) unusedpointer;
        (void) catnumber;
        
       
    for (i = 0; i < 3; i++) {
    
        /* FIRST CAT AND NO MOUSE */
        P(mutex);
        if (all_dishes_available == true) {
          all_dishes_available = false;
          V(cats_queue); /* lets first cat in */
        }

        cats_wait_count++;
        V(mutex);

        P(cats_queue); /* first cat in, other wait */
        if (no_cat_eat == true) {
          no_cat_eat = false;
          first_cat_eat = true;
        }
        else {
          first_cat_eat = false;
        }
        


        /* THIS IS WHERE FIRST CAT DETERMINES KITCHEN DOMINANCE FOR CATS */
        if (first_cat_eat == true) {
          P(mutex);
          if (cats_wait_count > 1) {
            another_cat_eat = true;
            V(cats_queue); /* let another cat in */
          }
          else {
            assert(cats_wait_count==1);
            another_cat_eat = false;
          }
          V(mutex);
        }
        

        kprintf("Cat %lu in the kitchen.\n", catnumber+1);
        


        /* All cats (first cat and non-first cat) in the kitchen */  
        P(dish_mutex); /* protect shared variables */
        //kprintf("my_dish: %d\n",my_dish);
        if (dish1_taken == false) {
          dish1_taken = true;
          my_dish = 1;
        }
        else {
          assert(dish2_taken == false);
          dish2_taken = true;
          my_dish = 2;
        }
        //kprintf("my_dish: %d\n",my_dish);
        V(dish_mutex);
        
        
        kprintf("Cat %lu is eating at dish %d.\n", catnumber+1, my_dish);
        //clocksleep(random() % NMAXTIME); /* enjoys food */
        clocksleep(1); // FOR TESTING ONLY -- uncomment above line when ready
        kprintf("Cat %lu finished eating at dish %d.\n", catnumber+1, my_dish);

        
        /* All cats (first cat and non-first cat) RELEASE DISHES */
        P(dish_mutex); /* Protect shared variables */
        kprintf("Preparing to release dish: %d\n",my_dish);
        if (my_dish == 1) { // Release dish 1
          dish1_taken = false;
        }
        else { // Release dish 2 
          assert(dish2_taken==true);
          dish2_taken = false;
        }
        kprintf("Released dish: %d\n",my_dish);
        V(dish_mutex);

        P(mutex);
          cats_wait_count--; /* Reduced before leaving */
        V(mutex);
        

        /* First cat is leaving the kitchen */
        if (first_cat_eat == true) { /* First cat */
          if (another_cat_eat == true) {
            P(done); /* Wait for another cat */ 
          }
          kprintf("Cat %lu is leaving.\n", catnumber+1);
          no_cat_eat = true; /* Letting the next cat control */
          /* Switch to mouse if one is waiting */
            P(mutex);
            if (mice_wait_count > 0) { // if there are mice waiting
                V(mice_queue); // let mice eat
            }
            else if (cats_wait_count > 0) {
                V(cats_queue); // cat has preference
            }
            else {
                all_dishes_available = true;
            }
            V(mutex);

        } /* End of first_cat_eat */
        else { // non-first cat is leaving
            kprintf("Cat %lu is leaving.\n", catnumber+1);
            V(done); 
        }   
        
     }
     V(sim_count);   

}

/*
 * mousesem()
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
 *      Write and comment this function using semaphores.
 *
 */

static
void
mousesem(void * unusedpointer,
         unsigned long mousenumber)
{
        /*
         * Avoid unused variable warnings.
         */

        (void) unusedpointer;
        (void) mousenumber;
        
        volatile bool first_mouse_eat;
        volatile bool another_mouse_eat;
        volatile int my_dish;
        int i;
        
    for (i = 0; i < 3; i++) {
             
        /* FIRST MOUSE AND NO CAT */
        P(mutex);
        if (all_dishes_available == true) {
          all_dishes_available = false;
          V(mice_queue); /* lets first mouse in */
        }

        mice_wait_count++;
        V(mutex);

        P(mice_queue); /* first mouse in, other wait */
        if (no_mouse_eat == true) {
          no_mouse_eat = false;
          first_mouse_eat = true;
        }
        else {
          first_mouse_eat = false;
        }
        
        /* THIS IS WHERE FIRST MOUSE DETERMINES KITCHEN DOMINANCE FOR MICE */
        if (first_mouse_eat == true) {
          P(mutex);
          if (mice_wait_count > 1) {
            another_mouse_eat = true;
            V(mice_queue); /* let another mouse in */
          }
          else {
            assert(mice_wait_count==1);
            another_mouse_eat = false;
          }
          V(mutex);
        }

        kprintf("Mouse %lu in the kitchen.\n", mousenumber+1);
        

        /* Both mice (first mouse and second mouse) in the kitchen */
        P(dish_mutex); /* protect shared variables */
        kprintf("my_dish: %d\n",my_dish);
        if (dish1_taken == false) {
          dish1_taken = true;
          my_dish = 1;
        }
        else {
          assert(dish2_taken == false);
          dish2_taken = true;
          my_dish = 2;
        }
        kprintf("my_dish: %d\n",my_dish);
        V(dish_mutex);
        
        kprintf("Mouse %lu is eating at dish %d.\n", mousenumber+1, my_dish);
        //clocksleep(random() % NMAXTIME); /* enjoys food */
        clocksleep(1); // FOR TESTING ONLY -- uncomment above line when ready
        kprintf("Mouse %lu finished eating at dish %d.\n", mousenumber+1, my_dish);
        



        /* Both Mice (first and second mouse) RELEASE DISHES */
        P(dish_mutex); /* Protect shared variables */
        if (my_dish == 1) { // Release dish 1
          dish1_taken = false;
        }
        else { // Release dish 2
          assert(dish2_taken==true);
          dish2_taken = false;
        }
        V(dish_mutex);

        P(mutex);
          mice_wait_count--; /* Reduced before leaving */
        V(mutex);
        

        /* First mouse is leaving the kitchen */ 
        if (first_mouse_eat == true) { /* First mouse */
          if (another_mouse_eat == true) {
            P(done);
          }
          kprintf("Mouse %lu is leaving.\n", mousenumber+1);
          no_mouse_eat = true; /* Letting the next mouse control */
          /* Switch to cats if any are waiting */
            P(mutex);
            if (cats_wait_count > 0) { // if there are cats waiting
                V(cats_queue); // let cats eat
            }
            else if (mice_wait_count > 0) {
                V(mice_queue); // then let mice
            }
            else {
                all_dishes_available = true;
            }
            V(mutex);

        } /* End of first_mouse_eat */
        else { // second mouse is leaving
            kprintf("Mouse %lu is leaving.\n", mousenumber+1);
            V(done);
        }
     }
     V(sim_count);
        
}


/*
 * catmousesem()
 *
 * Arguments:
 *      int nargs: unused.
 *      char ** args: unused.
 *
 * Returns:
 *      0 on success.
 *
 * Notes:
 *      Driver code to start up catsem() and mousesem() threads.  Change this
 *      code as necessary for your solution.
 */

int
catmousesem(int nargs,
            char ** args)
{
        int index, error, i;

        /*
         * Avoid unused variable warnings.
         */

        (void) nargs;
        (void) args;
        
        cats_queue = sem_create("cats semaphore", (int) 0);
        assert(cats_queue != NULL);
        
        mice_queue = sem_create("mice semaphore", (int) 0);
        assert(mice_queue != NULL);
        
        mutex = sem_create("mutex", (int) 1);
        assert(mutex != NULL);
        
        dish_mutex = sem_create("dish semaphore", (int) 1);
        assert(dish_mutex != NULL);
        
        done = sem_create("done eating semaphore", (int) 0);
        assert(done != NULL);
        
        sim_count = sem_create("sim count", (int) 0);
        assert(sim_count != NULL);
        
        
        mice_wait_count = 0;
        cats_wait_count = 0;


        all_dishes_available = true;
        dish1_taken = false;
        dish2_taken = false;
        
        no_cat_eat = true; // first cat
        no_mouse_eat = true; // first mouse
        

        /*
         * Start NCATS catsem() threads.
         */

        for (index = 0; index < NCATS; index++) {

                error = thread_fork("catsem Thread",
                                    NULL,
                                    index,
                                    catsem,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {

                        panic("catsem: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }

        /*
         * Start NMICE mousesem() threads.
         */
         
         

        for (index = 0; index < NMICE; index++) {

                error = thread_fork("mousesem Thread",
                                    NULL,
                                    index,
                                    mousesem,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {

                        panic("mousesem: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }
        
        
         
        
        for (i = 0; i < 8; i++) {
            P(sim_count);
        }
        
        kprintf("cats_queue->count: %d\n",cats_queue->count);
        kprintf("mice_queue->count: %d\n",mice_queue->count);
        kprintf("mutex->count: %d\n",mutex->count);
        kprintf("dish_mutex->count: %d\n",dish_mutex->count);
        kprintf("done->count: %d\n",done->count);
        kprintf("sim_count->count: %d\n",sim_count->count);
        
        sem_destroy(cats_queue);
        sem_destroy(mice_queue);
        sem_destroy(mutex);
        sem_destroy(dish_mutex);
        sem_destroy(done);
        sem_destroy(sim_count);
        

        return 0;
}
/* 
* End of Catsem.c
*/
