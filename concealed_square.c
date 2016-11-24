/* Find the unique positive integer 
 * whose square has the form
 * 1_2_3_4_5_6_7_8_9_0,
 * where each "_" is a single digit.

 * Project Euler: 206 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define MIN     1020304050607080900 
int comparison[MAX_LEN]; 


int main();
int satisfied(long long i);
int atoi(const char str);

int main()
{

/*        sprintf(target_string,"%d",source_int) */


        /* Generate the int comparison array; '\0'
         * used as a placeholder in array */
        for(int i = 2; i < MAX_LEN; i++){
                comparison[i] = (i % 2 == 0) ? i/2 : '\0';
        }

        long long a;
        long long test;

        for(long long i = MIN;; i++){
                test = i*i;

                if(test < MIN){
                        continue;
                }
                if(satisfied(test)){
                        a = i;
                        break;
                }
        }
        
        printf("%lli\n", a);
        

}

int satisfied(long long i)
{
        char intstr[MAX_LEN];
        printf("%lli\n", i);

        sprintf(intstr, "%lli", i);

        for(int a = 0; a < MAX_LEN; a += 2){
                if(atoi(intstr[a]) != comparison[a]){
                        return 0;
                }
        }

        return 1;

}

