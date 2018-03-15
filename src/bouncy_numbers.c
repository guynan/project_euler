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
 * Answer: 1587000 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define START           21780
#define START_RATIO     90
#define END_RATIO       99
#define DIGIT_LEN       10

int main(int argc, char** argv);
int isdesc(uint32_t i);
int isasc(uint32_t i);


int main(int argc, char** argv)
{
        /* Start with a known proportion and go from there
         * up until we find the expected ratio */
        uint32_t count = (START * START_RATIO) / 100;

        for(uint32_t i = START + 1; ; i++){

                count += (!isdesc(i) && ! isasc(i));

                /* We do this little dance where we take the percentage to
                 * avoid floating point calculations and flawed comparisons. We
                 * also ensure that the number we produce is evenly divisible
                 * so we don't get a result that is approximate */
                uint32_t curr = (i * END_RATIO) / 100;
                if(curr == count && ((i * END_RATIO) % 100) == 0){
                        printf("%d\n", i);
                        break;
                }
        }

        return 0;

}

int isdesc(uint32_t i)
{
        int last = i % 10;
        i /= 10;

        while(i){
                if(i % 10 > last)
                        return 0;
                last = i % 10;
                i /= 10;
        }

        return 1;
                
}

int isasc(uint32_t i)
{
        int last = i % 10;
        i /= 10;

        while(i){
                if(i % 10 < last)
                        return 0;
                last = i % 10;
                i /= 10;
        }

        return 1;
                
}

