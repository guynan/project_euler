/* Quadratic Primes
 *
 * Project Euler: 27
 *
 * Answer: -59231 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


/* Definitions */
#define MAX             1000
#define MIN             -999
#define MAX_PRIME       875000
#define SIZEOF_PRIMES   75000


/* Function Protoytpes */
int consecPrimes(int16_t a, int16_t b, int *primes);
uint8_t in(int value, int *primes);
uint8_t isPrime(uint32_t s);
uint32_t mod(int i);
int * initPrimes();
int main();


int main()
{
        int16_t a, b, chain;

        /* Saves all the attributes about longest array 
         * so if you want to find out about it you don't 
         * need an unwieldly number of extra variables */
        uint32_t *longest = malloc(3 * sizeof(uint32_t));

        /* Initialise our list of primes */
        int *primes = initPrimes();

        for(a = MIN; mod(a) < MAX; a++){
                for(b = MIN; mod(b) < MAX; b++){
                        chain = consecPrimes(a, b, primes);
                        if(chain > *longest){
                                longest[0] = chain;
                                longest[1] = a;
                                longest[2] = b;
                        }
                }
        }

        printf("%d\n", longest[1] * longest[2]);


}

/* Return modulus of int */
uint32_t mod(int i)
{
        return (i < 0) ? -i : i;
}


/* Detects whether int is prime */
uint8_t isPrime(uint32_t s)
{
        if (s < 1) return 0;

        if (s == 2) return 1;

        int top = (int) round(sqrt(s) +1);

        for(int i = 2; i < top+1; i++){
                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;
}


/* Counts how many primes can be generated using 
 * this sequence of f(a, b). Uses the prime array to 
 * pass to check if the number we are testing is prime */
int consecPrimes(int16_t a, int16_t b, int *primes)
{
        uint32_t count = 0; uint32_t value;

        for(int n = 0; ; n++){
                value = pow(n, 2) + (a * n) + b;

                if(in(value, primes)){
                        count++;
                } else {
                        return count;
                }

        }

        return count;

}


/* Initialises a list of primes and returns it */
int * initPrimes()
{
        int *primes = malloc(SIZEOF_PRIMES * sizeof(int));

        for(uint32_t c, i = 0; i < MAX_PRIME; i++){

                if(isPrime(i)){
                        primes[c++] = i;
                }
        }

        return primes;
}


uint8_t in(int value, int *primes)
{

        while(*primes){

                if(*primes == value) return 1;

                if(*primes++ > value) return 0;
        }

        return 0;

}

