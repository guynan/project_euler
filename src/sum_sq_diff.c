/* Find the difference between the 
 * sum of the squares and the square
 * of the sum for all numbers up to 100
 *
 * Answer: 25164150
 *
 * Project Euler: 6 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             100
#define SQUARE(n)       ((n) * (n))


int main(int argc, char** argv);


int main(int argc, char** argv)
{
        uint64_t sqrsum = 0;
        uint64_t total = 0;

        for(uint64_t i = 0; i <= MAX; i++){
                sqrsum += SQUARE(i);
                total += i;
        }

        printf("%"PRIu64"\n", SQUARE(total) - sqrsum);
}

