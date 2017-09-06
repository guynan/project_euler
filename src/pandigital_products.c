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
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

/* Obviously will be less than this */
#define MAX_PANDIGIT            9876
#define PANDIGIT_STR            "123456789"


int isPandigital(uint32_t i, uint32_t j, uint64_t prod);
int charcomp(const void* a, const void* b);
int in(uint64_t i, uint64_t* arr);
int main(int argc, char** argv);
uint32_t productSum(void);



int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", productSum());

        return 0;

}


/* Here we cast all of the numbers to strings, concatenate, sort
 * and perhaps compare them to a string */
int isPandigital(uint32_t i, uint32_t j, uint64_t prod)
{
        char* a; char* res;

        a = malloc(10 * sizeof(char));
        res = malloc(10 * sizeof(char));
                
        /* There has got to be a better fucking way of
         * doing this but OH WELL */
        sprintf(res, "%d", i);
        sprintf(a, "%d", j);
        strcat(res, a);
        sprintf(a, "%"PRIu64, prod);
        strcat(res, a);

        qsort(res, strlen(res), sizeof(char), charcomp);

        free(a);
        return (0 == strcmp(res, PANDIGIT_STR));

}

int charcomp(const void* a, const void* b)
{
        return (*((char*) a) - *((char*) b));
}

/* Need to search the whole array as the list is unsorted */
int in(uint64_t i, uint64_t* arr)
{

        while( *arr ){
                if(*arr == i) return 1;
                arr++;
        }

        return 0;

}

uint32_t productSum(void)
{
        uint32_t i, j, product;

        uint64_t productSum;

        productSum = 0;

        uint64_t* productList;

        uint32_t index = 0;

        /* Rid yourself of the magic number please */
        productList = malloc(20 * sizeof(uint64_t));

        for(i = 1; i < MAX_PANDIGIT; i++){
                for(j = 1; j < MAX_PANDIGIT; j++){

                        if(i == j) continue;
                        
                        product = i * j;

                        if(product > MAX_PANDIGIT) continue; 

                        if(isPandigital(i, j, product)){
                                if(!in(product, productList)) {
                                        productList[index++] = product;
                                        productSum += product;
                                }

                        }

                }

        }

        return productSum;

}
