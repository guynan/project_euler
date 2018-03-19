/* By expanding this for the first four iterations, we get:
 *
 * 1 + 1/2 = 3/2 = 1.5
 * 1 + 1/(2 + 1/2) = 7/5 = 1.4
 * 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
 * 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
 *
 * The next three expansions are 99/70, 239/169, and 577/408, but the eighth
 * expansion, 1393/985, is the first example where the number of digits in the
 * numerator exceeds the number of digits in the denominator.
 *
 * In the first one-thousand expansions, how many fractions contain a numerator
 * with more digits than denominator?
 *
 * Project Euler: 57
 *
 * Answer: 153 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
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
size_t mpz_len(mpz_t i);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t count = 0;

        mpz_t num, den, tmp;

        mpz_inits(num, den, tmp, NULL);
        
        mpz_set_ui(num, INIT_NUMERATOR);
        mpz_set_ui(den, INIT_DENOMINATOR);

        for(uint64_t i = 1; i < N_ITERATIONS; i++){

                /* Store value of numerator */
                mpz_set(tmp, num);

                mpz_addmul_ui(num, den, 2);
                mpz_add(den, den, tmp);

                count += (mpz_len(num) > mpz_len(den));

        }

        mpz_clears(num, den, tmp, NULL);

        printf("%"PRIu64"\n", count);

        return 0;

}


/* Takes a multi precision integer, converts it to a string, takes the length
 * of the string --freeing those resources too-- and returning the length */
size_t mpz_len(mpz_t i)
{
        size_t len = 0;

        char* str = mpz_get_str(NULL, 10, i);

        if(!str)
                goto out;
        
        len = strlen(str);

        free(str);

out:

        return len;

}

