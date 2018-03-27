/* x^x for 1 <= x <= 1000
 * Find the last ten digits
 * of the sum of this series
 *
 * Answer: 9110846700
 * Project Euler: 48 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>


#define MAX 1000


int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        mpz_t sum, power;
        mpz_init(sum);
        mpz_init(power);

        unsigned long int i;

        for(i = 1; i <= MAX; i++){
                mpz_ui_pow_ui(power, i, i);
                mpz_add(sum, sum, power);
        }

        char* str = mpz_get_str(NULL, 10, sum);

        printf("%s\n", str + (strlen(str) - 10));

        mpz_clears(sum, power, NULL);
        free(str);

        return 0;
}

