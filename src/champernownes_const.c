/* Champernowne's constant

 * Project Euler: 40
 * Answer: 210 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


#define DMAX    1000000
#define BASE    10
int indexc = 0;


int main(int argc, char** argv);
int16_t intrev(int16_t i);
void append(int32_t i, int16_t* arr);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int16_t product = 1;

        int16_t* champconst = calloc(DMAX + 1, sizeof(int16_t));

        for(int32_t i = 1; indexc < DMAX; i++){
                append(i, champconst);
        }

        for(int32_t i = 1; i < DMAX; i *= 10){
                product *= champconst[i - 1];
        }

        free(champconst);

        printf("%"PRId32"\n", product);
}


void append(int32_t i, int16_t* arr)
{
        /* So that we append in the correct order... */
        int16_t* stack = calloc(64, sizeof(int16_t));
        size_t len;

        for(len = 1; i; i /= BASE){
                stack[len++] = i % BASE;
        }

        for(len--; len; len--){
                arr[indexc++] = stack[len];
        }

        free(stack);

        return;
}

