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

int pythagorean(int a, int b, int c);
int main(int argc, char** argv);
int maxsolutions(int max);
int searchmax(int* arr);

int main(int argc, char** argv)
{
        (void) argc; (void) argv;

        printf("%d\n", maxsolutions(MAX));

        return 0;

}

int maxsolutions(int max)
{
        int* maxarr = malloc(max * sizeof(int));

        /* Naive method */
        for(int a = 1; a < max; a++){
                for(int b = 1; (a + b) < max; b++){
                        for(int c = 1; (a + b + c) < max; c++){
                                if(!pythagorean(a, b, c)) continue;

                                maxarr[a + b + c]++;
                        }
                }
        }

        return searchmax(maxarr);

}

int searchmax(int* arr)
{
        int ind = 0; int val = 0;
        

        for(int i = 0; i < MAX; i++){
                if(arr[i] > val){
                        val = arr[i]; 
                        ind = i;
                }
        }

        return ind;

}
                

int pythagorean(int a, int b, int c)
{
        return (pow(a, 2) + pow(b, 2) == pow(c, 2));
}

