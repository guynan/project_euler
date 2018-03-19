


#include <stdio.h>
#include <stdint.h>
#include <gmp.h>


#define INIT_NUMERATOR          3
#define INIT_DENOMINATOR        2
#define N_ITERATIONS            1000


/* If we look at the sequence here, we note that the numerator increases by two
 * times the previous denominator and the denominator increases by the previous
 * numerator. 
 *
 * This is trivial to calculate; however, since that means the
 * denominator for example, approximately doubles each time. This means that
 * with 1000 iterations of this problem, we will end up with a number on the
 * order of magnitude of 2^1000. Clearly this is a problem. I solve this in C
 * by utilising the GNU Multi Precision library */


int main(int argc, char** argv);




int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t num = INIT_NUMERATOR;
        uint64_t den = INIT_DENOMINATOR;
        uint64_t tmp;

        for(uint32_t i = 1; i < 5; i++){
                printf("%d/%d\n", num, den);
                tmp = num;
                num += (2 * den);
                den += tmp;
        }

        return 0;


}


