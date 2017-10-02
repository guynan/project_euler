/* It was proposed by Christian Goldbach that every odd composite number can be
 * written as the sum of a prime and twice a square.
 *
 * 9 = 7 + 2�1**2
 * 15 = 7 + 2�2**2
 * 21 = 3 + 2�3**2
 * 25 = 7 + 2�3**2
 * 27 = 19 + 2�2**2
 * 33 = 31 + 2�1**2
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a
 * prime and twice a square?
 *
 * Project Euler: 46 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

#define MAX             10000

/* Prototypes */
uint32_t findClosestPrime(uint32_t i, uint32_t* primes);
uint32_t* initPrimes(uint32_t max);
int main(int argc, char** argv);
int obeysGoldbach(long i);
int isPrime(uint32_t s);
int isSquare(uint32_t);

int main(int argc, char** argv)
{
        (void) argc; (void) argv;

        uint32_t* primes = initPrimes(MAX);

        /* odd composite - 2 * square = prime */
//        for(uint32_t i = 3; i < MAX; i += 2){
        
                
        printf("%"PRIu32"\n", findClosestPrime(27, primes));

        return 0;
}

int obeysGoldbach(long i)
{
        return 0;
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

int isSquare(uint32_t a)
{
        double tmp = sqrt(a);

        return ((int)(tmp * tmp) == a);

}


uint32_t findClosestPrime(uint32_t i, uint32_t* primes)
{
        uint32_t largest = 0;

        for(uint32_t j = 0; i <= primes[j]; j++){
                largest = primes[j];
        }

        return largest;

}

uint32_t* initPrimes(uint32_t max)
{

        uint32_t* primes = malloc(MAX * sizeof(uint32_t));

        for(uint32_t i, c = 0; i < max; i++){
                if(isPrime(i)) primes[c++] = i;
        }

        return primes;

}
