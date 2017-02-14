/* It can be seen that the number, 125874, 
 * and its double, 251748, contain
 * exactly the same digits, but in a different order.

 * Find the smallest positive integer, x, such that 
 * 2x, 3x, 4x, 5x, and 6x, contain the same digits.

 * Project Euler: 52 
 * Answer: 142857 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int contains(char *string, char i);
int permuted(int i, int compare);
int intLen(int i);
int valid(int i);
int main();


int main()
{
        int i;
        for(i = 1; ; i++){
                if(valid(i)) break;
        }

        printf("%d\n", i);

        return 0;
}


/* Checks if the integer is valid by comparing
 * it against multiples of itself. */
int valid(int i)
{
        int compare;
        for(int c = 2; c < 7; c++){
                compare = i * c;

                if(intLen(i) != intLen(compare)) return 0;

                if(!permuted(i , compare)) return 0;
        }

        return 1;
}


/* Checks if the integer is a permutation
 * of itself multiplied by another integer */
int permuted(int i, int compare)
{
        char *iptr = malloc(16 * sizeof(char));
        char *compptr = malloc(16 * sizeof(char));

        sprintf(iptr, "%d", i);
        sprintf(compptr, "%d", compare);

        for( ; *iptr; ){
                if(!contains(compptr, *iptr++)) return 0;
        }

        return 1;

}


/* Iterates through string to see if
 * it is indeed in there */
int contains(char *string, char i)
{
        for( ; *string != '\0'; ){
                if(*string++ == i) return 1;
        }

        return 0;
}


int intLen(int i)
{
        return (floor(log10(abs(i))) + 1);
}

