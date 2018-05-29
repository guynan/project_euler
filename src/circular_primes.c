/* The number, 197, is called a circular prime
 * because all rotations of the digits:
 * 197, 971, and 719, are themselves prime.

 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

 * How many circular primes are there below one million?

 * Project Euler: 35
 * Answer: 55 */


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


/* Definitions */
#define MAX             1000000
#define BASE            10


/* Prototypes */
int main(int argc, char** argv);
uint32_t circulate(uint32_t i);
int possibly_circular(uint32_t i);
int circular_prime(uint32_t i);
int isPrime(uint32_t s);


int main(int argc, char** argv)
{
        /* Count is 1 so we capture 2 */
        uint32_t c = 1;

        for(uint32_t i = 3; i < MAX; i+= 2){

                if(circular_prime(i))
                        c++;
        }

        printf("%"PRIu32"\n", c);

        return 0;

}


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(uint32_t s)
{
        if (s < 2 || s == 2 || s % 2 == 0)
                return (s == 2);

        uint32_t top = (uint32_t) round((float) sqrt(s));

        for(uint32_t i = 3; i <= top; i+=2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}


int circular_prime(uint32_t i)
{
        if(!possibly_circular(i) || !isPrime(i))
                return 0;

        uint32_t rotated = i;

        while(1){

                rotated = circulate(rotated);
                if(!isPrime(rotated))
                        return 0;

                if(i == rotated)
                        return 1;
        }

        return 1;

}


uint32_t circulate(uint32_t i)
{
        if(i < BASE)
                return i;

        uint32_t len = floor(log10(i));
        uint32_t first = i % BASE;
        i /= BASE;
        return pow(BASE, len) * first + i;
}


int possibly_circular(uint32_t i)
{
        while(i){

                if((i % BASE) % 2 == 0)
                        return 0;

                i /= BASE;

        }

        return 1;

}

