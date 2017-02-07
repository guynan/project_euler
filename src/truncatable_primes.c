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


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Definitions */
#define MAX 750000
static int primes[80000];
static int res[12];
static int primesum = 0;
static int primec = 0;


/* Function Prototypes */
int truncateLeft(int i);
int truncateRight(int i);
int trueLeft(int prime);
int trueRight(int prime);
int isPrime(unsigned int s);
void initPrimes();
int inPrimes(int i);
int in(int i, int res[]);
int justifyParent(int prime);
int strtoint(char *string);
int main();


int main()
{
        register int prime;

	initPrimes();

        for(int i = 0; primec != 11 ; i++){

                prime = primes[i];

                if(trueLeft(prime) && trueRight(prime)){
                        primesum += prime;
                        primec++;
                }

        }

        printf("%d\n", primesum);

        return 0;

}


int trueLeft(int prime)
{
        int left;

        if (prime < 10) return 0; 

        left = truncateLeft(prime);

        for( ; left > 10; left = truncateLeft(left)){

                if(!inPrimes(left)) return 0;

        }

        left = truncateLeft(left);

        if(inPrimes(left)) return 1;

        return 0;

}


int trueRight(int prime)
{
        int right; 

        if (prime < 10) return 0; 

        right = truncateRight(prime);

        for( ; right > 10; right = truncateRight(right)){

                if(!inPrimes(right)) return 0;
                        
        }

        right = truncateLeft(right);

        if(inPrimes(right)) return 1;
                
        return 0;
}


/* Converting to a string and then
 * removing one character from the left 
 * of the string */
int truncateLeft(int i)
{
        if(i < 10) return i; 
                
        char *string = malloc(16 * sizeof(char));

        sprintf(string, "%d", i);

        string += 1;

        return strtoint(string);
}


/* Initially check to see if it is worth
 * converting to a string and then move from
 * the right of the string and return the int */
int truncateRight(int i)
{
        if(i < 10) return i;
                
        char string[16]; int c;

        sprintf(string, "%d", i);        

        for(c = 0; string[c] != '\0'; c++);

        string[c - 1] = '\0';

        return strtoint(string);
}


/* Convert a string to a decimal integer */
int strtoint(char *string)
{
        int dec;

        for(dec = 0; *string; ){
                dec = dec * 10 + (*string++ - '0');
        }

        return dec;
}

/* Generates a list of primes up to MAX */
void initPrimes()
{
        int count = 0;

        for(int i = 0; i < MAX; i++){
                if(isPrime(i)){
                        primes[count] = i;
                        count++;
                }
        }
}

        
/* This checks to see if `i` is
 * in the list of generated primes */
int inPrimes(int i)
{
        for(int c = 0; primes[c] != '\0'; c++){

                if(i == primes[c]) return 1;
                        
                if(i < primes[c]) return 0;
                        
        }

        return 0;
}


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(unsigned int s)
{
        if (s == 0 || s == 1) return 0;

        if (s == 2) return 1;

        /* Hopefully preventing rounding errors */
        int top = (int) round(sqrt(s) +1 );

        for(int i = 2; i < top+1; i++){

                if(i == top) return 1;

                if (s % i == 0) return 0;
                        
        }

        return 0;
}


/* Checks for i in the array res; if it 
 * finds it then it returns the index in the
 * array; if not, returns -1. */
int in(int i, int *res)
{
        for(int c = 0; *res != '\0'; c++){
                        
                if(*(res + c) == i) return c;
        }

        return -1;

}

/* Returns true if we had to justify the
 * parent in the res array */
int justifyParent(int prime)
{
        int left, index;

        left = truncateLeft(prime);
        index = in(left, res);

        /* Here we are checking if a child truncatable
         * prime has been added to the list. If it has
         * been, we replace it with the parent trunc. prime */
        if(index != -1){
                res[index] = prime;
                return 1;
        }

        return 0;

}

