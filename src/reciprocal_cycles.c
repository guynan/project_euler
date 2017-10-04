/* Find the value of d < 1000 for 
 * which 1/d contains the longest recurring
 * cycle in its decimal fraction part.

 * Project Euler: 26 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             1000
#define DECIMAL_BASE    10

uint32_t longReciprocalCycle(uint32_t max);
uint32_t getReciprocalCount(uint32_t i);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", longReciprocalCycle(MAX));

        return 0;
}


uint32_t getReciprocalCount(uint32_t i)
{
        /* Remove searches where remainder is trivial */
        if(!(i % 5)) return 1;

        uint32_t initRem = 1 % i;
        uint32_t count = 1;
        uint32_t rem = (DECIMAL_BASE * initRem) % i;

        for( ; rem != 0 && rem != initRem; count++){
                rem = (DECIMAL_BASE * rem) % i;
        }

        return count;
}


uint32_t longReciprocalCycle(uint32_t max)
{
        uint32_t longest = 0;
        uint32_t num = 0;

        /* Only test odd numbers */
        for(uint32_t i = 1; i < max; i += 2){
                uint32_t k = getReciprocalCount(i);
                if(k > longest){
                        num = i;
                        longest = k;
                }
                
        }

        return num;

}
