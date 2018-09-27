/* A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of
 * the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
 * which means that 28 is a perfect number.

 * A number n is called deficient if the sum of its proper
 * divisors is less than n and it is called abundant if this sum exceeds n.

 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,
 * the smallest number that can be written as the sum of two
 * abundant numbers is 24. By mathematical analysis,
 * it can be shown that all integers greater than 28123 can
 * be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any
 * further by analysis even though it is known that the greatest
 * number that cannot be expressed as the sum of
 * two abundant numbers is less than this limit.

 * Find the sum of all the positive integers
 * which cannot be written as the sum of two abundant numbers.
 *
 * Project Euler 23
 * Answer: 4179871 */

/* This is really fucking slow - please optimise */
/* As the numbers which aren't abundant are much
 * smaller, try having that as your search space */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX     28123

int abundant(int32_t i);
int main(int argc, char** argv);
int sum_abundant(int32_t n, int32_t* abund, int32_t max);


int main(int argc, char** argv)
{
        int32_t sum = 0;
        int32_t* abund = calloc(MAX, sizeof(int32_t));

        for(int32_t i = 0; i < MAX; i++){
                abund[i] = !!abundant(i);
        }

        for(int32_t i = 0; i < MAX; i++){
                sum += (!sum_abundant(i, abund, MAX)) ? i : 0;
        }

        printf("%"PRId32"\n", sum);
        free(abund);

        return 0;

}


int abundant(int32_t i)
{
        int32_t sum = 0;

        for(int32_t a = 1; a < i; a++){
                sum += (!(i % a)) ? a : 0;
        }

        return (sum > i);

}


int sum_abundant(int32_t n, int32_t* abund, int32_t max)
{
        int32_t diff = 1;

        for(int32_t i = 0; diff > 0 && i < n; i++){

                if(!abund[i])
                        continue;

                diff = n - i;

                if(diff > 0 && abund[diff]){
                        return 1;
                }
        }

        return 0;

}

