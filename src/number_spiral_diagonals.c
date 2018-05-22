
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX_N                   1001
#define OUTER_SPIRAL_SUM(n)     (4 *((n) * (n)) - (6 * (n - 1)))


int main(int argc, char** argv);

int main(int argc, char** argv)
{
        /* This one is done by a pen and paper reduction of the problem. I
         * found that I could represent the right corner trivially as the
         * number of what iteration of square it was, squared. The subsequent
         * results were as follows;
         *
         * S0 = n**2;
         * S1 = n**2 - (n - 1);
         * S2 = n**2 - 2(n - 1);
         * S3 = n**2 - 3(n - 1);
         *
         * Thus, our formula for the sum of all of these 'rings' in the square
         * is subsequently: 4n**2 - 6(n-1). Note however, this solution is for
         * n in reals > 1; */

        int64_t sum = 1;

        for(int32_t n = 3; n <= MAX_N; n += 2){
                sum += OUTER_SPIRAL_SUM(n);
        }

        printf("%"PRId64"\n", sum);

        return 0;

}

