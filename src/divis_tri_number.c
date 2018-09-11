/* Find the first triangle number with over
 * 500 divisors.
 * Answer: 76576500
 *
 * Project Euler: 12 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX     500


int32_t max_tri_divis(int32_t max);
int main(int argc, char** argv);
int32_t numdivis(int32_t f);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRId32"\n", max_tri_divis(MAX));

        return 0;
}

int32_t max_tri_divis(int32_t max)
{
        int32_t tri = 3;

        for(int32_t i = 3; numdivis(tri) <= max; tri += i++)
                ;

        return tri;
}

int32_t numdivis(int32_t f)
{
        int32_t count = 1;

        for(int32_t i = 1; i*i < f; count += (f % i++ == 0))
                ;

        return 2 * count;
}

