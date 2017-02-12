/* A googol (10^100) is a massive number: 
 * one followed by one-hundred zeros;
 * 100^100 is almost unimaginably large: 
 * one followed by two-hundred zeros.
 * Despite their size, the sum 
 * of the digits in each number is only 1.

 * Considering natural numbers of the form, 
 * a^b, where a, b < 100, what is the
 * maximum digital sum?
 *
 * Answer: 972
 * Project Euler: 56 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define MAX     100

int main();
int digitalSum(mpz_t i);

int main()
{
        /* I get a feeling of comfort
         * that the number will be easily
         * truncatable and comparable to 
         * the rest so I don't need to allocate
         * the whole kitchen sink in terms of 
         * memory. */

        int max; int sum; mpz_t digit; 

        mpz_init(digit); 

        for(long a = 1 ; a <= MAX; a++){
                for(long b = 1; b <= MAX; b++){

                        mpz_ui_pow_ui(digit, a, b);
                        sum = digitalSum(digit);

                        /* Assign if bigger */
                        max = (sum > max) ? sum : max;
                }

        }

        printf("%d\n", max);



        return 0;

}


/* Very simple cast to string; sum iteration */
int digitalSum(mpz_t i)
{
        int sum = 0;
        char *strptr = malloc(221 * sizeof(char));

        mpz_get_str(strptr, 10, i);

        for( ; *strptr; sum += (*strptr++ - '0'))
                                ;
        return sum;
}

