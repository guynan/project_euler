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
#define MAX             9876543299
#define PANDIGIT        "9876543210"
#define PANLEN          16
#define BASE            10

static uint8_t PAND8_T[11] = {9,8,7,6,5,4,3,2,1};
static int PRIMES[9] = {17, 13, 11, 7, 5, 3, 2, 1};

int dcomp(const void* a, const void* b);
uint8_t isPandigital(uint64_t i);
int isSubStringDivis(uint64_t n);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;
 
        uint64_t sum = 0;

        /* Okay so this loop has been optimised the shit out of */
        for(uint64_t i = START; i < MAX; i+= 9){
                if(isSubStringDivis(i) && isPandigital(i)){ 
                        printf("%"PRIu64"\n", i);
                        sum += i;
                }
        }

        printf("%"PRIu64"\n", sum);

        return 0; 

}


uint8_t isPandigital(uint64_t i)
{
        uint8_t* digit = calloc(PANLEN, sizeof(uint8_t));

        for(uint8_t j = 0; i > 0; j++){
                digit[j] = i % BASE;
                i /= BASE;
        }

        qsort(digit, PANLEN, sizeof(char), dcomp);

        uint8_t res = (0 == strcmp(digit, PAND8_T));

        free(digit);
        return res;

}

int dcomp(const void* a, const void* b)
{
        return (*((uint8_t*) a) < *((uint8_t*) b));
}


int isSubStringDivis(uint64_t n)
{
        uint16_t tmp;

        for(uint8_t i = 0; n > 1000; i++){
                tmp = (n % 1000);
                if(tmp % PRIMES[i] != 0) return 0;
                n /= 10;
        }

        return 1;

}

