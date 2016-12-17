/* Includes */

#include <stdio.h>

#define MAX     1000 /* << dmax */
#define DMAX    1000000
int champconst[DMAX];
int indexc = 0;

/* Prototypes */
int main();
int ctoint(char c);
void append(int i);


int main()
{

        for(int i = 0; indexc < DMAX; i++){
                append(i);
        }
        
        int product = 1;

        for(int i = 1; i < DMAX; i *= 10){
                product *= champconst[i];
        }

        printf("%d\n", product);
}


/* Converts int to a string, iterates over
 * the string incrementing the global indexc
 * counter */
void append(int i){

        char string[64];
        sprintf(string, "%d", i);

        for(int c = 0; string[c] != '\0'; c++){
                champconst[indexc] = ctoint(string[c]);
                indexc++;
        }
}


/* Manual char to int conversion */
int ctoint(char c)
{
        int x =  (int) c - 48;
        return x;
}

