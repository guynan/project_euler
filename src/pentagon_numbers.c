/* Find the pair of pentagonal numbers
 * for which their sum and difference are 
 * pentagonal. What is the value of their
 * difference?

 * Answer: 5482660
 * Project Euler: 44 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


/* Should be less than 10000 */
#define MAX     3000

/* Prototypes */
int main(int argc, char** argv);
uint32_t* initPentagons(uint32_t limit);
int isPentagonal(uint32_t n, uint32_t* pent);


int main(int argc, char** argv)
{

        uint32_t k, j, diff;

        uint32_t* pent = initPentagons(MAX);

        for(uint32_t a = 5; a < MAX; a++){
                for(uint32_t b = 5; b < MAX; b++){
                                
                        if(a == b) break;

                        k = pent[a];
                        j = pent[b];
                        
                        diff = k - j;

                        if(isPentagonal(k + j, (pent + a)) && isPentagonal(diff, pent)){
                                goto done;
                        }
                }

        }

        done:
                printf("%"PRIu32"\n", diff);

        return 0;

}


/* Initialise array of pentagonal numbers */
uint32_t* initPentagons(uint32_t limit)
{
        uint32_t* pent = malloc(limit * sizeof(uint32_t));
        
        if(!pent){
                exit(1);
        }

        for(uint32_t n = 0; n < limit; n++){
                pent[n] = (n * (3*n - 1))/2;
        }

        return pent;

}

/* Asks if is pentagonal by
 * iterating over the pentagon array */
int isPentagonal(uint32_t n, uint32_t* pent)
{
        
        for(uint32_t i = 0; i < MAX; i++){

                if(n == pent[i]) return 1;

                if(n < pent[i]) return 0;

        }

        return 0;

}

