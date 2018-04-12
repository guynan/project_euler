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
int isPentagonal(uint32_t x);
int perfect_square(uint32_t n);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t pb, pa;

        for(uint32_t a = 5; ; a++){
                pa = PENT(a);

                for(uint32_t b = 5; b < a; b++){
                        pb = PENT(b);

                        if(isPentagonal(pa-pb) && isPentagonal(pa+pb)){
                                goto done;
                        }
                }

        }

done:
        printf("%"PRIu32"\n", pa-pb);

        return 0;

}



/* Asks if is pentagonal by
 * iterating over the pentagon array */
int isPentagonal(uint32_t x)
{
        uint32_t tmp = 24 * x + 1;

        return (perfect_square(tmp) &&
                (uint32_t) sqrt((double) tmp) % 6 == 5);
}


int perfect_square(uint32_t n)
{
        uint32_t tmp = (uint32_t) sqrt((double) n);
        return ((tmp * tmp) == n);
}



