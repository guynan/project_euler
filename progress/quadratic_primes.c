/* Quadratic Primes */

/* Includes */
#include <stdio.h>
#include <math.h>

/* Definitions */
#define MAX     1000
#define n       2

int main();
int mod(int i);
int isprime(int s);


int main()
{
        printf("%d\n", isprime(4));
}

/* Return modulus of int */
int mod(int i)
{
        return (i < 0) ? -i : i;
}


/* This is the bottleneck. Takes ages */
int isprime(int s)
{
        int isprime = 0; /* False */
        int top = (int) round(sqrt(s))+1;

        if (s == 1){
                return 0;
        }

        if (s == 2){
                return 1;
        }

        for(int i = 2; i < top +1 ; i++){
                if(i == top){
                        isprime = 1; /* True */
                        break; 
                }

                if (s % i == 0){
                        break;
                }
        }

        return isprime;
}

