/* This function is an iterative approach
 * to finding prime numbers. It checks the
 * modulus of each number up to the square
 * of the integer you want to test */


#include <math.h>
#include <stdint.h>

/* Detects whether int is prime */
int is_prime(int32_t s)
{
        int32_t res = !(s <= 2 || (s & 0x1) != 1);
        int32_t top = (int32_t) round(sqrt((float) s));

        for(int32_t i = 3; res && i <= top; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}

