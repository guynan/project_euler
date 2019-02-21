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
int is_prime(uint32_t s);


int main(int argc, char** argv)
{
        /* Count is 1 so we capture 2 */
        uint32_t c = 1;

        for(uint32_t i = 3; i < MAX; i += 2){
                c += circular_prime(i);
        }

        printf("%"PRIu32"\n", c);

        return 0;

}


/* Primality by trial division */
int is_prime(uint32_t s)
{
        uint32_t res = !(s <= 2 || (s & 0x1) != 1);

        for(uint32_t i = 3; res && i * i <= s; i += ((res = !(s % i == 0)), 2))
                ;

        return (res || s == 2);
}


int circular_prime(uint32_t i)
{
        if(!possibly_circular(i) || !is_prime(i))
                return 0;

        uint32_t rotated = circulate(i);

        for( ; i != rotated; rotated = circulate(rotated)){

                if(!is_prime(rotated))
                        break;
        }

        return (i == rotated);

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


/* A number may not be circular if it contains any even digits */
int possibly_circular(uint32_t i)
{
        for( ; (i % BASE) % 2; i /= BASE)
                ;

        return !i;

}

