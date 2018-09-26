/* We shall say that an n-digit number is
 * pandigital if it makes use of all the
 * digits 1 to n exactly once. For
 * example, 2143 is a 4-digit pandigital
 * and is also prime. What is the largest
 * pandigital prime that exists?

 * Project Euler: 41
 * Answer: 7652413 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>


/* The key here is noting that the greatest pandigit 1 - 9 is 987654321,
 * though by use of the divisibility rule, by taking the sum over all the
 * digits we note that all permutations of the maxima across 9******** and also
 * 8*******, we note that their digital sums are 45 and 36 respectively which
 * means that they are both at least divisible by 3. Thus these can be excluded
 * from the search as for the number to be prime it must not be divisible by
 * anything aside from one and itself. Thus our search space has been cut down
 * massively and we start searching from 7654321 and decreasing each time by
 * two (as we know that our number must too be odd) we find the number */


#define MAX             7654321
#define BASE            10
#define MAX_DIGIT_LEN   9


int main(int argc, char** argv);
int n_pandigit(uint32_t i);
int is_prime(uint32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t i;

        for(i = MAX; !(n_pandigit(i) && is_prime(i)); i-= 2)
                ;

        printf("%"PRIu32"\n", i);

        return 0;
}

int n_pandigit(uint32_t i)
{
        uint32_t set_ints = 0x0;
        uint32_t fault_bit = 0x2000;
        uint32_t bit_mask = 0x0;
        uint32_t len = 0x0;

        for( ; i; i /= BASE){
                bit_mask = 0x1;
                bit_mask <<= i % BASE;
                set_ints |= (set_ints & bit_mask) ? fault_bit : bit_mask;
                len |= 0x1;
                len <<= 0x1;
        }

        return set_ints == len;

}

int is_prime(uint32_t s)
{
        uint32_t res = !(s <= 2 || (s & 0x1) != 1);

        for(uint32_t i = 3; res && i * i <= s; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}

