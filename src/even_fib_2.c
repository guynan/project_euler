/* Find the sum of all the even values in the 
 * Fibonacci sequence whose values do not 
 * exceed four million. 
 *
 * Project Euler: 2 
 * Answer: 4613732 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX 4000000

/* Prototypes */
int main();

int main()
{
	int first = 1; int second = 1; int term; int sum = 0;

	while(1){

                term = first + second;

		if(term > MAX){
			break;
		}

		sum += (term % 2 == 0) ? term : 0;

		first = second;
		second = term;
	}

        printf("%d\n", sum);

        return 0;

}

