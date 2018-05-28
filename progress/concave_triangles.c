
#include <stdio.h>
#include <stdint.h>
#include <math.h>


#define END_RATIO       0.001
//#define END_RATIO       0.001
#define EPS     0.0000000001


int main(int argc, char** argv);
double solve_area(double x, double theta);
double solve_intersect(int32_t n, double startx);



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
         * X**2 + Y**2 = r**2
         *
         */

        /* Maybe replace this with M_PI_4 for greater precision */
        const double total_area = (4.0 - M_PI) / 16.0;

        double curr_angle, curr_area, x;

        double lastx = 0.0;

        for(int32_t n = 1; ; n += 1){

                /* Don't solve for the angle; unecessary */
                curr_angle = atan(pow(n, -1.0));
                x = solve_intersect(n, lastx);
//                printf("%d\n", n);
                curr_area = solve_area(x, curr_angle);

                if((curr_area / total_area) < END_RATIO){
                        printf("%d\n", n);
                        break;
                }

                lastx = x;

        }

        return 0;

}


/* x/n = 0.5 - sqrt(0.25 - (x - 0.5) ** 2)
 * this effectively solves for x
 * */
double solve_intersect(int32_t n, double startx)
{

        double step = 0.1;
        startx = 0.25;
        double x;

        for(x = startx; ; step *= 0.995){

                double lhs = x / (double) n;
                double rhs = 0.5 - sqrt(0.25 - ((x - 0.5) * (x - 0.5)));

                if(fabs(lhs - rhs) < EPS){
                        break;
                }

                /* Think I am getting overflow */
                if(lhs > rhs){
                        x -= step;
                } else {
                        x += step;
                }
                printf("%f\n", x);
        }

        return x;


}

double solve_area(double x, double theta)
{
        return 0.25 * x * tan(theta);
}

