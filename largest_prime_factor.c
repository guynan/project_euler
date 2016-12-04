/* Find largest prime factor of the
 * number 600851475143 
 *
 * Answer: 6857
 * Project Euler: 3*/

/* Includes */
#include <stdio.h>
#include <math.h>

/* Definitions */
long MAX = 600851475143;

/* Prototypes */
int main();
int isprime(int x);

int main()
{
        long largest; 
        for(long i = 1; i * i < MAX; i++){
                if (MAX % i == 0 && isprime(i)){
                        largest = i;
                }
        }

        printf("%li\n", largest);
}


/* Detects whether int is prime */
int isprime(int s)
{
        /* False */
        int isprime = 0; 
        int top = (int) sqrt(s);

        for(int i = 2; i < top +1; i++){
                if(i == top){

                        /* True */
                        isprime = 1; 
                        break; 
                }

                if (s % i == 0){
                        break;
                }
        }

        return isprime;
}

