/* Find the first four consecutive integers
 * to have four distinct prime factors each.
 * What is the first of these numbers? 
 * Project Euler: 47 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX     10000

/* Prototypes */
int main();

int main()
{
        int consec = 1;

        for(int i = 0; i < MAX; consec = 1, i++){
                if(has_distinct(i)){
                        consec++;
                }

                if(consec == 4){
                        break;

