/* The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 × 7
 * 15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors
 * are:
 *
 * 644 = 2² × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors
 * each. What is the first of these numbers?
 *
 * Project Euler: 47
 *
 * Answer: */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


#define N_FACTORS               4
#define MAX                     100000
#define FACTOR_ARR_N            48


uint32_t facnum(uint32_t n, uint32_t* factors);
uint32_t consecfactors(uint32_t n);
uint32_t countFactors(uint32_t* f);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", consecfactors(N_FACTORS));

        return 0;

}


uint32_t facnum(uint32_t n, uint32_t* factors)
{
        uint32_t z = 2;

        memset(factors, 0, (FACTOR_ARR_N * sizeof(uint32_t)));

        uint32_t i = 0;

        while(z * z <= n){

                if(n % z == 0){
                        factors[i++] = z;  
                        n /= z;
                }

                else z++;

        }

        if(n > 1){
                factors[i] = n;  
        }

        return countFactors(factors);

}


uint32_t countFactors(uint32_t* f)
{

        uint32_t last = 0;
        uint32_t count = 0;

        while(*f){
                if(*f != last) count++;
                last = *f++;
        }

        return count;

}


uint32_t consecfactors(uint32_t n)
{
        uint32_t* f = malloc(FACTOR_ARR_N * sizeof(uint32_t));

        uint32_t consec = 0;

        for(uint32_t i = 100; consec != n; i++){

                consec = 0;

                for(uint32_t j = 0; j < n; j++){

                        uint32_t factors = facnum(i + j, f);

                        if(factors != n) break;

                        consec++;        
                }

                if(consec == n){
                        free(f);
                        return i;
                }

        }

        return 0;

}

