/* Evaluate the sum of all the amicable 
 * numbers under 10,000. 
 * Project Euler: 21
 * Answer: 31626 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX     10000

int main(int argc, char** argv);
int isAmicable(uint64_t n);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t sum = 0;

        for(uint64_t n = 1; n < MAX; n++){
               sum += (isAmicable(n)) ? n : 0;
        }

        printf("%"PRIu64"\n", sum); 

        return 0;

}


/* Returns whether n is amicable */
int isAmicable(uint64_t n)
{
        uint64_t sum = 0;
        uint64_t i;

        uint64_t k = n / 2 + 1; 

        /* Find sum of factors of n*/
        for(i = 0; i < k; sum += (n % ++i == 0) ? i : 0)
                ;

        k = sum;
        sum = 0;

        /* Find sum of factors of sum */
        for(i = 1; i < k; i++){
                sum += (k % i == 0) ? i : 0;
        } 

        return (sum == n && n != i);

}

