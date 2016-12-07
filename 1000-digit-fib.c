/* What is the first digit in the Fibonacci
 * sequence that will have over 1000 digits?
 *
 * Project Euler: 25
 * Answer:  */

/* Includes */
#include <stdio.h>
#include <gmp.h>

/* Definitions */
#define MAX 10

/* Prototypes */
int main();

int main()
{
        int index;

        int first = 1; int second = 1; int term;

        /* Create array of Fibonacci values < MAX */
        for(int i = 2; i < MAX; i++){

                term = first + second;
                printf("%d\n", term);

                first = second;
                second = term;
/*
                if (len(term)> MAX){
                        break;
                }
*/

        }

//        printf("%d\n", index);

        return 0;

}

