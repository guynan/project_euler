/* Find the pair of pentagonal numbers
 * for which their sum and difference are
 * pentagonal. What is the value of their
 * difference?

 * Answer: 5482660
 * Project Euler: 44 */


#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>


#define PENT(x)         ((3* (x)*(x) - (x))/2)


int main(int argc, char** argv);
int perfect_square(uint32_t n);
int pentagonal(uint32_t x);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t pb, pa;
        uint32_t res = 0;

        for(uint32_t a = 5; !res; a += 2){

                pa = PENT(a);

                for(uint32_t b = a / 5; !res && (b < a); b++){

                        pb = PENT(b);
                        res = (pentagonal(pa-pb) && pentagonal(pa+pb));
                }

        }

        printf("%"PRIu32"\n", pa-pb);

        return 0;

}

/* Checking if a number is pentagonal by the numerical method of the product of
 * the number and 24 plus one is both a perfect square and upon division by 6,
 * the number has a remainder of 5 */
int pentagonal(uint32_t x)
{
        uint32_t tmp = 24 * x + 1;

        return (perfect_square(tmp) &&
                (uint32_t) sqrt((double) tmp) % 6 == 5);
}


/* A dirty floating point way of checking whether a number is composed of
 * the product of two identical integers */
int perfect_square(uint32_t n)
{
        uint32_t tmp = (uint32_t) sqrt((double) n);
        return ((tmp * tmp) == n);
}

