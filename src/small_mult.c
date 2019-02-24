/* Smallest positive number that is evenly
 * divisible by all the numbers from 1 -> 20
 *
 * Answer: 232792560
 *
 * Project Euler: 5 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define DIVIS_CONST     20

int evenly_divisible(uint32_t a, uint32_t max_divis);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        uint32_t a;

        for(a = 2; !(evenly_divisible(a, DIVIS_CONST)); a+= 2)
                ;

        printf("%"PRIu32"\n", a);

        return 0;
}


int evenly_divisible(uint32_t a, uint32_t max_divis)
{
        for(int i = max_divis; i > 2; i--){

                if (a % i != 0){
                        return 0;
                }
        }

        return 1;
}

