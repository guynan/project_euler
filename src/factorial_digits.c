/* Find the sum of all the numbers which 
 * are equal to the sum of the factorial
 * of their digits. 
 *
 * Answer: 40730
 * Project Euler: 34 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* Find way of not setting arbitrary num */
#define MAX     1600000 
static uint64_t facts[12];

uint64_t digit_factorial(uint64_t i);
int main(int argc, char** argv);
uint64_t factorial(uint64_t f);


int main(int argc, char** argv)
{
        uint64_t sum = 0;

        /* Cache the results of the factorial so the calculation is a lookup */
        for(uint64_t i = 0; i < 10; i++){
                facts[i] = factorial(i);
        }

        for(uint64_t i = 5; i < MAX; i++ ){ 
                sum += (i == digit_factorial(i)) ? i : 0;
        }

        printf("%"PRIu64"\n", sum);

}

uint64_t factorial(uint64_t f)
{
        uint64_t factorial = 1;
        for(uint64_t i = 1; i != f+1; factorial *= i++)
                ;

        return factorial;
}

/* Calculates the sum of the factorials of all the digits. I cheat by pulling
 * the precalculated value from an array with all the answers. Sue me */
uint64_t digit_factorial(uint64_t i)
{
        uint64_t sum = 0; 

        for( ; i; i /= 10){
                sum += facts[i % 10];
        }

        return sum;
}

