/* The decimal number, 585 = 10010010012
 * (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than
 * one million, which are palindromic in
 * base 10 and base 2.
 *
 * Project Euler: 36
 * Answer: 872187 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX     1000000


uint32_t binrev(uint32_t i);
uint32_t intrev(uint32_t i);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t sum = 0;

        for(int i = 0; i < MAX; i++){
                sum += (!(intrev(i) ^ i) && !(binrev(i) ^ i)) ? i : 0;
        }

        printf("%"PRIu32"\n", sum);

        return 0;

}

uint32_t intrev(uint32_t i)
{
        uint32_t rev = 0;

        while(i){
                rev *= 10;
                rev += (i % 10);
                i /= 10;
        }

        return rev;

}

/* This is essentially the same algorithm as above because of course it should
 * be. Efficiently creates the reverse binary representation */
uint32_t binrev(uint32_t i)
{
        uint32_t rev = 0;

        while(i){
                rev <<= 1;
                rev ^= (i & 1);
                i >>= 1;
        }

        return rev;
}

