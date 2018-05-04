/* A Harshad or Niven number is a number that
 * is divisible by the sum of its digits.
 * 201 is a Harshad number because it is divisible
 * by 3 (the sum of its digits.)
 * When we truncate the last digit from 201, we get 20,
 * which is a Harshad number.
 * When we truncate the last digit from 20, we get 2,
 * which is also a Harshad number.
 * Let's call a Harshad number that, while recursively
 * truncating the last digit, always results in a Harshad
 * number a right truncatable Harshad number.

 * Also:
 * 201/3=67 which is prime.
 * Let's call a Harshad number that, when divided by
 * the sum of its digits, results in a prime a strong Harshad number.

 * Now take the number 2011 which is prime.
 * When we truncate the last digit from it we get 201,
 * a strong Harshad number that is also right truncatable.
 * Let's call such primes strong, right truncatable Harshad primes.

 * You are given that the sum of the strong,
 * right truncatable Harshad primes less than 10000 is 90619.

 * Find the sum of the strong, right truncatable Harshad
 * primes less than 10^14.
 *
 * Project Euler: 387
 *
 * Answer: */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>


#define START   10000
#define MAX     100000000000000 /* 1 x 10^14 */
#define PRESUM  90619
#define BASE    10


uint64_t truncateRight(uint64_t i);
uint64_t digital_sum(uint64_t i);
int isHarshad(uint64_t s);
int isPrime(uint64_t s);
int main(int argc, char** argv);


/* What we know:
        - They must be truncatable, meaning we must know the first number for
          this must apply until the last number

 */
int main(int argc, char** argv)
{
        int trunc; int sum = 0;

        for(uint64_t i = 0; i < MAX; i+= 10){

        }

        return 0;

}

int SRTHP(uint64_t max)
{
        uint64_t bases[4] = {2,3,5,7};
        uint64_t allowed_append[4] = {1,2,3,7};
        uint64_t res = 0;
        uint64_t inner = 0;

        for(uint32_t i = 0; i < 4; i++){
                res = bases[i];
                while(res < max){
                        inner = res;

                        for(uint32_t i = 0; i < 4; i++){
                                inner = int_append(inner, allowed_append[i]);
                        }

                }

        }


}

int isHarshad(uint64_t s)
{
        return (s % digital_sum(s) == 0);
}


/* Could do a Sieve of Eratosthenes but
 * this ain't Python and we can brute force
 * the shit out of this all the way up to
 * `MAX` with the power of our optimised
 * outer loops. Got memory to burn */
int isPrime(uint64_t s)
{
	if(s < 1) return 0;

        if (s == 2) return 1;

        int top = (int) round(sqrt(s))+1;

        for(int i = 2; i < top +1 ; i++){

                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;
}


/* Initially check to see if it is worth
 * converting to a string and then move from
 * the right of the string and return the int */
uint64_t truncateRight(uint64_t right)
{
        for( ; right; right /= BASE){

                if(!isPrime(right))
                        return 0;
        }

        return 1;

}


/* Convert a string to a decimal integer */
uint64_t strtoint(char *string)
{
        int dec = 0;

        while(*string){
                dec = dec * 10 + (*string++ - '0');
        }

        return dec;
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

int left_trunc(int32_t left)
{
        for( ; left; left = intrev(intrev(left) / BASE)){

                if(!isPrime(left))
                        return 0;
        }

        return 1;

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

uint64_t digital_sum(uint64_t i)
{
        uint64_t digital_sum = 0;

        for( ; i; i /= BASE){
                digital_sum += i % BASE;
        }

        return digital_sum;
}

/* Note; this is only for appending *SINGLE* digits to the end of `base` */
uint64_t int_append(uint64_t base, uint64_t offset)
{
        return (base * BASE) + offset;
}
