/* This function is an iterative approach
 * to finding prime numbers. It checks the 
 * modulus of each number up to the square 
 * of the integer you want to test */


/* Includes */
#include <math.h>
#include <stdint.h>


/* Function prototype */
uint8_t isPrime(uint32_t); 


uint8_t isPrime(uint32_t s)
{
        /* Theoretically shouldn't get values
         * less than zero due to type safety */
        if (s < 2) return 0;

        /* Preventing rounding errors */
        uint32_t top = (uint32_t) round(sqrt(s) + 1);

        for(uint32_t i = 2; i < top + 1; i++){

                if(i == top) return 1;

                if(s % i == 0) break;
        }

        return 0;
}

