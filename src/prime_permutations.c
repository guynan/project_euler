/*
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
 * increases by 3330, is unusual in two ways: (i) each of the three terms are
 * prime, and, (ii) each of the 4-digit numbers are permutations of one
 * another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
 * primes, exhibiting this property, but there is one other 4-digit increasing
 * sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this
 * sequence?
 *
 * Project Euler: 49 
 *
 * Answer: 296962999629 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define INT_STR_BUF     8
#define TEST            1487

static int PRIME_BUFFER =       2048;

void findArithmeticPrimes(int* primes, int numPrimes);
int charcomp(const void* a, const void* b);
int isPermutation(int a, int b);
int main(int argc, char** argv);
int isPrime(uint32_t s);
int initPrimes(int** p);


/* Pseudocode - for i in primes, if is permutation of current
 * prime - find the difference and divide this by two and add
 * to the lower of the numbers. if the resulting number
 * is a prime, then you have found your trio. */
int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int* primes;

        primes = malloc(PRIME_BUFFER * sizeof(int));

        int numPrimes = initPrimes(&primes);

        findArithmeticPrimes(primes, numPrimes);

        return 0;

}



/* This function is an iterative approach
 * to finding prime numbers. It checks the 
 * modulus of each number up to the square 
 * of the integer you want to test */
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

int isPermutation(int a, int b) 
{
        char* astr = malloc(INT_STR_BUF * sizeof(char));
        char* bstr = malloc(INT_STR_BUF * sizeof(char));

        sprintf(astr, "%d", a);        
        sprintf(bstr, "%d", b);

        /* Only sort 4 elements; read: ignoring '\0',
         * as that is the max size */
        qsort(astr, 4, sizeof(char), charcomp);
        qsort(bstr, 4, sizeof(char), charcomp);

        return (0 == strcmp(astr, bstr));
}

int charcomp(const void* a, const void* b)
{
        return (*((char*) b) - *((char*) a));
}


/* Initialises the primes and returns the number of primes */
int initPrimes(int** p)
{
        /* Where i = number of primes */
        int i = 0;

        int* primes = *p;
        for(int n = 1000; n < 9999; n++){
                if(isPrime(n)){

                        if(i == PRIME_BUFFER){
                                puts("oo");
                                if(!realloc(primes, PRIME_BUFFER *=2)){
                                        printf("OOM\n");
                                        exit(2);
                                }

                        }

                        primes[i++] = n;
                }

        }

        return i;
}


/* Helpful variable names lie here */
void findArithmeticPrimes(int* primes, int numPrimes)
{
        for(int* tmp = primes; *tmp; tmp++){
                for(int k = numPrimes; k > 0; k--){

                        if(*tmp == TEST) continue;

                        int f = primes[k];

                        if(*tmp == f) continue;

                        if(isPermutation(*tmp, f)){
                                int diff = primes[k]- *tmp;
                                int x = *tmp + (diff / 2);
                                if(isPrime(x) && isPermutation(x, f)){
                                        printf("%d%d%d\n", *tmp, x, f);
                                        return;
                                }
                        }
                }
        }

        return;

}
