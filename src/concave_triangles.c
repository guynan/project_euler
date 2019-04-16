
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


#define END_RATIO       0.001
#define EPS             0.000000001
#define COARSE_STEP     64


double solve_area(double x, int32_t n, double(*f)(double x));
double solve_intersect(int32_t n);
double circle_equation(double x);
int main(int argc, char** argv);
double area_defect(double x);
double null_area(double x);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* If we define the diameter as 1; the area for the lower quadrant of
         * the square is (1/2)**2. The area of the sector is (1/4)(1/2)**2 pi
         *
         * This makes the total area (1/4) - (pi)/16 which is equivalently;
         *
         * (4 - pi) / 16;
         *
         * Our angle that we create is thusly the inverse tan of (1/n) where n
         * is the number of bound circles that we wish to find
         *
         * We know that the formula of a circle fulfils the general formula
         *
         * X**2 + Y**2 = r**2 */

        int32_t n;
        double curr_area, x;
        int32_t step = COARSE_STEP;
        double (*area_func) (double x) = null_area;
        const double total_area = (1.0 / 4.0) - (M_PI_4 / 4.0);

        /* Here we do a coarse search for something that first satisfies the
         * area constraint. Since we have skipped over so many values, we then
         * go back to the start of this range and try each value, one by one,
         * but this time *also* with a calculation that is far more precise so
         * that we can find the exact solution */

        for(n = 1; ; n += step){

                x = solve_intersect(n);
                curr_area = solve_area(x, n, area_func);

                if((curr_area / total_area) < END_RATIO){

                        /* This means that this is the second time visiting */
                        if(area_func == area_defect){
                                break;
                        }

                        area_func = area_defect;
                        n -= (COARSE_STEP + 2);
                        step = 1;

                }

        }

        printf("%"PRId32"\n", n);

        return 0;

}


/* Here we make the intersection of our curve of the circle equal to the
 * equation of the line that meets said curve from the bottom left corner to
 * the top right corner of the nth square. Symbolically;
 *
 *      x/n = 0.5 - sqrt(0.25 - (x - 0.5) ** 2)
 *
 * this solves for x by evaluating the difference in both functions */
double solve_intersect(int32_t n)
{
        double step = 0.05;
        double x;

        for(x = 0.025; ; step *= 0.99){

                double lhs = x / (double) n;
                double rhs = circle_equation(x);

                if(fabs(lhs - rhs) < EPS){
                        break;
                }

                x += (lhs > rhs) ? (step * -1) : step;

        }

        return x;

}


/* This is a simplification of 1/2 a * b * sin c.
 * Since that we know the b value (distance from origin to the where x = 0 on
 * the curve) is 0.5 and the angle sin(c) is the angle of the inverse tan of
 * the inverse of n, we can simplify this substantially to the below. The
 * function below takes into account whether it or not it is a rough search
 * (where one does not take into consideration the area of the concavity) or
 * the converse situation where one does. */
double solve_area(double x, int32_t n, double(*f)(double x))
{
        return ((0.25 * x) / (double) n) - f(x);
}


/* Here we integrate function `f` from the bounds a -> b. The number n is our
 * sampling frequency within each integral bound. */
double integral(double(*f)(double x), double a, double b, int32_t n)
{
        double step = (b - a) / (double) n;
        double area = 0.0;

        for(int32_t i = 0; i < n; i++){
                area += f(a + (i + 0.5) * step) * step;
        }

        return area;

}


/* Here we get a precise measurement for the area of the defect created by the
 * concavity of the circle. We do so by evaluating the area of the triangle
 * from value x using the y value (0.5 * base * height) and evaluating the
 * integral beneath the circle from the bounds of x to 0.5 (the radius) */
double area_defect(double x)
{
        double y = circle_equation(x);
        return ((0.5 - x) * y) / 2.0 - integral(circle_equation, x, 0.5, 50);
}


/* The function that yields a result for y given the value x, but *only* for
 * this specific quadrant of the circle; bottom left. */
double circle_equation(double x)
{
        return 0.5 - sqrt(0.25 - ((x - 0.5) * (x - 0.5)));
}

/* Returns zero with the absolute intention of doing so */
double null_area(double x)
{
        (void) x;
        return 0.0;
}

