/* Finding the summation of primes < 2mil
 * This takes fucking ages
 *
 * Answer: 142913828922 
 *
 * Project Euler: 10 */

/* Includes */
#include <stdio.h>
#include <math.h>

/* Definitions */
#define MAX 2000000

/* Prototypes */
int isprime(unsigned int s);
int main();

int main()
{
        long long unsigned int primesum = 2;

        for(unsigned int i = 3; i < MAX; i++){
                if (isprime(i)){
                        primesum += i;
                }
        }

        printf("%llu\n", primesum);

}
       
/* This is the bottleneck. Takes ages */
int isprime(unsigned int s)
{
        int isprime = 0; /* False */
        int top = (int) round(sqrt(s))+1;

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
                
