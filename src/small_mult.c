/* Smallest positive number that is evenly 
 * divisible by all the numbers from 1 -> 20
 *
 * Answer: 232792560
 *
 * Project Euler: 5 */

/* Includes */
#include <stdio.h>


/* Prototypes */
int isDivisible(long a);
int main();


int main()
{
        long int a;

        for(a = 1; !(isDivisible(a)); a++);

        printf("%li\n", a);
                                
        return 0;
}

int isDivisible(long a)
{

        for(int i = 1; i <= 20; i++){

                if (a % i != 0) break;

                if (i == 20) return 1;
        }

        return 0;

}

