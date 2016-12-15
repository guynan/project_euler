/* The prime 41, can be written 
 * as the sum of six consecutive primes:

 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 * This is the longest sum of consecutive 
 * primes that adds to a prime below one-hundred.

 * The longest sum of consecutive primes 
 * below one-thousand that adds to a prime,
 * contains 21 terms, and is equal to 953.

 * Which prime, below one-million, can be 
 * written as the sum of the most consecutive primes?

 * Project Euler: 50 */

#include <stdio.h>
#include <math.h>

//#define START   900000
#define START   0
#define MAX     1000
/*
#define START   0
#define MAX     100
*/
int primes[80000]; // I counted them

int main();
int isPrime(unsigned int s);
void initPrimes();
int checkPrime(int n);

int main()
{
        /* One assumption I make is that the 
         * longest consecutive sum will start
         * from the first prime number; 2. */

        initPrimes();

        int sum = 0; int largest; 
        
        for(int i = START; i < MAX; i++){
                sum += primes[i];
                if(sum > MAX){
                        printf("%d\n", largest);
                        break;
                }

                if(checkPrime(sum)){
                        largest = sum;
                }

        }                

        printf("%d\n", largest);

        /*
        int i = 0; int largest = 0;

//        Find index of largest prime in range 
        for(; primes[i] < MAX; i++);
        
        int sum = primes[i]; 

        for(int c = 0; c < MAX; c++){
                sum -= primes[c];
                if(checkPrime(sum)){
                        largest = sum;
                        break;
                }

        }

        printf("%d\n", largest);

        */
        return 0;
}

/* Once we initialise the array, it 
 * is far more efficient to traverse that 
 * when looking for primes */
int checkPrime(int n)
{
        for(int i = 0; primes[i] != '\0'; i++){
                if(n == primes[i]){
                        return 1;
                } 

                if(primes[i] > n){
                        return 0;
                }
        }

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
