/* A composite is a number containing at least 
 * two prime factors. For example, 15 = 3 × 5; 
 * 9 = 3 × 3; 12 = 2 × 2 × 3.

 * There are ten composites below thirty containing 
 * precisely two, not necessarily distinct, prime 
 * factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

 * How many composite integers, n < 10**8, have
 * precisely two, not necessarily distinct, prime factors?

 * Project Euler: 187 
 *
 * Answer: 17427258 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>


#define MAX                     100000000


/* Prototypes */
uint64_t countSemiprimes(uint64_t max);
int main(int argc, char** argv);
uint64_t* sieve(uint64_t max);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu64"\n", countSemiprimes(MAX));
        
        return 0;

}

uint64_t countSemiprimes(uint64_t max)
{
        uint64_t prime_max = max / 2;

        uint64_t c = 0;

        uint64_t* primes = sieve(prime_max);

        for(uint64_t i = 0; i < prime_max; i++){
                if(!primes[i]) continue;

                for(uint64_t j = i; j < prime_max; j++){

                        if(!primes[j]) continue;

                        if(i * j >= max) break;

                        c++;
                }
        }

        free(primes);

        return c;
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

        
