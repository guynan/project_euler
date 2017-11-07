/* A composite is a number containing at least 
 * two prime factors. For example, 15 = 3 × 5; 
 * 9 = 3 × 3; 12 = 2 × 2 × 3.

 * There are ten composites below thirty containing 
 * precisely two, not necessarily distinct, prime 
 * factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

 * How many composite integers, n < 10**8, have
 * precisely two, not necessarily distinct, prime factors?

 * Project Euler: 187 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


#define MAX     100000000


/* Prototypes */
int isPrime(uint32_t s);
int hasTwoPrimeFac(int i);
uint32_t facnum(uint32_t n, uint32_t* fac);
int main(int argc, char** argv);

int main(int argc, char** argv)
{
        int counter = 0;
        uint32_t* factors = calloc(MAX, sizeof(uint32_t));

        for(int i = 0; i < MAX; i++){
                if(facnum(i, factors) == 2){
                        counter++;
//                        printf("%d\n", i);
                }
        }
        

        printf("%d\n", counter);
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


uint32_t facnum(uint32_t n, uint32_t* factors)
{
        uint32_t orig = n;
        uint32_t count = 0;
        uint32_t z = 2;

        while(z * z <= n){
                if(n % z == 0){
                        if(factors[z]) return 3;
                        count++;
                        n /= z;
                }

                else z++;

                if(count > 2){
                        factors[orig] = 1;
                        return 3;
                }

        }

        if(n > 1){
                count++;
        }

        return count;

}
