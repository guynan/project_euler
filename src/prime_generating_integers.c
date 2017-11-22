/* Consider the divisors of 30: 1,2,3,5,6,10,15,30.
 * It can be seen that for every divisor d of 30, d+30/d is prime.
 * Find the sum of all positive integers n not exceeding 100 000 000
 * such that for every divisor d of n, d+n/d is prime.
 *
 * Problem 357
 *
 * Answer */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX             100000000

int primegen(uint32_t i, uint64_t* sieve);
int main(int argc, char** argv);
uint64_t* sieve(uint64_t max);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t sum = 0;

        uint64_t* s = sieve(2 * MAX);

        for(uint32_t i = 0; i <= MAX; i++){
                sum += (primegen(i, s)) ? i : 0;
        }

        printf("%"PRIu64"\n", sum);

        return 0;

}


int primegen(uint32_t n, uint64_t* sieve)
{

        for(uint32_t i = 1; i * i <= n; i++){

                if(n % i == 0){

                        if(!sieve[i + n/i])
                                return 0;

                }
        }

        return 1;
}


/* Takes one argument of an integer and returns a pointer to an array of
 * integers with booleans for each index that indicate whether that integer is 
 * indeed a prime number. */
uint64_t* sieve(uint64_t max)
{
        uint64_t i = 0; uint64_t j = 0;

	uint64_t *se = malloc((max + 1)* sizeof(uint64_t));

        memset(se, 1, (max + 1) * sizeof(uint64_t));

        se[0] = 0; se[1] = 0;

        /* Start the sieve */
	for(i = 2; i <= max; i++){
		if(se[i]) {
			for (j = i; (i * j) <= max; j++) {
				se[(i * j)] = 0;
			}
		}
	}

	return se;

}

        
