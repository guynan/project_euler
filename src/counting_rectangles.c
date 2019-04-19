

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define TARGET_N        2000000
#define LIM             2000


int main(int argc, char** argv);
int32_t n_rectangles(int32_t h, int32_t v);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t nearest_area = 1;
        int32_t eps = TARGET_N;

        for(int32_t i = 1; i < LIM; i += 2){

                for(int32_t j = 2; j < LIM; j += 2){

                        int32_t n_rect = n_rectangles(i, j);

                        if(n_rect > TARGET_N){
                                break;
                        }

                        int32_t diff = TARGET_N - n_rect;

                        if(diff < eps){
                                eps = diff;
                                nearest_area = i * j;
                        }

                }
        }

        printf("%"PRId32"\n", nearest_area);

        return 0;

}

int32_t n_rectangles(int32_t h, int32_t v)
{
        return (h * v * (h + 1) * (v + 1)) >> 2;
}

