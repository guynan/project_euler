/* A Pythagorean triplet is a set of
 * three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet
 * for which a + b + c = 1000.
 * Find the product abc.
 *
 * Answer: 31875000
 * Project Euler: 9 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define PERIMETER       1000


int main(int argc, char** argv);
int ispythag(uint32_t a, uint32_t b, uint32_t c);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t a, b, c;

        for(a = 1; a < PERIMETER; a++){

                for(b = 1; b < PERIMETER; b++){

                        c = PERIMETER - (a + b);

                        if(ispythag(a, b, c)){
                                goto out;
                        }

                }

        }

out:

        printf("%"PRIu32"\n", a * b * c);

        return 0;
}

int ispythag(uint32_t a, uint32_t b, uint32_t c)
{
        return ((a * a) + (b * b) == (c * c));
}

