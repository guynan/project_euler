
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX             50
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

        for(int64_t D = 1; D <= MAX; D++){

                int64_t x = diophantine_minimise_x(D);
                max_x = (x > max_x) ? x : max_x;
        }

//        printf("%d\n", max_x);
//        printf("%ld\n", diophantine_minimise_x(5));
        printf("%ld\n", init_m(10));
        printf("%ld\n", diophantine_minimise_x(10));

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
//                printf("m = %ld, k = %ld\n", m, k);

                last_k = k;

        }

        return min_m;
}

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

        for( ; ; m++){

                tmp_a = a;

                a = (tmp_a * m + (n * b)) / ABS(k);
                b = (tmp_a + (b * m))/ ABS(k);
                k = ((m * m) - n) / k;
                if((a + b * m) % k != 0) continue;

//                printf("%ld: (%ld, %ld, %ld)\n",n, a, b, k);

                if(k == 1){
                        break;
                }
                /*
                if((a + (b * m)) % ABS(k) == 0) {
                        puts("called");
                        continue;
                }
                */

        }

        printf("%ld: (%ld, %ld, %ld)\n",n, a, b, k);

        return a;
}


int64_t perfect_square(int64_t n)
{
        int64_t x = round(sqrt((double) n));
        return (x * x) == n;
}

