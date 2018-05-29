
/* The number 3797 has an interesting property.
 * Being prime itself, it is possible
 * to continuously remove digits from left to right,
 * and remain prime at each stage: 3797, 797, 97, and 7.
 * Similarly we can work from right to left: 3797, 379, 37, and 3.

 * Find the sum of the only eleven primes that are
 * both truncatable from left to right and right to left.

 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

 * Answer: 748317
 * Project Euler: 37 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


#define BASE            10
#define TRUNC_PRIME_N   11


int32_t intrev(int32_t i);
int left_trunc(int32_t prime);
int truncatable_prime(int32_t i);
int right_trunc(int prime);
int isPrime(int32_t s);
int possibly_trunc(int32_t i);
int main(int argc, char** argv);


static int32_t c = 0;
static int32_t sum = 0;


int main(int argc, char** argv)
{

        (void) argc;
        (void) argv;

        for(int32_t i = 1; ; i += 2){

                if(truncatable_prime(i)){

                        sum += i;

                        if(++c == TRUNC_PRIME_N){
                                break;
                        }
                }
        }

        printf("%"PRId32"\n", sum);

        return 0;

}


int truncatable_prime(int32_t i)
{
        return !(i < 10 || !possibly_trunc(i)) &&
                (right_trunc(i) && left_trunc(i));
}


int left_trunc(int32_t left)
{
        for( ; left; left = intrev(intrev(left) / BASE)){

                if(!isPrime(left))
                        return 0;
        }

        return 1;

}


int right_trunc(int32_t right)
{
        for( ; right; right /= BASE){

                if(!isPrime(right))
                        return 0;
        }

        return 1;
}


int isPrime(int32_t s)
{
        if (s < 2 || s == 2 || s % 2 == 0)
                return (s == 2);

        int32_t top = (int32_t) round((double) sqrt(s));

        for(int32_t i = 3; i <= top; i += 2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}


int32_t intrev(int32_t i)
{
        int32_t rev = 0;

        while(i){
                rev *= BASE;
                rev += (i % BASE);
                i /= BASE;
        }

        return rev;
}


/* Rule out numbers with any even integers *except two*, rule out any numbers
 * with more than one two, and rule out any numbers that don't end in 3 || 7 */
int possibly_trunc(int32_t i)
{
        int32_t end;
        int32_t has_2 = 0;

        end = i % BASE;

        if(end != 7 && end != 3)
                return 0;

        for( ; i; i /= BASE){
                end = (i % BASE);

                if(end % 2 == 0){

                        if(end == 2){
                                if(has_2++)
                                        return 0;

                        } else {
                                return 0;
                        }

                }
        }

        return 1;

}

