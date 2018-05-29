/*Starting with 1 and spiralling anticlockwise in the following way, a square
 * spiral with side length 7 is formed.
 *
 * 37 36 35 34 33 32 31
 * 38 17 16 15 14 13 30
 * 39 18  5  4  3 12 29
 * 40 19  6  1  2 11 28
 * 41 20  7  8  9 10 27
 * 42 21 22 23 24 25 26
 * 43 44 45 46 47 48 49
 *
 * It is interesting to note that the odd squares lie along the bottom right
 * diagonal, but what is more interesting is that 8 out of the 13 numbers lying
 * along both diagonals are prime; that is, a ratio of 8/13  62%.
 *
 * If one complete new layer is wrapped around the spiral above, a square
 * spiral with side length 9 will be formed. If this process is continued, what
 * is the side length of the square spiral for which the ratio of primes along
 * both diagonals first falls below 10%?
 *
 * Project Euler: 58
 *
 * Answer: 26241 */


#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define END_PERCENT     10


int main(int argc, char** argv);
int is_prime(int64_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* Here we can map the values of each number on the di
         *
         * S0 = n**2;
         * S1 = n**2 - (n - 1);
         * S2 = n**2 - 2(n - 1);
         * S3 = n**2 - 3(n - 1);
         *
         * Notably, we don't care about anything which is obviously a sqaure
         * number for it will never be a prime. */

        int64_t s1, s2, s3, n;
        int64_t diag_total = 5;
        int64_t count = 3;

        for(n = 5; ; n += 2){

                s1 = (n * n) - (n - 1);
                s2 = (n * n) - 2 * (n - 1);
                s3 = (n * n) - 3 * (n - 1);

                count += is_prime(s1) + is_prime(s2) + is_prime(s3);

                diag_total += 4;

                if((100 * count) / diag_total < END_PERCENT){
                        break;
                }

        }

        printf("%"PRId64"\n", n);

        return 0;

}

int is_prime(int64_t s)
{
        if (s < 2 || s == 2 || s % 2 == 0)
                return (s == 2);

        int64_t top = (int64_t) round((double) sqrt(s));

        for(int64_t i = 3; i <= top; i += 2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}

