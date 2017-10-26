
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

int main(int argc, char** argv);
int ccomp(const void* a, const void* b);
int dcomp(const void* a, const void* b);
int isPandigitalSO(uint64_t n);
int isStrPandigital(uint64_t i);
int isPandigital(uint64_t i);
int isSubStringDivis(uint64_t n);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;
        uint64_t sum = 0;
        uint32_t count = 0;
        for(uint64_t i = START; i < MAX; i++){
//                if(i % 9 != 0) continue;
                /*
                if(isSubStringDivis(i) && isPandigitalSO(i)){
                        sum += i;
                }
                */
                if(isPandigitalSO(i)) count++;

        }

        printf("%"PRIu32"\n", count);
        printf("%"PRIu64"\n", sum);

        return 0; 

}

int isStrPandigital(uint64_t i)
{
//        if(i % 9 != 0) return 0;

        char* digit = calloc(PANLEN, sizeof(char));
        sprintf(digit, "%"PRIu64, i);
        qsort(digit, PANLEN, sizeof(char), ccomp);

        int res = (0 == strcmp(digit, PANDIGIT));

        free(digit);
        return res;

}

int isPandigital(uint64_t i)
{
        if(i % 9 != 0) return 0;
        uint8_t* digit = calloc(PANLEN, sizeof(uint8_t));

        for(uint8_t j = 0; i > 0; j++){
                digit[j] = i % BASE;
                i /= BASE;
        }

        qsort(digit, PANLEN, sizeof(char), dcomp);
        /*
        for(uint8_t j = 0; j < 10; j++){
                printf("%d", (int)digit[j]);
        }
        printf("\n");
        */

        int res = (0 == strcmp(digit, PAND8_T));

        free(digit);
        return res;

}

int dcomp(const void* a, const void* b)
{
        return (*((uint8_t*) a) < *((uint8_t*) b));
}

int ccomp(const void* a, const void* b)
{
        return (*((char*) a) - *((char*) b));
}


/* This is a pandigital confirmation method lifted from Stack Overflow */
int isPandigitalSO(uint64_t n)
{
        uint64_t digits = 0;
        uint64_t count = 0;
        uint64_t tmp;

        for( ; n > 0; n /= 10, ++count){

                if((tmp = digits) == (digits |= 1 << (n 
                        - ((n / BASE) * BASE) - 1))) 
                        return 0;

        } 

        return digits == (1 << count) - 1;

}

int isSubStringDivis(uint64_t n)
{
        for(uint8_t i = 0; n > 1000; i++){
                uint32_t tmp = n % 1000;

                if(tmp % PRIMES[i] != 0) return 0;
                n /= 10;
        }

        return 1;

}
