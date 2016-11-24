/* Find the sum of all the numbers which 
 * are equal to the sum of the factorial
 * of their digits. 
 * Project Euler: 34 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX     150

/* Prototypes */
int main();
long factorial(long f);

int main()
{
        for(int i = 0; ){ /* Finished here */
        printf("%li", factorial(4));
}


long factorial(long f)
{
        long factorial = 1;

        for(long i = 1; i != f+1; i++){
                factorial *= i;
        }

        return factorial;
}
