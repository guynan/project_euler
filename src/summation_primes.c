/* Finding the summation of primes < 2mil
 * This takes fucking ages
 *
 * Answer: 142913828922 
 *
 * Project Euler: 10 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

/* Definitions */
#define MAX 2000000

/* Prototypes */
int isPrime(uint32_t s);
int main(int argc, char** argv);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t sum = 2;

        for(uint32_t i = 3; i < MAX; i += 2){

                if (isPrime(i)) sum += i;
        }

        printf("%"PRIu64"\n", sum);

}
       

int isPrime(uint32_t s)
{
        /* Theoretically shouldn't get values
         * less than zero due to type safety */
        if (s < 2) return 0;

        /* Preventing rounding errors */
        uint32_t top = (uint32_t) round(sqrt(s) + 1);

        for(uint32_t i = 2; i < top + 1; i++){

                if(i == top) return 1;

                if(s % i == 0) break;
        }

        return 0;
}

