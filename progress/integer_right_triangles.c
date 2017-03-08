/* If p is the perimeter of a right angle triangle 
 * with integral length sides, {a,b,c}, there 
 * are exactly three solutions for p = 120.

 * {20,48,52}, {24,45,51}, {30,40,50}

 * For which value of p ≤ 1000, is the 
 * number of solutions maximised?
 *
 * Project Euler 39
 *
 * Answer: */


#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>


#define MAX     1000


int main();
int check(uint16_t a, uint16_t b, uint16_t c);


int main()
{
        int *p = malloc(MAX * sizeof(int));
        for(int i = 0; *p; p[i++] = 0);

        int perimeter;

        for(uint16_t a = 1; a < MAX; a++){
                for(uint16_t b = 1; b < MAX; b++){
                        for(uint16_t c = 1; c < MAX; c++){

                                perimeter = a + b + c;
                                if(perimeter > 1000) break;

                                p[perimeter] += check(a,b,c);
                        }
                }
        }

        int big;

        for( ; *++p; ){
                printf("%d\n", *p);
                big = (*p > big) ? *p : big;
        }

        printf("%d\n", big);

        return 0;
}


int check(uint16_t a, uint16_t b, uint16_t c)
{
        /* Pythagorean rule */
        return (pow(c, 2) == pow(a, 2) + pow(b, 2));
}


