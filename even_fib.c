/* Find the sum of all the even values in the 
 * Fibonacci sequence whose values do not 
 * exceed four million. 
 *
 * Project Euler: 2 
 * Answer: 4613736 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 4000000
#define MAX_LEN 400 /* MAX_LEN will be << MAX */

/* Prototypes */
int main();

int main()
{
        int fiblist[MAX_LEN];
        fiblist[0] = 1; fiblist[1] = 2;

        int first; int second; int ith;

        /* Create array of Fibonacci values < MAX */
        for(unsigned int i = 2; i < MAX; i++){
                first = i - 2;
                second = i - 1;
                ith = fiblist[first] + fiblist[second];

                if (ith > MAX){
                        break;
                }

                fiblist[i] = ith;

        }

        unsigned int sum = 0;

        /* Iterate over all Fibonacci nums in range */
        for(int i = 0; ; i++){

                sum += (fiblist[i] % 2 == 0) ? fiblist[i]: 0;

                /* Break if next i is end of list */
                if (fiblist[i+1] == '\0'){
                        break;
                }
        }

        printf("%d\n", sum);

        return 0;

}

