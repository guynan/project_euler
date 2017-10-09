/* Working from left-to-right if no digit is exceeded by the digit to its left
 * it is called an increasing number; for example, 134468.
 *
 * Similarly if no digit is exceeded by the digit to its right it is called a
 * decreasing number; for example, 66420.
 *
 * We shall call a positive integer that is neither increasing nor decreasing a
 * "bouncy" number; for example, 155349.
 *
 * Clearly there cannot be any bouncy numbers below one-hundred, but just over
 * half of the numbers below one-thousand (525) are bouncy. In fact, the least
 * number for which the proportion of bouncy numbers first reaches 50% is 538.
 *
 * Surprisingly, bouncy numbers become more and more common and by the time we
 * reach 21780 the proportion of bouncy numbers is equal to 90%.
 *
 * Find the least number for which the proportion of bouncy numbers is exactly
 * 99%.
 *
 * Project Euler: 112
 *
 * Answer: */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


#define START           21780
#define START_RATIO     0.9
#define END_RATIO       0.99
#define DIGIT_LEN       10

int main(int argc, char** argv);
int isAscending(char* a);
int isDescending(char* a);


int main(int argc, char** argv)
{
        char* digit = malloc(DIGIT_LEN * sizeof(char));

        /* Start with a known proportion and go from there
         * up until we find the expected ratio */
        uint32_t count = START * START_RATIO;

        for(uint32_t i = START + 1; ; i++){

                sprintf(digit, "%"PRIu32, i);
                
                count += (!isDescending(digit) && ! isAscending(digit));

                if(ceil(i * END_RATIO) == count){
                        printf("%d\n", i);
                        break;
                }
        }

        return 0;

}

int isDescending(char* a)
{
        char last = *a;
        a++;

        while(*a){
                if(*a > last) return 0;
                last = *a;
                a++;
        }

        return 1;
                
}

int isAscending(char* a)
{
        char last = *a;
        a++;

        while(*a){
                if(*a < last) return 0;
                last = *a;
                a++;
        }

        return 1;
}