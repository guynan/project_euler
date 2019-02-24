/* Quadratic Primes
 *
 * Project Euler: 27
 *
 * Answer: -59231 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX                     1000
#define MIN                     -999
#define QUAD_F(a, b, n)         ((n) * (n) + ((a) * (n)) + (b))


int32_t consecprimes(int32_t a, int32_t b);
int main(int argc, char** argv);
int is_prime(int32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t a, b, chain;

        int32_t product = 0;
        int32_t longest = 0;

        for(a = MIN; a < MAX; a += 2){

                for(b = a; b < MAX; b += 2){

                        chain = consecprimes(a, b);

                        if(chain > longest){
                                longest = chain;
                                product = a * b;

                        }
                }
        }

        printf("%"PRId32"\n", product);


        return 0;

}


/* Primality by trial division */
int is_prime(int32_t s)
{
        int32_t res = !(s <= 2 || (s & 0x1) != 1);

        for(int32_t i = 3; res && i * i <= s; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}


/* Counts how many primes can be generated using this sequence of f(a, b). */
int32_t consecprimes(int32_t a, int32_t b)
{
        int32_t tmp = 1;
        int32_t count = 0;

        /* This is a highly cheeky for loop. The first and only statement is
         * hard to parse for the untrained eye. */
        for(int32_t n = 1; tmp; n += 2){

                count += (tmp = is_prime(QUAD_F(a, b, n)));
        }

        return count;

}

