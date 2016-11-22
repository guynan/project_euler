/* Find the difference between the 
 * sum of the squares and the square
 * of the sum for all numbers up to 100
 *
 * Answer: 25164150
 *
 * Project Euler: 6 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 101

/* Prototypes */
int square(int i);

int main()
{
        register int sqrsum = 0; int total = 0;

        for(int i = 0; i < MAX; i++){
                sqrsum += square(i);
                total += i;
        }

        printf("%d\n", square(total) - sqrsum);
}

int square(int i)
{
        int s = i*i;
        return s;
}
