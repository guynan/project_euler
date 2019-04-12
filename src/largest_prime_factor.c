/* Find pf prime factor of the
 * number 600851475143
 *
 * Answer: 6857
 * Project Euler: 3*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX     600851475143

int main(int argc, char** argv);
int is_prime(int32_t s);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t pf = 0;

        for(int32_t i = 1; ((int64_t) i * i) <= MAX;
                i += ((pf = (!(MAX % i) && is_prime(i)) ? i : pf), 2))
                ;

        printf("%"PRId32"\n", pf);
}


/* Detects whether int is prime */
int is_prime(int32_t s)
{
        int32_t res = !(s < 2 || !(s % 2));

        for(int32_t i = 3; (i * i) <= s && res; i += (res = (s % i), 2))
                ;

        return (res || s == 2);
}

