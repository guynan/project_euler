/* Finding the summation of primes < 2mil
 *
 * Answer: 142913828922
 *
 * Project Euler: 10 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define MAX 2000000

int main(int argc, char** argv);
int is_prime(int32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int64_t sum = 2;

        for(int32_t i = 3; i < MAX; i += 2){

                sum += (is_prime(i)) ? i : 0;
        }

        printf("%"PRId64"\n", sum);

        return 0;

}

int is_prime(int32_t s)
{
        int32_t res = !(s <= 2 || (s & 0x1) != 1);
        int32_t top = (int32_t) round(sqrt((float) s));

        for(int32_t i = 3; res && i <= top; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}

