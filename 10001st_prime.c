/* Finding the 10001st prime number 
 *
 * Answer: 104743
 * Project Euler: 7 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 10001

/* Prototypes */
int isprime(int s);
int main();

int main()
{
        int primec = 0; int last;

        for(int i = 0; primec != MAX; i++){
                if (isprime(i)){
                        primec++;
                }

                last = i;
        }

        printf("%d\n", last);

}
       
       
/* Detects whether int is prime */
int isprime(int s)
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
                
