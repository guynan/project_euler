
/* Project Euler: 63 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


uint64_t intpow(uint64_t base, uint64_t exp);
int main(int argc, char** argv);
uint64_t intlen(uint64_t i);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* Initially, we need to find our maximum. The question we ask is for
         * what power will all numbers to the power of that number will be
         * longer than. We know that in base 10, 10 to the power of any
         * exponent will be of length that is precisely one more than the
         * aforementioned exponent. We can use this as our upper limit.

         * However, the exponent if not similarly bounded can grow arbitrarily
         * large. What we know is that as soon as the number to the power of
         * the exponent is larger than the length, we have searched enough.
         */

        uint64_t count = 0;

        for(uint64_t base = 0; base < 10; base++){
                for(uint64_t exp = 0;  ; exp++){

                        uint64_t len = intlen(intpow(base, exp));

                        if(exp > len){
                                break;
                        }

                        if(len == exp){
                                count++;
                        }


                }
        }

        printf("%"PRIu64"\n", count);

}

uint64_t intlen(uint64_t i)
{
        uint64_t len;

        for(len = 1; ; i /= 10){
                if(i < 10)
                        break;
                len++;
        }

        return len;
}

uint64_t intpow(uint64_t base, uint64_t exp)
{
        if(exp <= 1){
                return (exp == 1) ? exp : 1;
        }

        uint64_t res;

        for(res = 1; exp; exp--){
                res *= base;
        }

        return res;

}

