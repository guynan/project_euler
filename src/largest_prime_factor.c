/* Find largest prime factor of the
 * number 600851475143 
 *
 * Answer: 6857
 * Project Euler: 3*/

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <math.h>

/* Definitions */
uint64_t MAX = 600851475143;

/* Prototypes */
int main();
int isPrime(uint32_t s);

int main()
{
        uint64_t largest; 

        for(uint64_t i = 1; i * i < MAX; i++){
                largest = (MAX % i == 0 && isPrime(i)) ? i : largest;
        }

        printf("%li\n", largest);
}


/* Detects whether int is prime */
int isPrime(uint32_t s)
{
	if(s < 1) return 0;

        uint32_t top = (uint32_t) round(sqrt(s));

        for(uint32_t i = 2; i < top +1; i++){

                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;

}


