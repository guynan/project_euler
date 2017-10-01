/* The prime 41, can be written 
 * as the sum of six consecutive primes:

 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 * This is the longest sum of consecutive 
 * primes that adds to a prime below one-hundred.

 * The longest sum of consecutive primes 
 * below one-thousand that adds to a prime,
 * contains 21 terms, and is equal to 953.

 * Which prime, below one-million, can be 
 * written as the sum of the most consecutive primes?

 * Project Euler: 50 

 * Answer: 997651 */

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define NUM_PRIMES      20000
#define MAX             1000000

int isIn(uint64_t sum, uint32_t* p) __attribute((optimize(2)));
uint32_t longestConsec(uint32_t* primes, uint32_t max);
int main(int argc, char** argv);
uint32_t* initPrimes(uint32_t max);
int isPrime(uint32_t s);


int main(int argc, char** argv)
{
        (void) argc; 
        (void) argv;

        uint32_t* primes = initPrimes(MAX);

        printf("%"PRIu32"\n", longestConsec(primes,  MAX));

        return 0;
}


/* Generate a list of primes up to 1mil */
uint32_t* initPrimes(uint32_t max)
{
        uint32_t n = NUM_PRIMES;
        uint32_t count = 0;
        uint32_t* p = malloc(n * sizeof(uint32_t));

        for(uint32_t i = 0; i < max; i++){

                if(isPrime(i)){
                        p[count] = i;
                        count++;
                }

                p = (count == n) ? realloc(p, (n *= 2) * sizeof(uint32_t)) : p;

        }

        return p;
}


int isPrime(uint32_t s)
{
        /* Theoretically shouldn't get values
         * less than zero due to type safety */
        if (s < 2) return 0;

        /* Preventing rounding errors */
        uint32_t top = (uint32_t) round(sqrt(s) + 1);

        for(uint32_t i = 2; i < top + 1; i++){

                if(i == top) return 1;

                if(s % i == 0) break;
        }

        return 0;
}

int isIn(uint64_t sum, uint32_t* p)
{
        for( ; *p ; p++){
                if(sum == *p) return 1;

                if(sum < *p) return 0;
                        
        }

        return 0;

}


uint32_t longestConsec(uint32_t* primes, uint32_t max)
{
        uint32_t largest = 0;
        uint32_t length = 0;

        /* Naive solution */
        for(int i = 0; primes[i]; i++){
                
                uint64_t sum = 0;

                for(int j = i; primes[j]; j++){
                        sum += primes[j];

                        if(sum > max) break;

                        if(isIn(sum, (primes + j))){
                                uint32_t diff = j - i;

                                if(diff > length){
                                        largest = sum;
                                        length = diff;
                                }
                        }
                }
        }

        return largest;


}
