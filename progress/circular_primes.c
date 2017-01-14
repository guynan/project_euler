/* The number, 197, is called a circular prime 
 * because all rotations of the digits: 
 * 197, 971, and 719, are themselves prime.

 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

 * How many circular primes are there below one million?

 * Project Euler: 35 */


/* Includes */
#include <stdio.h>
#include <math.h>


/* Definitions */
#define MAX     1000000
int primes[80000]; // I counted them
int res[500];


/* Prototypes */
int main();
int isPrime(unsigned int s);
int stringcomp(char this[], char that[]);
char * oneRotation(char string[]);
int strtoint(char string[]);
void strprint(char string[]);
void initPrimes();
int len(char string[]);


int main()
{
        initPrimes();

        /*
        for(int i = 0; i < MAX; i++){
                circulate(i);
        }

        int c; 

        for(c = 0; res[c] != '\0'; c++);

        printf("%d\n", c);
        */

        return 0;
        
}        


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(unsigned int s)
{
        if (s == 0 || s == 1){
                return 0;
        }

        if (s == 2){
                return 1;
        }

        /* Hopefully preventing rounding errors */
        int top = (int) round(sqrt(s) +1 );

        for(int i = 2; i < top+1; i++){
                if(i == top){
                        return 1;
                }

                if (s % i == 0){
                        return 0;
                }
        }

        return 0;
}

/* Generate a list of primes up to 1mil */
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
                if(i == primes[c]){
                        return 1;
                }
                
                if(i > primes[c]){
                        return 0;
                }
        }

        return 0;
}


/* Compares two strings */
int stringcomp(char this[], char that[])
{
        for(int i = 0; this[i] != '\0'; i++){
                if(this[i] != that[i]){
                        return 0;
                }
        }

        return 1;
}

/* Length of a string array */
int len(char string[])
{
        int i;

        for(i = 0; string[i] != '\0'; i++);

        return i;
}


/* Honestly no idea what I am doing */
void circulate(int i)
{
        char strcp[10];

        char *strptr;

        /* Create n as a an array of
         * characters */
        sprintf(strcp, "%d", i);
        
        /* While n != f */
        for(int a = 0; i != rotated; a++){
                strptr = oneRotation(strptr);

        }
}

/* Print a string */
void strprint(char string[])
{
        for(int m = 0; string[m] != '\0'; printf("%c", string[m]), m++);
}


/* @param: This takes a string
 * as an argument and returns an array of 
 * the rotated value */
char * oneRotation(char string[])
{

        static char res[5];

        for(int c = 0; string[c] != '\0'; c++){

                if(res[c + 1] == '\0'){
                        res[0] = string[c];
                }

                res[c] = string[c - 1];
        }

        return res;
}


/* Convert a string to a decimal integer */
int strtoint(char string[])
{
	int dec;

	for(int i = 0; string[i] != '\0'; i++){
		dec = dec * 10 + (string[i] - '0');
        }

        return dec;
}
