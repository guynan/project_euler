/* We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
 * through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 *
 * Project Euler 32
 *
 * Answer: 45228
 *
 * As a joke to myself I am writing this to be C89 compliant */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX_PANDIGIT            9876
#define MAX_MULT                2000
#define BASE                    10


uint32_t concat_ints(uint32_t* ints);
int in(uint32_t i, uint32_t* arr);
int main(int argc, char** argv);
int is_pandigit(uint32_t i);
uint32_t productSum(void);



int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", productSum());

        return 0;

}


int is_pandigit(uint32_t i)
{
        uint32_t set_ints = 0x0;
        uint32_t fault_bit = 0x2000;
        uint32_t bit_mask = 0x0;

        for( ; i; i /= BASE){
                bit_mask = 0x1;
                bit_mask <<= i % BASE;
                set_ints |= (set_ints & bit_mask) ? fault_bit : bit_mask;
        }

        return set_ints == 0x3FE;

}

uint32_t productSum(void)
{
        uint32_t i, j, product, concat, productSum;

        productSum = 0;

        uint32_t* productList;

        uint32_t index = 0;

        /* Rid yourself of the magic number please */
        productList = malloc(20 * sizeof(uint32_t));

        /* Max multiplier is 2000. This is somewhat arbitrary, however, we know
         * that 2000^2 is in excess of what could be expected to not have any
         * double ups of any integers within the concatenated numbers */
        for(i = 1; i < MAX_MULT; i++){
                for(j = 1; j < MAX_MULT; j++){

                        product = i * j;

                        if(product > MAX_PANDIGIT){
                                continue;
                        }

                        uint32_t tmp[4] = {i, j, product, 0};

                        concat = concat_ints(tmp);

                        if(is_pandigit(concat)){

                                if(!in(product, productList)) {
                                        productList[index++] = product;
                                        productSum += product;
                                }

                        }

                }

        }

        return productSum;

}


/* This performs a unordered concatenation on an array of integers, producing
 * one integer which is the digital appending of them */
uint32_t concat_ints(uint32_t* ints)
{
        uint32_t concat = *ints++;

        for( ; *ints; ints++){

                for(uint32_t tmp = *ints; tmp; tmp /= BASE){

                        concat *= BASE;
                        concat += tmp % BASE;
                }

        }

        return concat;

}

/* Need to search the whole array as the list is unsorted */
int in(uint32_t i, uint32_t* arr)
{

        while(*arr){

                if(*arr++ == i){
                        return 1;
                }
         }

        return 0;
}

