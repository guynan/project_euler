/* It can be seen that the number, 125874,
 * and its double, 251748, contain
 * exactly the same digits, but in a different order.

 * Find the smallest positive integer, x, such that
 * 2x, 3x, 4x, 5x, and 6x, contain the same digits.

 * Project Euler: 52
 * Answer: 142857 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>


#define BASE                    10
#define PERMUTE_MULTIPLIER      6


int mult_permutation(int32_t i, int32_t max);
int permuted(int32_t a ,int32_t b);
int main(int argc, char** argv);
int32_t sum_digits(int32_t a);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t i;

        for(i = 1; !mult_permutation(i, PERMUTE_MULTIPLIER); i++)
                ;

        printf("%"PRIu32"\n", i);

        return 0;
}


/* Checks if the integer is valid by comparing
 * it against multiples of itself. */
int mult_permutation(int32_t i, int32_t max)
{
        int32_t compare;

        for(int32_t c = 2; c <= max; c++){
                compare = i * c;

                /* The majority will not be even remotely similar. This
                 * calculation can be done very swiftly and reduced the search
                 * space for more expensive calculations. This can also be done
                 * whilst keeping the instruction pipline pretty hot. */
                if(sum_digits(i) != sum_digits(compare))
                        return 0;

                if(!permuted(i , compare))
                        return 0;
        }

        return 1;
}


/* Checks if the integer is a permutation
 * of itself multiplied by another integer */
int permuted(int32_t a, int32_t b)
{
        int32_t* instances = calloc(BASE, sizeof(int32_t));

        for( ; a; a /= BASE){
                (instances[a % BASE])++;
        }

        for( ; b; b /= BASE){
                (instances[b % BASE])--;
        }

        /* a is now a throwaway variable and already set to 0 and come to think
         * of it, so is b so we can use this to store the return value */
        for(a = 0; a < BASE; a++){

                if(instances[a] != 0){
                        goto out;
                }
        }

        b = 1;

out:

        free(instances);
        return b;

}


int32_t sum_digits(int32_t i)
{
        int32_t sum = 0;

        for( ; i; i /= BASE){
                sum += (i % BASE);
        }

        return sum;

}

