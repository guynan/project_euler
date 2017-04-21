/* Find the sum of all the even values in the 
 * Fibonacci sequence whose values do not 
 * exceed four million. 
 *
 * Project Euler: 2 
 * Answer: 4613732 */


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* Definitions */
#define MAX 4000000
#define MAX_LEN 400 /* MAX_LEN will be << MAX */


/* Prototypes */
int main();


int main()
{
        int *fiblist = malloc(MAX_LEN * sizeof(int));
        fiblist[0] = 1; fiblist[1] = 1;

        int *first = &fiblist[0];
        int *second = &fiblist[1];
        int ith;

        /* Create array of Fibonacci values < MAX */
        for(int i = 2; i < MAX; i++){

                ith = *first++ + *second++;

                if (ith > MAX) break;

                fiblist[i] = ith;
        }

        uint32_t sum = 0;
        
        /* Iterate over all Fibonacci nums in range */
        for(int *arr = &fiblist[0]; *arr; arr++){

                sum += !(*arr % 2) ? *arr : 0;

        }

        printf("%d\n", sum);

        return 0;

}

