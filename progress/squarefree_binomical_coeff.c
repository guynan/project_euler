/* There are exactly ten ways of selecting three from five, 12345:
 *
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, 5C3 = 10.
 *
 * In general,
 *
 * nCr = n! / r!(n - r)!
 * where r  n, n! = n×(n1)×...×3×2×1, and 0! = 1.
 * It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
 *
 * How many, not necessarily distinct, values of  nCr, for 1  n  100, are
 * greater than one-million?
 *
 * Problem 53
 *
 * Answer: 4075 */

#define NMAX            51


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>


uint64_t combination(uint16_t n, uint16_t r);
int squarefree(uint64_t n, uint64_t* sqprimes, uint64_t len);
uint64_t sum_squarefree_combinations(uint32_t nmax);
uint64_t sum_arr(char* arr, uint64_t len);
uint64_t* generate_sqprimes(uint64_t max);
uint64_t factorial(uint16_t i, uint16_t n);
int main(int argc, char** argv);
int is_prime(uint64_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu64"\n", sum_squarefree_combinations(NMAX));

        return 0;
}


/* The general formula for this is n!/r!(n - r)! */
uint64_t combination(uint16_t n, uint16_t r)
{
        return factorial((n - r + 1), n) / factorial(1, r);

}


/* In order to reduce the problem size I have tried to eliminate
 * as many additional calculations as possible. This factorial function
 * also accepts an argument i; which then becomes the starting number for
 * the function, calculating the product up to n. This removes a few low
 * hanging fruit. Displayed thusly with nCr with n = 9 and r = 2
 *
 *      1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9        9!
 *      ---------------------------------       ----
 *      1 x 2 x 1 x 2 x 3 x 4 x 5 x 6 x 7       2!7!
 *
 * Above we can see that we can eliminate the first 1 - 7 of both the
 * numerator and the denominator reducing this problem to:
 *
 *      8 x 9
 *      -----
 *      1 x 2
 *
 * Which is a slightly smaller problem to calculate. We expect with the
 * larger numbers to encounter the value bigger than MAX_VAL very early
 * on in the sequence thusly this optimises for when n - r is small */
uint64_t factorial(uint16_t i, uint16_t n)
{
        uint64_t f = 1;

        for( ; i <= n; f *= i++)
                ;

        return f;

}


/* This counts the "large" (values exceeding maxval) combinations in the form
 * of nCr where 1 <= n <= nmax and 1 <= r <= n. This however employs some
 * trickery to fit such large calculations into the space of 64 bit integers */
uint64_t sum_squarefree_combinations(uint32_t nmax)
{
        uint64_t n_items = combination(nmax, nmax/2 + 1);
        printf("%"PRIu64"\n", n_items);
        uint64_t* primes = generate_sqprimes(n_items);
        char* yes = calloc(n_items + 1, 1);

        /* We know that the combination function
         * is symmetric and thusly once we have calculated
         * one side of it, we can multiply the instances
         * that are bigger than 1mil by two to get the other side */

        for(uint32_t n = 1; n <= nmax; n++){

                uint32_t limit = (n & 0x1) ? n / 2 + 1 : n / 2;

                for(uint32_t r = 1; r <= limit; r++){

                        uint64_t k = combination(n, r);

                        if(squarefree(k, primes, n_items)){
                                yes[k] = 1;
                        }

                }


        }

        uint64_t sum = sum_arr(yes, n_items);

        free(primes);
        free(yes);

        return sum;

}

int squarefree(uint64_t n, uint64_t* sqprimes, uint64_t len)
{
        if(n % 4 == 0){
                return 0;
        }
        for(uint32_t i = 0; i < len && sqprimes[i]; i++){

                if(n % sqprimes[i] == 0){
                        return 0;
                }
        }

        return 1;

}

uint64_t* generate_sqprimes(uint64_t max)
{
        max = (uint64_t) round((double) sqrt(max));
        uint64_t* primes = calloc(max + 1, sizeof(uint64_t));

        uint32_t c = 0;

        for(uint64_t i = 0; i < max; i++){
                if(is_prime(i)){
                        primes[c++] = i * i;
                }
        }

        return primes;

}


int is_prime(uint64_t s)
{
        if (s <= 2 || s % 2 == 0)
                return (s == 2);

        uint64_t top = (uint64_t) round((double) sqrt(s));

        for(uint64_t i = 3; i <= top; i+=2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}

uint64_t sum_arr(char* arr, uint64_t len)
{
        uint64_t sum = 0;
        for(uint64_t i = 0; i < len; i++){
                sum += (arr[i]) ? i : 0;
        }

        return sum;

}
