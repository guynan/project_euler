/* The number, 1406357289, is a 0 to 9 pandigital number because it is made up
 * of each of the digits 0 to 9 in some order, but it also has a rather
 * interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
 * note the following:
 *
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 *
 * Project Euler: 43
 *
 * Answer: 16695334890 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>


#define START           1023456789
#define MAX             4999999999
#define BASE            10


static const int PRIMES[] = {17, 13, 11, 7, 5, 3, 2};

int is_pandigit(uint64_t i);
int substring_divis(uint64_t n);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* A couple of things that speed up our computation:
         *
         *      All pandigital numbers (0-9) are divisible by 9 so we can
         *      increment by 9 to reduce our search space. We start with the
         *      first known pandigital number, so we know each subsequently
         *      generated number is far more likely to be one too.
         *
         *      I have found that it is also considerably more computationally
         *      efficient to first check if the number is substring divisible
         *      before checking whether it is a pandigit. This is because all
         *      numbers --irrespective of their unsuitability-- must be checked
         *      and my algorithm for checking if it is pandigital relies on
         *      sorting the number first even before any suitability checking
         *      can commence. This means that it takes O(n log n) time. */

        uint64_t sum = 0;

        for(uint64_t i = START; i < MAX; i+= 9){
                sum += (substring_divis(i) && is_pandigit(i)) ? i : 0;
        }

        printf("%"PRIu64"\n", sum);

        return 0;

}


int is_pandigit(uint64_t i)
{
        uint32_t set_ints = 0x0;
        uint32_t bit_mask = 0x0;

        for( ; i; i /= BASE){
                bit_mask = 0x1;
                bit_mask <<= i % BASE;
                set_ints ^= bit_mask;

                if(set_ints & bit_mask == 0){
                        return 0;
                }
        }

        return set_ints == 0x3FF;

}

int substring_divis(uint64_t n)
{
        uint16_t tmp;

        for(uint8_t i = 0; n > 1000; ){

                tmp = (n % 1000);

                if(tmp % PRIMES[i++]){
                        return 0;
                }

                n /= 10;
        }

        return 1;

}

