/* Finding the longest Collatz sequence
 * under 1 million.
 *
 * Answer: 837799
 *
 * Project Euler: 14 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


/* Apply the Collatz function to n */
#define COLLATZ_MACRO(n)        (((n) % 2 == 0) ? (n)/2 : (3*(n)) + 1)
#define MAX                     1000000

int main(int argc, char** argv);

/* Global access for the length of the longest Collatz sequence
 * and what number --thus far-- generates the longest sequence */
static uint64_t longest = 0;
static uint64_t longcount = 0;


int main(int argc, char** argv)
{
        /* To reduce recalculations, we store results for the count of numbers
         * in this array to cache the result of the previous additions and
         * be able to add that to newer calculations, making this approximately
         * able to run in linear time... */
        uint64_t* collatz = NULL;
        collatz = calloc(MAX + 2, sizeof(uint64_t));

        if(!collatz){
                return -1;
        }

        for(uint64_t i = 2; i < MAX; i++){

                uint64_t count = 0;
                for(uint64_t n = i; n != 1; count++){

                        /* Check to see if function has been applied already;
                         * if so, add this to the current count and move on */
                        if(n < MAX && collatz[n]){
                                count += collatz[n];
                                break;
                        }

                        n = COLLATZ_MACRO(n);
                }

                if (count > longcount){
                        longcount = count;
                        longest = i;
                }

                collatz[i] = count;
        }

        free(collatz);

        printf("%"PRIu64"\n", longest);

        return 0;
}

