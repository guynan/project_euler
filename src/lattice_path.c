/* Starting in the top left corner of a 2×2 grid, 
 * and only being able to move to the right and down, 
 * there are exactly 6 routes to the bottom right
 * corner.
 * How many such routes are there through a 20×20 grid?

 * Project Euler: 15 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define N       20

/* Note here that if you cannot access the 128 bit integer 
 * type then this will not work... */
#ifdef          __GNUC__
#define         MAX_UNSIGNED_INT        unsigned __int128
#else
#define         MAX_UNSIGNED_INT        uint64_t 
#endif

int main(int argc, char** argv);
MAX_UNSIGNED_INT countRoutes(int n);
MAX_UNSIGNED_INT factorial(int n);
MAX_UNSIGNED_INT reducedFactorial(int x, int n);


/* My solution to this problem relies
 * on the fact that the length of each path 
 * MUST be the same length (2n) and the number
 * of 'down' moves must equal the 'right' moves. */
int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu64"\n", countRoutes(N));

        return 0;

}


MAX_UNSIGNED_INT countRoutes(int n)
{
        /* (2n)! / (n! * n!) */
        /* Though; this can be simplified by
         * cancelling out n! on the bottom with 
         * n! on the top leaving n * n + 1 ... 2n
         * on the top reducing the size of both the 
         * numerator and denominator allowing higher
         * order problems to be calculated with the
         * same number of bits. */
        MAX_UNSIGNED_INT nfac = factorial(n);
        MAX_UNSIGNED_INT routes = reducedFactorial(2 * n, n) / nfac;

        return routes;

}

MAX_UNSIGNED_INT factorial(int n)
{
        MAX_UNSIGNED_INT i = 1;
        for( ; n > 0; i *= n--);
        return i;
}

MAX_UNSIGNED_INT reducedFactorial(int x, int n)
{
        MAX_UNSIGNED_INT i = 1;
        for( ; x > n; i *= x--);
        return i;
}
