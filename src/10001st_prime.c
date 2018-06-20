/* Finding the 10001st prime number
 *
 * Answer: 104743
 * Project Euler: 7 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


#define N_PRIME         10001


int main(int argc, char** argv);
int is_prime(int32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t i = 0;

        for(int32_t primec = 0; primec != N_PRIME; primec += is_prime(++i))
                ;

        printf("%"PRId32"\n", i);

        return 0;

}

int is_prime(int32_t s)
{
        if (s <= 2 || s % 2 == 0)
                return (s == 2);

        int32_t top = (int32_t) round((float) sqrt(s));

        for(int32_t i = 3; i <= top; i+=2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}

