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


#define MAX     1000000

static const double three_sevenths = 3.0 / 7.0;

struct frac {
        int32_t n;
        int32_t d;
        double fp;
};

int32_t gcd(int32_t a, int32_t b);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        struct frac left = {2, 7, (double) 2.0/7.0};

        for(int32_t n = 4; n < MAX; n++){

                int32_t STEP = (n & 0x1) ? 1 : 2;

                for(int32_t d = (n * 7 / 3) - 1; d < MAX; d += STEP){

                        double tmp = (double) n / (double) d;

                        if(tmp > three_sevenths){
                               continue;
                        }

                        if(tmp > left.fp){

                                if(gcd(n, d) != 1){
                                        continue;
                                }

                                left.n = n;
                                left.d = d;
                                left.fp = tmp;
                        }

                        if(tmp < three_sevenths){
                                break;
                        }

                }

        }

        printf("%d/%d\n", left.n, left.d);


        return 0;

}

/* Euler's Method to find the greatest common divisor */
int32_t gcd(int32_t a, int32_t b)
{
        int32_t tmp;

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}

