/* Find the unique positive integer 
 * whose square has the form
 * 1_2_3_4_5_6_7_8_9_0,
 * where each "_" is a single digit.
 * Project Euler: 206 
 * Answer: 1389019170 */

/* While this is done, it takes about a minute
 * fourty. Develop more efficient algorithm */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX_LEN 20
#define	START	0
#define MIN     1020304050607080900 
int comparison[MAX_LEN]; 


/* Prototypes */
int main();
int satisfied(long long i);

int main()
{

        /* Generate the int comparison array; '\0'
         * used as a placeholder in array */
        for(int i = 2; i < MAX_LEN; i++){
                comparison[i-2] = (i % 2 == 0) ? i/2 : '\0';
        }

        long long test; long long i;

        for(i = START;; i++){
                test = i*i;

                if(test < MIN){
                        continue;
                }
                if(satisfied(test)){
                        break;
                }
        }
        
        printf("%lli\n", i);

	return 0;

}

int satisfied(long long i)
{
        char intstr[MAX_LEN]; int x;

        sprintf(intstr, "%lli", i);

        for(int a = 0; a < MAX_LEN; a += 2){

		/* Manual str to int conversion */
		x = (intstr[a]) - 48;

                if(x != comparison[a]){
                        return 0;
                }
        }

        return 1;

}

