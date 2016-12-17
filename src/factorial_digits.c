/* Find the sum of all the numbers which 
 * are equal to the sum of the factorial
 * of their digits. 
 *
 * Answer: 40730
 * Project Euler: 34 */

/* Includes */
#include <stdio.h>

/* Definitions */

/* Find way of not setting arbitrary num */
#define MAX     1600000 

/* Prototypes */
int main();
int ctoint(char c);
long factorial(long f);
int check_digit_fact(long i);


int main()
{
        long sum = 0;

        for(long i = 5; i < MAX; i++ ){ 
                sum += (check_digit_fact(i)) ? i : 0;
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

int check_digit_fact(long i)
{
        char string[16];

        /* Cast num to string */
        sprintf(string, "%li", i);
        
        int sum = 0; int digit;

        for(int c = 0; string[c] != '\0'; c++){
                digit = ctoint(string[c]);
                sum += factorial(digit); 
        }
        
        return (sum == i);        
}

int ctoint(char c)
{
        int x = (int) c - 48;
        return x;
}

