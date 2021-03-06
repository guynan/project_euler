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
 * Answer: 5777
 *
 * Project Euler: 46 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>


#define MAX             10000


uint32_t findClosestPrime(uint32_t i, uint32_t* primes);
uint32_t* initPrimes(uint32_t max);
int main(int argc, char** argv);
int isPrime(uint32_t s);
int isSquare(uint32_t);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t* primes = initPrimes(MAX);

        uint32_t i = 0;

        if(!primes){
                return -1;
        }

        for(i = 3; ; i += 2){

                int found = 1;

                for(uint32_t j = 0; i >= primes[j]; j++){

                        if(isSquare(i - primes[j])){
                                found = 0;
                                break;
                        } 
                }

                if(found){
                        goto done;
                }
        }

done:
        free(primes);
        printf("%"PRIu32"\n", i);

        return 0;
}

int isPrime(uint32_t s)
{
        if (s < 2) return 0;

        uint32_t top = (uint32_t) round(sqrt(s) + 1);

        for(uint32_t i = 2; i <= top; i++){

                if(i == top) return 1;

                if(s % i == 0) break;
        }

        return 0;
}

/* This is fucking dirty */
int isSquare(uint32_t a)
{
        double tmp = sqrt((double) a / 2);
        return ((uint32_t) tmp == tmp);
}

uint32_t* initPrimes(uint32_t max)
{
        uint32_t* primes = malloc(MAX * sizeof(uint32_t));

        if(!primes){
                goto out;
        }

        uint32_t c = 0;
        for(uint32_t i = 0; i < max; i++){
                if(isPrime(i)) primes[c++] = i;
        }

out:
        return primes;

}

