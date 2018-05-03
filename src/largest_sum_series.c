/* Largest Sum in a series
 * Find the thirteen adjacent digits
 * in the 1000-digit number that have the
 * greatest product. What is the value of this product?

 * Answer: 23514624000
 * Project Euler: 9 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             987
#define LEN_ADJ         13


static char numstr[1024] =
                        "73167176531330624919225119674426574742355349194934"
                        "96983520312774506326239578318016984801869478851843858"
                        "61560789112949495459501737958331952853208805511125406"
                        "98747158523863050715693290963295227443043557668966489"
                        "50445244523161731856403098711121722383113622298934233"
                        "80308135336276614282806444486645238749303589072962904"
                        "91560440772390713810515859307960866701724271218839987"
                        "97908792274921901699720888093776657273330010533678812"
                        "20235421809751254540594752243525849077116705560136048"
                        "39586446706324415722155397536978179778461740649551492"
                        "90862569321978468622482839722413756570560574902614079"
                        "72968652414535100474821663704844031998900088952434506"
                        "58541227588666881164271714799244429282308634656748139"
                        "19123162824586178664583591245665294765456828489128831"
                        "42607690042242190226710556263211111093705442175069416"
                        "58960408071984038509624554443629812309878799272442849"
                        "09188845801561660979191338754992005240636899125607176"
                        "06058861164671094050775410022569831552000559357297257"
                        "1636269561882670428252483600823257530420752963450"
;


void numconv(char* numstr);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int64_t largest = 0;
        int64_t prod;
        char* tmp;

        numconv(numstr);

        for(int32_t i = 0; i < MAX; i++){

                prod = 1;
                tmp = numstr + i;

                for(int32_t j = 0; j < LEN_ADJ; j++){

                        /* We know that if the current number is zero, that
                         * means that at least 12 of the next products of the
                         * series starting from index i will all evaluate to
                         * zero. This is a tricky one to evaluate whether the
                         * branch is worthwhile *or* it is better to keep the
                         * instruction pipeline very hot. Testing
                         * inconclusive */

                        if(!*tmp){
                                i += 12;
                                break;
                        }

                        prod *= *tmp++;
                }

                largest = (prod > largest) ? prod : largest;

        }

        printf("%"PRId64"\n", largest);

        return 0;
}

/* Converts string to array of integers
 * as this yields 13x fewer conversions */
void numconv(char* numstr)
{
        for( ; *numstr; *numstr++ -= '0')
                ;

        return;
}

