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


int main()
{
        int *p = malloc(MAX * sizeof(int));

        for(uint16_t a = 1; a < MAX; a++){
                for(uint16_t b = 1; b < MAX; b++){
                        for(uint16_t c = 1; c < MAX; c++){

                                perimeter = a + b + c;
                                if(perimeter > 1000) break;

                                count += check(a,b,c);
                        }
                }
        }

        return 0;
}


int check(uint16_t a, uint16_t b, uint16_t c)
{
        /* Pythagorean rule */
        return (pow(c, 2) == pow(a, 2) + pow(b, 2));
}











