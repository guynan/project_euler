/* Find the first triangle number with over
 * 500 divisors. Fuck this is big.
 * Answer: 76576500
 *
 * Project Euler: 12 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 500
#define MAXLEN 50000

/* Prototypes */
int numdivis(long f);
int main();

int main()
{

        register long int last = 3;

        /* Beware infinite loop */
        for(long int i = 3;; i++){

                last = last + i;
                if (numdivis(last) > MAX){
                        break;
                }
        }

        printf("%li\n", last);
}
        
int numdivis(long f)
{
        int count = 1;
        register int i;

        for(i = 1; i*i < f; i++){
                if (f % i == 0){
                        count++;
                }
        }

        return 2*count;

}
