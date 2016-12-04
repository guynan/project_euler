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
