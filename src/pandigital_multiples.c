/* Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 *
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We
 * will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 * and 5, giving the pandigital, 918273645, which is the concatenated product
 * of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1?
 *
 * Project Euler: 38
 *
 * Answer: 932718654 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             9876
#define MAX_DIGIT_LEN   9
#define BASE            10


uint32_t pandigital_multiple(uint32_t i);
uint32_t concat(uint32_t a, uint32_t b);
int main(int argc, char** argv);
int is_pandigital(uint32_t i);
uint32_t pow10_g(uint32_t x);
uint32_t intlen(uint32_t x);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t largest = 0;

        for(uint32_t i = 2; i < MAX; i++){
                uint32_t k = pandigital_multiple(i);
                largest = (k > largest) ? k : largest;
        }

        printf("%"PRIu32"\n", largest);

        return 0;

}


/* In the event that a pandigital multiple can be made, this function shall
 * return that number, else it will return 0 */
uint32_t pandigital_multiple(uint32_t i)
{
        uint32_t cat = i;
        uint32_t length = 0;

        for(uint32_t j = 2; length < MAX_DIGIT_LEN; j++){

                cat = concat(cat, j * i);
                length = intlen(cat);
        }

        return is_pandigital(cat) ? cat : 0;

}


/* My little bit shift magic for testing pandigital numbers. */
int is_pandigital(uint32_t i)
{
        uint32_t set_ints = 0x0;
        uint32_t fault_bit = 0x2000;
        uint32_t bit_mask = 0x0;

        for( ; i; i /= BASE){
                bit_mask = 0x1;
                bit_mask <<= i % BASE;
                set_ints |= (set_ints & bit_mask) ? fault_bit : bit_mask;
        }

        return set_ints == 0x3FE;

}


uint32_t concat(uint32_t a, uint32_t b)
{
        a *= pow10_g(intlen(b));
        return a + b;
}


uint32_t pow10_g(uint32_t x)
{
        uint32_t ret = 10;

        for(uint32_t i = 1; i < x; i++){
                ret *= 10;
        }

        return ret;

}


uint32_t intlen(uint32_t x)
{
        uint32_t len = 0;
        for( ; x; x /= BASE){
                len++;
        }

        return len;
}

