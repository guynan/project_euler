/* Evaluate the sum of all the amicable 
 * numbers under 10,000. 
 * Project Euler: 21
 * Answer: 31626 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX     10000

/* Protoypes */
int main();
int isAmicable(int n);


int main()
{
        int sum = 0;

        for(int n = 1; n < MAX; n++){
               sum += (isAmicable(n)) ? n : 0;
        }

        printf("%d\n", sum); 

        return 0;

}


/* Returns whether n is amicable */
int isAmicable(int n)
{
        int sum = 0; int a;
        int partner_sum = 0;

        int k = n / 2 + 1;

        /* Find sum of factors of n*/
        for(int i = 0; i < k; sum += (n % ++i == 0) ? i : 0);

        /* Find sum of factors of sum */
        for(a = 1; a < sum; a++){
                partner_sum += (sum % a == 0) ? a : 0;
        }

        return (partner_sum == n && n != a);

}

