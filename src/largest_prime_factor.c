/* Find largest prime factor of the
 * number 600851475143
 *
 * Answer: 6857
 * Project Euler: 3*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int64_t MAX = 600851475143;

int main(int argc, char** argv);
int is_prime(int32_t s);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t largest = 0;

        int32_t limit = (int32_t) round(sqrt((double) MAX));

        for(int32_t i = 1; i <= limit; i += ((largest = (MAX % i == 0 && is_prime(i)) ? i : largest), 1))
                ;

        printf("%"PRId32"\n", largest);
}


/* Detects whether int is prime */
int is_prime(int32_t s)
{
        int32_t res = !(s <= 2 || s % 2 == 0);
        int32_t top = (int32_t) round(sqrt((float) s));

        for(int32_t i = 3; i <= top && res; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}

