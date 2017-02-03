/* We shall say that an n-digit number is
 * pandigital if it makes use of all the
 * digits 1 to n exactly once. For 
 * example, 2143 is a 4-digit pandigital
 * and is also prime. What is the largest
 * pandigital prime that exists? 

 * Project Euler: 41 
 * Answer: 7652413 */


/* Includes */
#include <stdio.h> 
#include <math.h> 


/* Definitions */
#define START   2000000 /* Skip a couple */
#define MAX     8000000


/* Protoypes */
int isPandigit(long int i);
int isPrime(unsigned long s);
int contains(char *string, int i);
void strprint(char *string);
int main();


int main()
{
        unsigned long int i;
        unsigned long int longest = 0;

        for(i = START; i < MAX; i++){
		if (isPandigit(i)) {
			if (isPrime(i)){
                                longest = i;
			}
                }
        }

        printf("%li\n", longest);

        return 0;
}


/* Convoluted way of checking if
 * the number is a pandigit */
int isPandigit(long int i)
{
        char string[16];

        sprintf(string, "%li", i);

        for(int c = 1; string[c - 1] != '\0'; c++){

                /* If it contains 0, not pandigital */
                if(!(string[c - 1] - '0')) return 0;

                if(!contains(string, c)) return 0;

        }

        return 1;
        
}


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(unsigned long s)
{
        if (s == 0 || s == 1) return 0;

        if (s == 2) return 1;

        /* Hopefully preventing rounding errors */
        int top = (int) round(sqrt(s) + 1);

        for(int i = 2; i < top+1; i++){
                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;
}


/* Iterates through string to see if
 * it is indeed in there */
int contains(char *string, int i)
{
        for( ; *string != '\0'; ){
                if((*string++ - '0') == i) return 1;
        }

        return 0;
}


/* Print a string like Python bro */
void strprint(char *string)
{
        for( ; *string != '\0'; printf("%c", *string++))
                ;
        printf("\n");
}

