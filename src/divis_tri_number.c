/* Find the first triangle number with over
 * 500 divisors. Fuck this is big.
 * Answer: 76576500
 *
 * Project Euler: 12 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


/* Definitions */
#define MAX 500
#define MAXLEN 50000


/* Prototypes */
uint64_t maxTriDivis(uint32_t max);
int main(int argc, char** argv);
uint32_t numdivis(uint64_t f);


int main(int argc, char** argv)
{

        (void) argc;
        (void) argv;

        printf("%"PRIu64"\n", maxTriDivis(MAX));

        return 0;
}


uint64_t maxTriDivis(uint32_t max)
{
        uint64_t last = 3;

        for(uint64_t i = 3; ; last += i++){
                
                if (numdivis(last) > max) break;
        }

        return last;
}

        
uint32_t numdivis(uint64_t f)
{
        uint32_t count = 1;

        for(uint32_t i = 1; i*i < f; i++){
                count += (f % i == 0);
        }

        return 2 * count;

}

