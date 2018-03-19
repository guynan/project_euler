/* Sum of multiples of 3 and 5 below 1000 
 * Project Euler: 1
 * Answer: 233168 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             1000
#define MULT_3_5(i)     ((i) % 3 == 0 || (i) % 5 == 0)


int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t sum = 0;

        for(uint64_t i = 0; i < MAX; i++){
                sum += (MULT_3_5(i)) ? i : 0;
        }

        printf("%"PRIu64"\n", sum);
}

