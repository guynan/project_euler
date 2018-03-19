
/* Digit Cancelling Fractions 
 * Project Euler: 33 
 * Answer: 100*/


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


uint64_t naively_cancel(uint64_t num, uint64_t den);
uint64_t gcd(uint64_t a, uint64_t b);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t nprod = 1;
        uint64_t dprod = 1;

        for(uint64_t num = 10; num < 100; num++){

                for(uint64_t den = 10; den < 100; den++){

                        /* Number must be under 1 */
                        if(num >= den)
                                continue;

                        if(naively_cancel(num, den)){
                                nprod *= num;
                                dprod *= den;
                        }
                }

        }

        uint64_t res = dprod / gcd(nprod, dprod);

        printf("%"PRIu64"\n", res);

        return 0;

}

/* Euler's Method to find the greatest common divisor */
uint64_t gcd(uint64_t a, uint64_t b)
{
        uint64_t tmp;        

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}

uint64_t naively_cancel(uint64_t num, uint64_t den)
{
        /* Our cden and cnum variables represent the
         * 'cancelled' numerator and denominator */

        uint64_t cnum, cden;

        uint64_t naively_cancel = 0;

        if(num % 10 == (den / 10) % 10){
                cnum = (num / 10) % 10;
                cden = den % 10;

                if(!cden || !cnum)
                        goto out;

                /* Floating point operations make me cringe.
                 * 
                 * However, if this test is passed, it means
                 * that they are equivalent fractions.
                 * 
                 * -- Probably */

                if((float) num/den == (float) cnum/cden){
                        naively_cancel = 1;
                }

        }

out:

        return naively_cancel;

}

