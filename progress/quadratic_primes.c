/* Quadratic Primes
 *
 *
 * Project Euler: 27
 *
 * Answer: -59231 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

/* Definitions */
#define MAX     1000

int main();
int mod(int i);
int consecPrimes(int a, int b);
int isPrime(unsigned int s);


int main()
{
        uint32_t *longest = malloc(3 * sizeof(uint32_t));

        int16_t a, b, chain;
        longest[0] = 0;

        for(a = -999; mod(a) < MAX; a++){
                for(b = -999; mod(b) < MAX; b++){
                        chain = consecPrimes(a, b);
                        if(chain > *longest){
                                longest[0] = chain;
                                longest[1] = a;
                                longest[2] = b;
                        }
                }
        }

        printf("%d\n", longest[1] * longest[2]);


}

/* Return modulus of int */
int mod(int i)
{
        return (i < 0) ? -i : i;
}

/* Detects whether int is prime */
int isPrime(unsigned int s)
{
        if (s == 0 || s == 1) return 0;

        if (s == 2) return 1;

        int top = (int) round(sqrt(s) +1);

        for(int i = 2; i < top+1; i++){
                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;
}


int consecPrimes(int a, int b)
{
        uint32_t count = 0; uint32_t value;

        for(int n = 0; ; n++){
                value = pow(n, 2) + (a * n) + b;

                if(isPrime(value)){
                        count++;
                } else {
                        return count;
                }

        }

        return count;

}
