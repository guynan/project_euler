/* A Pythagorean triplet is a set of 
 * three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet 
 * for which a + b + c = 1000.
 * Find the product abc.
 * 
 * Answer: 31875000
 * Project Euler: 9 */

#include <stdio.h>
#include <math.h>

#define MAX     1000

/* Prototypes */
int main();
int ispythag(int a, int b, int c);
int sumcheck(int a, int b, int c);

int main()
{
        int product = 0;

        for(int a = 0; a <= MAX; a++){
                for(int b = 0; b <= MAX; b++){
                        for(int c = 0; c <= MAX; c++){
                                if(sumcheck(a, b, c) && ispythag(a, b, c)){
                                        product = a * b * c;
                                        break; 
                                }
                        }

                        if(product != 0){
                                break;
                        }
                }

                if(product != 0){
                        break;
                }
        }
       
        printf("%d\n", product); 

        return 0;
}

int ispythag(int a, int b, int c)
{
        return (pow(a, 2) + pow(b, 2) == pow(c, 2));
}

int sumcheck(int a, int b, int c)
{
        return (a + b + c == MAX);
}
                
