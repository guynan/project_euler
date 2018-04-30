/* Quadratic Primes
 *
 * Project Euler: 27
 *
 * Answer: -59231 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


#define MAX                     1000
#define MIN                     -999
#define QUAD_F(a, b, n)         (pow((n), 2) + ((a) * (n)) + (b))


int32_t consecPrimes(int16_t a, int16_t b);
int main(int argc, char** argv);
int isPrime(int32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int16_t a, b, chain;

        /* Saves all the attributes about longest array
         * so if you want to find out about it you don't
         * need an unwieldly number of extra variables */
        int16_t *longest = calloc(3, sizeof(int16_t));

        for(a = MIN; a < MAX; a += 2){
                for(b = a; b < MAX; b += 2){
                        chain = consecPrimes(a, b);

                        if(chain > *longest){
                                longest[0] = chain;
                                longest[1] = a;
                                longest[2] = b;
                        }
                }
        }

        printf("%"PRId32"\n", (int32_t) longest[1] * longest[2]);

        free(longest);

        return 0;

}


/* Detects whether int is prime */
int isPrime(int32_t s)
{
        if (s < 2)
                return 0;

        int32_t top = (int32_t) round((float) sqrt(s));

        for(int32_t i = 2; i <= top; i++){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}


/* Counts how many primes can be generated using
 * this sequence of f(a, b). Uses the prime array to
 * pass to check if the number we are testing is prime */
int32_t consecPrimes(int16_t a, int16_t b)
{
        int32_t count = 0;
        int32_t tmp;

        for(int32_t n = 1; ; n += 2){

                tmp = QUAD_F(a, b, n);

                if(isPrime(tmp))
                        count++;
                else
                        break;
        }

        return count;

}

