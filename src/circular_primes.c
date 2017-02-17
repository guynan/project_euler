/* The number, 197, is called a circular prime 
 * because all rotations of the digits: 
 * 197, 971, and 719, are themselves prime.

 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

 * How many circular primes are there below one million?

 * Project Euler: 35 
 * Answer: 55
 
 * Please when compiling use the `-O2' flag */


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Definitions */
#define MAX     1000000
static int primes[80000]; // I counted them
static int result[60];
static int resc = 0;


/* Prototypes */
int stringcomp(char *this, char *that);
int isPrime(unsigned int s);
void strprint(char *string);
int strtoint(char *string);
int in(int i, int *array);
void append(int *array);
int oneRotation(int i);
int len(char *string);
void circulate(int i);
int inPrimes(int i);
void initPrimes();
int main();


int main()
{
        initPrimes();

        /* Speed increase: Use list of primes how
         * you should for fucks sake. Iterate over list
         * checking if it is a prime and then append.
         * Here we check 1 million integers vs. just
         * ~ 75,000 primes */
        for(int i = 0; i < MAX; i++){
                circulate(i);
        }

        int counter = 0;
        for(int i = 0 ; i < 60; i++){
                if(result[i] != 0){
                        counter++;
                }
        }

        printf("%d\n", counter);
        return 0;
        
}        


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(unsigned int s)
{
        if (s <= 1) return 0;

        if (s == 2) return 1;

        /* Hopefully preventing rounding errors */
        int top = (int) round(sqrt(s) + 1);

        for(int i = 2; i < top + 1; i++){
                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;
}

/* Generate a list of primes up to 1mil */
void initPrimes()
{
        int count = 0;

        for(int i = 0; i < MAX; i++){
                if(isPrime(i)){
                        primes[count++] = i;
                }
        }
}

        
/* This checks to see if `i` is
 * in the list of generated primes */
int inPrimes(int i)
{
        int *prime = primes;
        while(*prime != '\0'){
                if(i == *prime) return 1;
                if(i < *prime++) return 0;
        }

        return 0;
}


/* Compares two strings */
int stringcomp(char *this, char *that)
{
        while(*this != '\0'){
                if(*this++ != *that++) return 0;
        }

        return (*that != '\0') ? 0 : 1; 
}


/* Length of a string array */
int len(char *string)
{
        int i;

        for(i = 0; *string++ != '\0'; i++);

        return i;
}


/* A real monty of a function:
 * We first have a look through all possible 
 * circular iterations of the integer `i`. 
 * If they are all prime numbers themselves; 
 * we chuck them in the `result` array using `append` */
void circulate(int i)
{
        int rotated, count = 0;
        int *circular = malloc(16 * sizeof(int));
        char *strcp = malloc(16 * sizeof(char));

        /* This is so we dont start rotating
         * one index integers */
        if(i < 10){

                if(inPrimes(i)){
                        result[resc++] = i;
                }

                return;
        }

        /* Create n as a an array of
         * characters */
        sprintf(strcp, "%d", i);

        /* Do one rotation so we can enter the loop */
        rotated = oneRotation(i);

        /* Return if it isn't even a prime */
        if(!inPrimes(i)){
                return;
        }

        else circular[count++] = i;
                
        /* While rotated value != i */
        while(i != rotated){

                if(inPrimes(rotated)){
                        rotated = oneRotation(rotated);
                        circular[count++] = rotated;
                }

                else return;
                        
        }

        append(circular);

}


/* Print a string */
void strprint(char *string)
{
        for( ; *string != '\0'; printf("%c", *string++));
        printf("\n");
}


/* @param: This takes a string
 * as an argument and returns an array of 
 * the rotated value */
int oneRotation(int i)
{
        char *string = malloc(16 * sizeof(char));
        char *res = malloc(16 * sizeof(char));

        sprintf(string, "%d", i);
        
        for(int c = 1; string[c] != '\0'; c++){

                if(string[c + 1] == '\0'){
                        res[0] = string[c];
                }

                res[c] = string[c - 1];
        }

        return strtoint(res);
}


/* Convert a string to a decimal integer */
int strtoint(char *string)
{
        int dec = 0;

        for( ; *string != '\0'; dec = dec * 10 + (*string++ - '0'))
                ;

        return dec;
}

/* Inserts the items of the array into the `result` array */
void append(int *array)
{
        /* Only need to check if one item is
         * in the list to know all the circular
         * primes are indeed in the list */
        if(in(*array, result)){
                return;
        }

        int value;

        /* Inserts unordered into `result` */
        while(*array != '\0'){
                value = *array++;
                if(!in(value, result)){
                        result[resc++] = value;
                }
        }

}

/* Pretty simple search; could make this faster by
 * appending in order and be able to break earlier */
int in(int i, int *array)
{
        while(*array != '\0'){
                if(i == *array++) return 1;
        }

        return 0;
}

