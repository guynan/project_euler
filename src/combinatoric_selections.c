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

#define NMAX            100
#define MAX_VAL         1000000


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


uint64_t combination(uint16_t n, uint16_t r);
uint32_t countCombinations(uint32_t nmax, uint32_t maxval);
uint64_t factorial(uint16_t i, uint16_t n);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", countCombinations(NMAX, MAX_VAL));

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
uint32_t countCombinations(uint32_t nmax, uint32_t maxval)
{
        uint32_t count = 0;

        /* We know that the combination function 
         * is symmetric and thusly once we have calculated
         * one side of it, we can multiply the instances 
         * that are bigger than 1mil by two to get the other side */

        for(uint16_t n = 1; n <= nmax; n++){

                /* We also know that as we approach n/2, if we find a
                 * value that is greater than 1 million early on, we know
                 * that all subsequent numbers of r up to n/2 will be even
                 * larger. What we can do is add (n/2 - r) to the half count
                 * IF the number is divisible by two, if not then we add
                 * (n/2 - r) + 1 to capture the middle value as well */

                for(uint16_t r = 1; r < n/2; r++){

                        uint64_t k = combination(n, r);

                        if(k > maxval){

                                if(n % 2 != 0) count++;

                                count += (2 * (n/2 - r) + 1);

                                break;

                        }

                }


        }

        return count;

}

