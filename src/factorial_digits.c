/* Find the sum of all the numbers which 
 * are equal to the sum of the factorial
 * of their digits. 
 *
 * Answer: 40730
 * Project Euler: 34 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Definitions */

/* Find way of not setting arbitrary num */
#define MAX     1600000 

/* Prototypes */
int main();
long factorial(long f);
int checkDigitFact(long i);


int main()
{
        long sum = 0;

        for(long i = 5; i < MAX; i++ ){ 
                sum += (checkDigitFact(i)) ? i : 0;
        }

        printf("%li\n", sum);

}


long factorial(long f)
{
        long factorial = 1;

        for(long i = 1; i != f+1; i++){
                factorial *= i;
        }

        return factorial;
}

int checkDigitFact(long i)
{
        char *string = malloc(16 * sizeof(int));

        /* Cast num to string */
        sprintf(string, "%li", i);
        
        int sum = 0; 

        for( ; *string; sum += factorial(*string++ - '0'))
                ;
                
        return (sum == i);        
}

