
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             1000
#define ABS(x)          ((x) < 0 ? (x) * -1 : (x))


int64_t diophantine_minimise_x(int64_t n);
int64_t perfect_square(int64_t n);
int main(int argc, char** argv);
int64_t init_m(int64_t n);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int64_t max_x = 0;
        int64_t max_d = 0;

        /* Note that this solution massively pisses me off since I worked so
         * hard on mathematically reducing the problem and ultimately I only
         * get a solution because of an order of magnitude hack */

        for(int64_t D = 1; D <= MAX; D++){

                int64_t x = diophantine_minimise_x(D);
                if(x > max_x) {
                        max_x = x;
                        max_d = D;
                }
        }

        printf("%ld\n", max_d);

        return 0;


}


int64_t init_m(int64_t n)
{

        int64_t m = 1;
        int64_t min_sol = n * n;
        int64_t min_m = n * n;
        int64_t last_k  = n * n;

        for( ; ; m++){

                int64_t k = ABS((m * m) - n);

                if(k < min_sol){
                        min_sol = k;
                        min_m = m;
                }

                if(k > last_k){
                        break;
                }

                last_k = k;

        }

        return min_m;
}

/* The limit that we impose upon this solution is a massive hack so we can
 * operate with 64bit integers. Looking at all of the solutions where there is
 * still a remainder for k at the end of this, the remainder is on the same
 * roughly on the same order of magnitude as the limit we impose. This means
 * that we are probably close, just a few iterations (albeit overflowing ones)
 * before we hit the solution. Instead of employing a big integer solution, we
 * can take the largest value of x for the order of magnitude is sufficient for
 * the numbers to be comparable */
int64_t diophantine_minimise_x(int64_t n)
{
        if(perfect_square(n)){
                return 0;
        }

        int64_t m = init_m(n);

        int64_t a = m;
        int64_t b = 1;

        int64_t k = (m * m) - n;
        int64_t tmp_a;

        for( ; m < 1000; ){

                /* This means that we have an overflow, and if k is that big
                 * anyway, it will make x smaller than other solutions */
                if(k == 0){
                        return 0;
                }

                /* We only want solutions with integer solutions to
                        (a + bm)/k */
                if((a + b * m) % ABS(k) != 0){
                        m++;
                        continue;
                }

                tmp_a = a;

                /* We proceed by the Chakravala method for an efficient way of
                 * solving Pell's equation */
                a = (tmp_a * m + (n * b)) / ABS(k);
                b = (tmp_a + (b * m))/ ABS(k);
                k = ((m * m) - n) / k;

                if(k == 1){
                        break;
                }

                m = 2;

        }

        return a;
}


int64_t perfect_square(int64_t n)
{
        int64_t x = round(sqrt((double) n));
        return (x * x) == n;
}

