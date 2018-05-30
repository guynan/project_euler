#include <stdio.h>
#include <stdint.h>
#include <math.h>


#define MAX             10000000
#define CACHE_MAX       10000

//static int32_t cache[CACHE_MAX];

int main(int argc, char** argv);
int32_t numdivis(int32_t f);



int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t count = 0;
        int32_t n_divis = 0;
        int32_t next;

        for(int32_t n = 1; n < MAX; n++){

                next = numdivis(n + 1);
                count += (n_divis == next);
                n_divis = next;
        }

        printf("%d\n", count);

        return 0;


}


int32_t numdivis(int32_t n)
{
        int32_t count = 0;

        int32_t top = (int32_t) round(sqrt((float) n));

        for(int32_t i = 1; i <= top; i++){
                count += ((n % i == 0) ? ((i * i == n) ? 1 : 2) : 0);

                /*
                if(cache[(n / i < CACHE_MAX) ? n / i : 1]){
                        count *= i;
                        goto out;
                }
                */

        }

/*
out:

        cache[(n < CACHE_MAX) ? n : 0] = count;
*/

        return count;

}

