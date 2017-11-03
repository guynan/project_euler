/* Function that returns a sieve
 * of Eratosthenes. Use this function
 * with caution as it operates in 64 bits
 * meaning we can address more memory than
 * we probably have. I would recommend not 
 * going further than pow(10,8) */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRIMEMAX        100000000

uint64_t* sieve(uint64_t max);
int main();

int main()
{
        int* a = (int*)sieve((uint32_t)PRIMEMAX);
        printf("%d\n", (int)*a);

        return 0;
}


/* Takes one argument of an integer
 * and returns a pointer to an array of
 * integers with booleans for each index
 * that indicate whether that integer is 
 * indeed a prime number. */
uint64_t* sieve(uint64_t max)
{
        uint64_t i = 0; uint64_t j = 0;

        size_t mem = max * sizeof(uint64_t);

        /* Assume kernel keeps zeroed pages and no performance hit */
	uint64_t *se = malloc(mem);

        /* 0 && 1 are not prime && can't
         * assume malloc produces 0 reliably */
        se[0] = 0; se[1] = 0;

        /* Set all values to 1; can't use memset */
        for(uint64_t c = 2; c <= max; *(se + c) = 1, c++);

        /* Start the sieve */
	for(i = 2; i <= max; i++)
	{
		if(se[i]) {
			for (j = i; (i * j) <= max; j++) {
				se[(i * j)] = 0;
			}
		}
	}

	return se;

}

