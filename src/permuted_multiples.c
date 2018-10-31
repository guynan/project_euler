/* It can be seen that the number, 125874,
 * and its double, 251748, contain
 * exactly the same digits, but in a different order.

 * Find the smallest positive integer, x, such that
 * 2x, 3x, 4x, 5x, and 6x, contain the same digits.

 * Project Euler: 52
 * Answer: 142857 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define BASE                    10
#define PERMUTE_MULTIPLIER      6


int mult_permutation(int32_t i, int32_t max);
int permuted(int32_t a ,int32_t b);
int main(int argc, char** argv);


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

                if(!permuted(i , compare))
                        return 0;
        }

        return 1;
}


/* Strap in; this is massively cheeky. The premise is that we have two numbers
 * which the nth bit will be *toggled* for every individual digit
 * (corresponding to the n by which we increment). This is not fool proof to
 * compare these directly; for example, 11 and 33 would say that these are
 * permutations of each other because 11 would set and unset the 1st bit and 33
 * would set and unset the third bit rendering them both equal to zero. All
 * this calculation shows the odd number of occurences of digits in numbers. To
 * prevent this behaviour, we also keep a running total of the sums of the
 * digits, one incrementing, one decrementing. If this sum is equal to zero,
 * then the sum of the digits in the numbers is equal. This proves that if we
 * have an even number of occurences, it will either be of two different
 * numbers, whereby the sum of *must* be different *or* they are the same in
 * which case they are equivalent permutations. */
int permuted(int32_t a, int32_t b)
{
        uint64_t insta = 0;
        uint64_t instb = 0;
        uint64_t bit_mask = 0;
        int32_t sum = 0;

        for( ; a && b; a /= BASE, b /= BASE){

                bit_mask = 0x1;
                bit_mask <<= a % BASE;
                insta ^= bit_mask;

                bit_mask = 0x1;
                bit_mask <<= b % BASE;
                instb ^= bit_mask;

                sum += a % BASE;
                sum -= b % BASE;
        }

        return insta == instb && !sum;

}

