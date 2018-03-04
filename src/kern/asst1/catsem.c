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

#define NMAXTIME


/*
 * Defining boolean type (not native to C)
 */
#define true 1
#define false 0
typedef char bool;


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

// SEMAPHORES
struct semaphore *cats_queue; // 0 initially -- locks other cats
struct semaphore *mice_queue; // 0 initially -- locks other mice
struct semaphore *mutex; // 1 initially -- locks to either a cat or a mouse
struct semaphore *dish_mutex; // 1 initially -- locks two animals of the same type
struct semaphore *done; // 0 initially --helps with bowl assignments before and after eating


volatile int mice_wait_count = 0;
volatile int cats_wait_count = 0;


volatile bool all_dishes_available = true;
volatile bool no_cat_eat = true; // first cat
volatile bool no_mouse_eat = true; // first mouse

volatile bool dish1_taken = false;
volatile bool dish2_taken = false;



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

        bool first_cat_eat;
        bool another_cat_eat;
        int my_dish;


        (void) unusedpointer;
        (void) catnumber;

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
        
        ////////////////////////////////////////

        /* THIS IS WHERE FIRST CAT DETERMINES KITCHEN DOMINANCE FOR CATS */
        if (first_cat_eat == true) {
          P(mutex);
          if (cats_wait_count > 1) {
            another_cat_eat = true;
            V(cats_queue); /* let another cat in */
          }
          V(mutex);
        }

        kprintf("Cat %lu in the kitchen.\n", catnumber+1);
        
        ////////////////////////////////////////

        /* All cats (first cat and non-first cat) in the kitchen */
        P(dish_mutex); /* protect shared variables */
        if (dish1_taken == false) {
          dish1_taken = true;
          my_dish = 1;
        }
        else {
          assert(dish2_taken == false);
          dish2_taken = true;
          my_dish = 2;
        }
        V(dish_mutex);
        kprintf("Cat %lu is eating at dish %d.\n", catnumber+1, my_dish);
        clocksleep(random() % (NMAXTIME + 4)); /* enjoys food */
        //clocksleep(1); // FOR TESTING ONLY -- uncomment above line when ready
        kprintf("Cat %lu finished eating at dish %d.\n", catnumber+1, my_dish);
        
        ////////////////////////////////////////
        
        //kprintf("DEBUG MESSAGE: Passed line 180, Attempting to release dish. Working with cat #%lu on dish #%d.\n", catnumber+1, my_dish);

        /* All cats (first cat and non-first cat) RELEASE DISHES */
        P(dish_mutex); /* Protect shared variables */
        if (my_dish == 1) { // Release dish 1
          dish1_taken = false;
        }
        else { // Release dish 2
          dish2_taken = false;
        }
        V(dish_mutex);
        
        //kprintf("DEBUG MESSAGE: Passed line 192, RELEASE DISH OCCURRED. Working with cat #%lu on dish #%d.\n", catnumber+1, my_dish);

        P(mutex);
          cats_wait_count--; /* Reduced before leaving */
        V(mutex);
        
        //kprintf("DEBUG MESSAGE: Passed line 197, cats_wait_count decremented. Working with cat #%lu.\n", catnumber+1);
        
        ////////////////////////////////////////
        //kprintf("DEBUG MESSAGE: Passed line 203, Cat %lu trying to leave the kitchen.\n", catnumber+1);
        /* First cat is leaving the kitchen */
        if (first_cat_eat == true) { /* First cat */
          if (another_cat_eat == true) {
            P(done); /* Wait for another cat */
          }
          kprintf("Cat %lu is leaving.\n", catnumber+1);
          no_cat_eat = true; /* Letting the next cat control */

          /* Switch to mice if any is waiting */
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
        
        //kprintf("DEBUG MESSAGE: Passed line 228, Cat %lu left the kitchen.\n", catnumber+1);



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
        
        bool first_mouse_eat;
        bool another_mouse_eat;
        int my_dish;
        
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
          V(mutex);
        }

        kprintf("Mouse %lu in the kitchen.\n", mousenumber+1);
        
        ////////////////////////////////////////

        /* Both mice (first mouse and second mouse) in the kitchen */
        P(dish_mutex); /* protect shared variables */
        if (dish1_taken == false) {
          dish1_taken = true;
          my_dish = 1;
        }
        else {
          assert(dish2_taken == false);
          dish2_taken = true;
          my_dish = 2;
        }
        V(dish_mutex);
        kprintf("Mouse %lu is eating at dish %d.\n", mousenumber+1, my_dish);
        clocksleep(random() % NMAXTIME); /* enjoys food */
        //clocksleep(1); // FOR TESTING ONLY -- uncomment above line when ready
        kprintf("Mouse %lu finished eating at dish %d.\n", mousenumber+1, my_dish);
        
        ////////////////////////////////////////
        
        //kprintf("DEBUG MESSAGE: Passed line 319, Attempting to release dish. Working with mouse #%lu on dish #%d.\n", mousenumber+1, my_dish);

        /* Both Mice (first and second mouse) RELEASE DISHES */
        P(dish_mutex); /* Protect shared variables */
        if (my_dish == 1) { // Release dish 1
          dish1_taken = false;
        }
        else { // Release dish 2
          dish2_taken = false;
        }
        V(dish_mutex);

        P(mutex);
          mice_wait_count--; /* Reduced before leaving */
        V(mutex);
        
        //kprintf("DEBUG MESSAGE: Passed line 337, mice_wait_count decremented. Working with mouse #%lu.\n", mousenumber+1);
        
        //kprintf("DEBUG MESSAGE: Passed line 340, RELEASE DISH OCCURRED. Mouse #%lu released dish #%d.\n", mousenumber+1, my_dish);
        
        ////////////////////////////////////////
        //kprintf("DEBUG MESSAGE: Passed line 344, Mouse %lu trying to leave the kitchen.\n", mousenumber+1);
        /* First mouse is leaving the kitchen */
        if (first_mouse_eat == true) { /* First mouse */
          if (another_mouse_eat == true) {
            P(done); /* Wait for another mouse */
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
        else { // secpmd mouse is leaving
          kprintf("Mouse %lu is leaving.\n", mousenumber+1);
          V(done);
        }
        
        //kprintf("DEBUG MESSAGE: Passed line 371, Mouse %lu left the kitchen.\n", mousenumber+1);
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
        int index, error;

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
        //kprintf("DEBUG MESSAGE: Passed line 467. Entering while check for \"cats_wait_count\" and \"mice_wait_count\".\n");
        
        //P(done);
        //while (cats_wait_count < 6 && mice_wait_count < 2) {
            
        //};
        //V(done);
        
        //kprintf("DEBUG MESSAGE: Passed line 475. Left while check for \"cats_wait_count\" and \"mice_wait_count\".\n");
        
        

        return 0;
}
