/* A palindromic number reads the same both ways.
 * The largest palindrome made from the product
 * of two 2-digit numbers is 9009 = 91 x 99.
 *
 * Find the largest palindrome made from
 * the product of two 3-digit numbers.
 *
 * Answer: 906609
 * Project Euler: 4 */

/* Pretty messy code and doesn't work for 
 * other data sets */

#include <stdio.h>
#include <stdint.h>


#define MAX     999
#define BASE    10
#define START   100


int main(int argc, char** argv);
int isPalindrome(uint32_t i);
uint32_t intrev(uint32_t i);


int main(int argc, char** argv)
{
        uint32_t test; uint32_t longest;

        /* Fuck this waterfall, like really */
        for(uint32_t i = 0; i < MAX; i++){
                for(uint32_t j = 0; a < MAX; a++){

                        test = i * j;

                        if(isPalindrome(test) && test > longest){
                                        longest = test;
                        }
                }
        }

        printf("%"PRIu32"\n", longest);

        return 0;

}


uint32_t intrev(uint32_t i)
{
        uint32_t rev = 0;
        uint32_t rem;

        while(i){
                rem = i % BASE;
                rev *= BASE;
                rev += rem;
                i /= BASE;
        }

        return rev;
}


int isPalindrome(uint32_t i)
{
        return (i == intrev(i));
}

