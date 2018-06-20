
/* Consider the fraction, n/d, where n and d are positive integers. If n<d and
 * HCF(n,d)=1, it is called a reduced proper fraction.  If we list the set of
 * reduced proper fractions for d ≤ 8 in ascending order of size, we get: 1/8,
 * 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7,
 * 3/4, 4/5, 5/6, 6/7, 7/8
 * It can be seen that there are 3 fractions between 1/3 and 1/2.  How many
 * fractions lie between 1/3 and 1/2 in the sorted set of reduced proper
 * fractions for d ≤ 12,000?
 * #73  */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX                     12000
static const double min_frac =  1.0 / 3.0;
static const double max_frac =  1.0 / 2.0;


int32_t gcd(int32_t a, int32_t b);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t frac_count = 0;

        for(int32_t n = 1; n <= MAX; n++){

                for(int32_t d = n * 2; d <= MAX; d++){

                        double tmp = (double) n / (double) d;

                        if(tmp >= max_frac){
                               continue;
                        }

                        frac_count += (tmp > min_frac && gcd(n, d) == 1);

                        if(tmp <= min_frac){
                                break;
                        }

                }

        }

        printf("%"PRId32"\n", frac_count);


        return 0;

}

/* Euler's Method to find the greatest common divisor */
int32_t gcd(int32_t a, int32_t b)
{
        int32_t tmp;

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}

