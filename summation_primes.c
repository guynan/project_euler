/* Finding the summation of primes < 2mil
 * This takes fucking ages
 *
 * Project Euler: 7 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 2000000

/* Prototypes */
int isprime(unsigned int s);
int main();

int main()
{
        long long unsigned int primesum = 0;

        for(unsigned int i = 0; i < MAX; i++){
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

        for(int i = 2; i < s+1; i++){
                if(i == s){
                        isprime = 1; /* True */
                        break; 
                }

                if (s % i == 0){
                        break;
                }
        }

        return isprime;
}
                
