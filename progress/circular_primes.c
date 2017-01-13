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
void strprint(char string[]);
void initPrimes();
int len(char c[]);

int main()
{
        initPrimes();

        for(int i = 0; i < MAX; i++){
                circulate(i);
        }

        int c; 

        for(c = 0; res[c] != '\0'; c++);

        printf("%d\n", c);

        return 0;
        
}        



/* This is the bottleneck. Takes ages */
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

void circulate(int i)
{
        char n[10];
        char f[10];

        /* Create n as a an array of 
         * characters */
        sprintf(n, "%d", i);

        /* While n != f */
        for(int l = 0; !stringcomp(n,f); l++){
                if(l + 1 > len(f)){
                        l = 0;
                }

                f[l] = n[l + 1];
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


/*
int stringcomp(char this[], char that[])
{
        for(int i = 0; this[i] != '\0'; i++){
                if(this[i] != that[i]){
                        return 0;
                }
        }

        return 1;
}
*/

int len(char c[])
{
        int i;

        for(c = 0; c[i] != '\0'; c++);

        return c;
}


void circulate(int i)
{
        char strcp[10];
        char f[10];
        char tmp[10];

        /* Create n as a an array of
         * characters */
        sprintf(strcp, "%d", i);

        /* Copy the string into `tmp` */
        for(int i = 0; strcp[i] != '\0'; tmp[i] = strcp[i], i++);

        strprint(tmp);


        /* While n != f */
        for(int l = 0; !stringcomp(strcp ,f); l++){

                for(int c = l; tmp[c] != '\0'; c++){

                        if(f[c + 1] == '\0'){
                                f[0] = tmp[c];
                        }

                        f[c] = tmp[c - 1];
                }

//                strprint(tmp);

                for(int i = 0; tmp[i] != '\0'; tmp[i] = f[i], i++);

                printf("\n");
        }
}

void strprint(char string[])
{

        for(int m = 0; string[m] != '\0'; printf("%c", string[m]), m++);
}

