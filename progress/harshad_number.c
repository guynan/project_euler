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
 * primes less than 1014.
 *
 * Project Euler: 387
 *
 * Answer: */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <gmp.h> /* Should fit in 64bit */


#define START   10000
#define MAX     100000000000000 /* 1 x 10^14 */
#define PRESUM  90619


long long truncateRight(long long i);
long long strtoint(char *string);
int isHarshad(long long s);
int isPrime(long long s);
int main();


int main()
{

        printf("%lli\n", truncateRight(2345));
        return 0;

}


/* This function is totally beautiful */
int isHarshad(long long s)
{
        int sum = 0;
        char *strptr = malloc(16 * sizeof(long long));

        sprintf(strptr, "%lli", s);

        for( ; *strptr; sum += (*strptr++ - '0'))
                ;

        return (s % sum == 0);
}


/* Could do a Sieve of Eratosthenes but
 * this ain't Python and we can brute force
 * the shit out of this all the way up to
 * `MAX` with the power of our optimised 
 * outer loops. Got memory to burn */
int isPrime(long long s)
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
long long truncateRight(long long i)
{
        char *strptr = malloc(16 * sizeof(long long));
	
        sprintf(strptr, "%lli", i);        

        for( ; *strptr++; );

        *strptr--; 
        *strptr  = '\0';

        return strtoint(strptr);
}


/* Convert a string to a decimal integer */
long long strtoint(char *string)
{
        int dec;

        for(dec = 0; *string != '\0'; ){
                dec = dec * 10 + (*string++ - '0');
        }

        return dec;
}

