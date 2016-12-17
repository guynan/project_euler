/* Smallest positive number that is evenly 
 * divisible by all the numbers from 1 -> 20
 *
 * Answer: 232792560
 *
 * Project Euler: 5 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 4000000000 /* Fucking big */

/* Prototypes */
int main();

int main()
{
        int value = -1;

        for(long int a = 1; a < MAX; a++){

                for(int i = 1; i < 21; i++){

                        if (a % i != 0){
                                break;
                        } 

                        value = (i == 20) ? a : value;
                }
                
                /* Checks if we found it */
                if(value != -1){
                        break;
                }
        }

        printf("%d\n", value);
                                
        return 0;
}

