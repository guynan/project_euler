#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <math.h>

#define MAX     1000000

int main(int argc, char** argv);
uint64_t totient_function(uint64_t n);
uint64_t gcd(uint64_t a, uint64_t b);
int isprime(uint64_t s);

static uint64_t TOTIENT_CACHE[MAX];
static int gcount = 0;

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        double tmp;
        double ratio = 0;
        uint64_t largest, tf;


        for(uint64_t i = 2; i < MAX; i++){

                if(isprime(i))
                        continue;

                tf = totient_function(i);
                tmp = (double) i / (double)tf;

                if(tmp > ratio){
                        ratio = tmp;
                        largest = i;
                }

        }

        printf("%d\n", gcount);
        printf("%li\n", largest);

        return 0;


}


uint64_t totient_function(uint64_t n)
{

#define CACHE_BOUND     100

        uint64_t count = 0;


        /* See if the number is a candidate for our cached solution */

        for(uint64_t i = 2; i < CACHE_BOUND; i++){

                if(n < i){
                        goto non_cached;
                }
                if(n % i == 0){

                        if(!TOTIENT_CACHE[n/i] || !TOTIENT_CACHE[i]){
                                goto non_cached;
                        }
                        TOTIENT_CACHE[n] = TOTIENT_CACHE[i] *
                                TOTIENT_CACHE[n/i];
                        return TOTIENT_CACHE[n];
                }
        }

non_cached:

        for(uint64_t i = 1; i < n; i++){
                if(gcd(i, n) == 1){
                        count++;
        }
        }
        TOTIENT_CACHE[n] = count;
        gcount++;

        return count;

}

/* Euler's Method to find the greatest common divisor */
uint64_t gcd(uint64_t a, uint64_t b)
{
        uint64_t tmp;

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}

int isprime(uint64_t s)
{
        if (s < 2 || s == 2 || s % 2 == 0)
                return (s == 2);

        uint64_t top = (uint64_t) round((double) sqrt(s));

        for(uint64_t i = 3; i <= top; i+=2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}

