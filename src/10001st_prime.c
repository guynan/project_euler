/* Finding the 10001st prime number 
 *
 * Answer: 104743
 * Project Euler: 7 */

/* Includes */
#include <stdio.h>
#include <math.h>

/* Definitions */
#define MAX 10001

/* Prototypes */
int isPrime(unsigned int s);
int main();

int main()
{
        int primec = 0; int i = 0;

        for( ; primec != MAX; i++){

                if (isPrime(i)) primec++;
        }

        printf("%d\n", i);

}


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(unsigned int s)
{
        if (s < 1) return 0;

        if (s == 2) return 1;

        /* Hopefully preventing rounding errors */
        int top = (int) round(sqrt(s) +1 );

        for(int i = 2; i < top+1; i++){

                if(i == top) return 1;

                if (s % i == 0) return 0;
                        
        }

        return 0;
}

