/* Finding the 10001st prime number
 *
 * Answer: 104743
 * Project Euler: 7 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define N_PRIME         10001


int main(int argc, char** argv);
int is_prime(int32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t i = 1;

        for(int32_t pc = N_PRIME - 1; pc; pc -= ((i += 2), (!!is_prime(i))))
                ;

        printf("%"PRId32"\n", i);

        return 0;

}

int is_prime(int32_t s)
{
        int32_t res = !(s <= 2 || (s & 0x1) != 1);

        for(int32_t i = 3; res && i * i <= s; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}

