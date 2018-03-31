/* Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 *
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We
 * will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 * and 5, giving the pandigital, 918273645, which is the concatenated product
 * of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1?
 *
 * Project Euler: 38 
 *
 * Answer: 932718654 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             9876
#define MAX_DIGIT_LEN   9
#define BASE            10


uint32_t largestPandigitalProduct(uint32_t max);
uint32_t concatMultiples(uint32_t i);
uint32_t concat(uint32_t* ints);
int main(int argc, char** argv);
int isPandigital(uint32_t i);
uint32_t pow10_g(uint32_t x);
uint32_t intlen(uint32_t x);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", largestPandigitalProduct(MAX));

        return 0;

}


uint32_t pow10_g(uint32_t x)
{
        uint32_t ret = 10;

        for(int i = 1; i < x; i++){
                ret *= 10;
        }
        
        return ret;

}


uint32_t intlen(uint32_t x)
{
        uint32_t len = 0;
        while(x){
                x /= BASE;
                len++;
        }

        return len;

}


uint32_t concat(uint32_t* ints)
{
        int concat = *ints++;

        while(*ints){
                concat *= pow10_g(intlen(*ints));
                concat += *ints++;
        }

        return concat;

}


uint32_t largestPandigitalProduct(const uint32_t max)
{
        uint32_t largest = 0;

        for(uint32_t i = 1; i < max; i++){
                uint32_t k = concatMultiples(i);
                largest = (k > largest) ? k : largest;
        }

        return largest;

}


uint32_t concatMultiples(uint32_t i)
{
        uint32_t cat = i;

        for(uint32_t j = 2; ; j++){

                uint32_t ints[2] = {cat, j * i};
                cat = concat(ints);

                uint32_t length = intlen(cat);

                if(length > MAX_DIGIT_LEN){
                        cat = 0;
                        goto out;
                }
                
                if(length == MAX_DIGIT_LEN && isPandigital(cat)){
                        goto out;
                }

        }

out:

        return cat;


}


int isPandigital(uint32_t i)
{
        uint32_t* pan = NULL;

        pan = calloc(BASE, sizeof(uint32_t));

        for( ; i; i /= BASE){
                (pan[i % BASE])++;
        }


        /* At this point, for a number to be pandigital, all numbers in this
         * array must be set to 1. We know we get zeroed memory too. `i` is now
         * zero which is useful so we don't need to introduce another var */
        for(i = 1 ; i < 10; i++){

                if(pan[i] != 1){
                        i = 0;
                        goto out;
                }
        }

        i = 1;
        
out:

        free(pan);

        return i;

}

