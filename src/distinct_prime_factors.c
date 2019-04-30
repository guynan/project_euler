/* The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 × 7
 * 15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors
 * are:
 *
 * 644 = 2² × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors
 * each. What is the first of these numbers?
 *
 * Project Euler: 47
 *
 * Answer: 134043 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define N_FACTORS       4


uint32_t count_factors(uint32_t n);
uint32_t consecfactors(uint32_t n);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", consecfactors(N_FACTORS));

        return 0;

}


/* This code starts by picking a number and then adding to it to see if the
 * number of factors is equal to the number that we are looking for. If so, it
 * checks the next consecutive number to see if it too has the same property.
 * If in any event that it does not, but has passed the zero threshold, we can
 * add the number that did pass the constraint and move one past that for we
 * know that those integers have been check and will not contribute to a
 * successful solution. */
uint32_t consecfactors(uint32_t n)
{

        uint32_t i = 1;

        for(uint32_t c = 0; c != n; ){

                i += c + 1;

                for(c = 0 ; count_factors(i + c) == n && c < n; c++)
                        ;
        }

        return i;

}


/* We remove all factors of two so that we can iterate via two, by only
 * checking the odd numbers henceforth. We also divide by the number which is a
 * factor such that we arrive at our upper limit sooner. If `n` is equal to
 * one, then this means that we successfully got all the prime factors. If not,
 * then it must in fact be a prime, and thus we must add this for we don't
 * iterate up to the original number itself */
uint32_t count_factors(uint32_t n)
{
        uint32_t count = 0;

        for(count += !(n & 0x1); !(n & 0x1); n >>= 1)
                ;

        for(uint32_t z = 3; (z * z) < n; z += 2){

                for(count += (n % z == 0); n % z == 0; n /= z)
                        ;
        }

        return (n > 1) + count;

}

