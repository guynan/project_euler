/* Find the first triangle number with over
 * 500 divisors.
 * Answer: 76576500
 *
 * Project Euler: 12 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX 500
#define MAXLEN 50000


uint64_t maxTriDivis(uint64_t max);
int main(int argc, char** argv);
uint64_t numdivis(uint64_t f);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu64"\n", maxTriDivis(MAX));

        return 0;
}

uint64_t maxTriDivis(uint64_t max)
{
        uint64_t tri = 3;

        for(uint64_t i = 3; ; tri += i++){
                
                if (numdivis(tri) > max)
                        break;
        }

        return tri;
}

uint64_t numdivis(uint64_t f)
{
        uint64_t count = 1;

        for(uint64_t i = 1; i*i < f; count += (f % i++ == 0))
                ;

        return 2 * count;

}

