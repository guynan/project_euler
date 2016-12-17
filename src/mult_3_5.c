/* Sum of multiples of 3 and 5 below 1000 
 * Project Euler: 1
 * Answer: 233168 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX     1000

/* Prototypes */
int main();
int check(int i);

int main()
{
        register int i; int sum = 0;

        for(i = 0; i< MAX; i++){
                sum += (check(i)) ? i : 0;
        }

        printf("%d\n", sum);
}

int check(int i)
{
        return (i % 3 == 0 || i % 5 == 0);
}
