/* The number, 197, is called a circular prime 
 * because all rotations of the digits: 
 * 197, 971, and 719, are themselves prime.

 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

 * How many circular primes are there below one million?

 * Project Euler: 35 */

/* Includes */
#include <stdio.h>
#include <math.h>

/* Definitions */
#define MAX     1000000
int primes[80000]; // I counted them
int res[500];

/* Prototypes */
int main();
int isPrime(unsigned int s);
void initPrimes();

int main()
{
        initPrimes();

        for(int i = 0; i < MAX; i++){
                circulate(i);
        }

        int c; 

        for(c = 0; res[c] != '\0'; c++);

        printf("%d\n", c);

        return 0;
        
}        



/* This is the bottleneck. Takes ages */
int isPrime(unsigned int s)
{
        if (s == 0 || s == 1){
                return 0;
        }

        if (s == 2){
                return 1;
        }

        int top = (int) round(sqrt(s) +1 );

        for(int i = 2; i < top+1; i++){
                if(i == top){
                        return 1;
                }

                if (s % i == 0){
                        return 0;
                }
        }

        return 0;
}

/* Generate a list of primes up to 1mil */
void initPrimes()
{
        int count = 0;

        for(int i = 0; i < MAX; i++){
                if(isPrime(i)){
                        primes[count] = i;
                        count++;
                }
        }
}

void circulate(int i)
{
        char n[10];




