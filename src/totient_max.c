/* Euler's Totient function, φ(n) [sometimes called the phi function], is used
 * to determine the number of numbers less than n which are relatively prime to n.
 * For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively
 * prime to nine, φ(9)=6.

 * It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

 * Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

 * #69 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>


#define MAX     1000000


int main(int argc, char** argv);
int32_t gcd(int32_t a, int32_t b);
int32_t* init_primes(int32_t max);
int32_t euler_totient_func(int32_t n, int32_t* primes);
int isprime(int32_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t* primes = init_primes(round(sqrt((double) MAX)));

        double tmp = 0;
        double ratio = 0;
        int32_t largest = 0, tf;

        for(int32_t i = 2; i < MAX; i++){

                tf = euler_totient_func(i, primes);
                tmp = (double) i / (double)tf;

                if(tmp > ratio){
                        ratio = tmp;
                        largest = i;
                }

        }

        printf("%"PRId32"\n", largest);
        free(primes);

        return 0;

}


/* Euler's Method to find the greatest common divisor */
int32_t gcd(int32_t a, int32_t b)
{
        int32_t tmp;

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}


int isprime(int32_t s)
{
        if (s <= 2 || s % 2 == 0)
                return (s == 2);

        int32_t top = (int32_t) round((double) sqrt(s));

        for(int32_t i = 3; i <= top; i+=2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}


/* The euler Product funtion defines the totient of n to be the product of all
 * (1 - 1/p) where p is a prime that evenly divides n */
int32_t euler_totient_func(int32_t n, int32_t* primes)
{
        double prod = 1.0;
        int32_t n_0 = n;

        for(int32_t i = 0; primes[i] && primes[i] <= n; i++){

                if(n % primes[i] == 0){
                        prod *= (1 - 1 / (double) primes[i]);
                        n /= primes[i];
                }
        }

        return (int32_t) (double) n_0 * prod;

}


int32_t* init_primes(int32_t max)
{
        int32_t* primes = calloc(max, sizeof(int32_t));

        primes[0] = 2;
        int32_t c = 1;

        for(int32_t i = 3; i <= max; i += 2){

                if(isprime(i)){
                        primes[c++] = i;
                }
        }

        return primes;
}

