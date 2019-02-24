
/* Project Euler 145
 * Answer: 608720 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


#define LIMIT           1000000000
#define BASE            10


int main(int argc, char** argv);
uint32_t intrev(uint32_t i);
int reversible(uint32_t i);
int onlyodds(uint32_t i);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* Search space is now half a billion by limiting to odd numbers.
         * We know this to work as even + odd == odd. To exploit this,
         * we want to rule out the inevitable repititions - for example
         * testing 36 + 63 is the same as testing 63 + 36 so we count
         * only the instances of odd numbers, rejecting numbers where
         * the subsequently generated reverse number is odd too and
         * finally multiplying the count by two to account for repeats */

        uint32_t count = 0;

        for(uint32_t i = 11; i < LIMIT; i += ((count += reversible(i)), 2))
                ;

        printf("%"PRIu32"\n", 2 * count);

        return 0;

}


int reversible(uint32_t i)
{
        uint32_t rev = intrev(i);

        /* odd + even == odd */
        if(rev & 1)
                return 0;

        return onlyodds(rev + i);

}


uint32_t intrev(uint32_t i)
{
        uint32_t rev = 0;

        for(uint32_t rem = 0; i; i /= BASE){
                rem = i % BASE;
                rev *= BASE;
                rev += rem;
        }

        return rev;
}


int onlyodds(uint32_t i)
{
        for( ; ((i % BASE) & 1); i/= BASE)
                ;

        return !i;
}

