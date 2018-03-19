/* Consider the fraction, n/d, where n and d are positive integers. If n<d and
 * HCF(n,d)=1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d  8 in ascending order
 * of size, we get:
 *
 * 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3,
 * 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that 2/5 is the fraction immediately to the left of 3/7.
 *
 * By listing the set of reduced proper fractions for d  1,000,000 in ascending
 * order of size, find the numerator of the fraction immediately to the left of
 * 3/7.
 *
 * Project Euler: 71
 *
 * Answer: */


#include <stdio.h>
#include <stdint.h>


/* YEP THIS ONE IS FUCKED */


#define MAX     100000
//#define MAX     8

static const double three_sevenths = 3.0 / 7.0;
static const double two_sevenths = 2.0 / 7.0;

struct frac {
        uint64_t n;
        uint64_t d;
};


uint64_t gcd(uint64_t a, uint64_t b);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        
        /* Attempting this in a very naive way */

        uint64_t count = 0;

        for(uint64_t n = 1; n < MAX; n++){
                for(uint64_t d = 1; d < MAX; d++){
                        if(d <= n)
                                continue;

                        if((double) n/d > three_sevenths)
                                continue;

                        if((double) n/d < two_sevenths)
                                break;

                        if(gcd(n, d) != 1)
                                continue;

//                        printf("%li/%li\n", n, d);
                        count++;

                }

        }

        printf("%li\n", count);


        return 0;

}

/* Euler's Method to find the greatest common divisor */
uint64_t gcd(uint64_t a, uint64_t b)
{
        uint64_t tmp;        

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}
