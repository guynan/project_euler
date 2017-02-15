/* Champernowne's constant

 * Project Euler: 40
 * Answer: 210 */


/* Includes */

#include <stdio.h>
#include <stdlib.h>

#define MAX     1000 /* << dmax */
#define DMAX    1000000
int champconst[DMAX];
int indexc = 0;

/* Prototypes */
int main();
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

        char *string = malloc(64 * sizeof(char));
        sprintf(string, "%d", i);

        for( ; *string != '\0'; ){
                champconst[indexc++] = (*string++ - '0');
        }
}
