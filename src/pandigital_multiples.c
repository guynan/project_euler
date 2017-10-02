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


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


/* Definitions */
#define MAX             9876
#define PANDIGIT_STR    "123456789"
#define MAX_DIGIT_LEN   9

/* Prototypes */
uint32_t largestPandigitalProduct(uint32_t max);
int compare(const void* a, const void* b);
uint32_t concatMultiples(uint32_t i);
int main(int argc, char** argv);
int isPandigital(const char* a);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", largestPandigitalProduct(MAX));

        return 0;

}


/* Does a simple ascii comparison such that qsort 
 * sorts the numbers relative to their numeric values */
int compare(const void* a, const void* b)
{
        return (*((char*)a) > *((char*)b));
}


/* Checks whether a string is pandigital by sorting it,
 * and comparing it to a constant string which is pandigital */
int isPandigital(const char* a)
{
        char* tmp = malloc((MAX_DIGIT_LEN + 1) * sizeof(char));
        strncpy(tmp, a, (MAX_DIGIT_LEN + 1));
        qsort(tmp, MAX_DIGIT_LEN, sizeof(char), compare);

        int res = (0 == strcmp(tmp, PANDIGIT_STR));
        free(tmp);

        return res;
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

        char* prev = NULL;

        for(uint32_t j = 1; ; j++){

                /* Needs to accomodate at most 2x */
                char* tmp = malloc(2  * MAX_DIGIT_LEN * sizeof(char));

                sprintf(tmp, "%" PRIu32, i * j);

                if(prev){
                        strncat(prev, tmp, MAX_DIGIT_LEN);
                        free(tmp);
                        tmp = prev;
                } 

                uint32_t length = strnlen(tmp, 10);

                if(length > MAX_DIGIT_LEN){
                        free(tmp);
                        return 0;
                }
                
                if(length == MAX_DIGIT_LEN && isPandigital(tmp)){
                        uint32_t k = strtol(tmp, NULL, MAX_DIGIT_LEN + 1);
                        free(tmp);
                        return k;
                }

                prev = tmp;

        }


}

