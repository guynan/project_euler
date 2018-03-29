/* A googol (10^100) is a massive number:
 * one followed by one-hundred zeros;
 * 100^100 is almost unimaginably large:
 * one followed by two-hundred zeros.
 * Despite their size, the sum
 * of the digits in each number is only 1.

 * Considering natural numbers of the form,
 * a^b, where a, b < 100, what is the
 * maximum digital sum?
 *
 * Answer: 972
 * Project Euler: 56 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <gmp.h>

#define MAX     100
#define BASE    10

int main(int argc, char** argv);
uint64_t digitalSum(mpz_t i);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        mpz_t digit;
        uint64_t max, sum;

        mpz_init(digit);

        for(uint64_t a = 1 ; a <= MAX; a++){
                for(uint64_t b = 1; b <= MAX; b++){

                        mpz_ui_pow_ui(digit, a, b);
                        sum = digitalSum(digit);

                        /* Assign if bigger */
                        max = (sum > max) ? sum : max;
                }

        }

        mpz_clear(digit);

        printf("%"PRIu64"\n", max);

        return 0;

}


/* Very simple cast to string; sum iteration */
uint64_t digitalSum(mpz_t i)
{
        uint64_t sum = 0;
        char* str = mpz_get_str(NULL, BASE, i);

        for( ; *str != '\0'; sum += (*str++ - '0'))
                                ;
        free(str);
        return sum;
}

