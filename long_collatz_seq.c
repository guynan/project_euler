/* Finding the longest Collatz sequence 
 * under 1 million. 
 *
 * Answer: 837799
 *
 * Project Euler: 14 */

/* Includes */
#include <stdio.h>

/* Defintions */
#define MAX     1000000

/* Prototypes */
long get_n(long n);
int main();

int main()
{
        unsigned long int count = 0;
        unsigned long int longest = 0;
        unsigned int longcount = 0;

        for(long i = 2; i < MAX; i++){
                count = 0;

                for(register long n = i; n != 1; count++){
                        n = get_n(n);
                }

                if (count > longcount){
                        longcount = count;
                        longest = i;
                }
        }

        printf("%li\n", longest);

        return 0;
}        
                                

/* Returns value of n depending
 * on whether it is even or not */
long get_n(long n)
{
        if (n % 2 == 0){
                n = n / 2;  
        } else {
                n = (3 * n) + 1;
        }

        return n;
}
