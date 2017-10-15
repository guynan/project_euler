

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define LIMIT           100000000
//#define LIMIT           1000
#define BASE            10

uint32_t generatePalindrome(uint32_t i);
int main(int argc, char** argv);
uint32_t intrev(uint32_t i);
uint32_t isSquareSum(uint32_t i);
int isPalindrome(uint32_t i);



int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t sum = 0;
        uint64_t count = 0;

        /* Note there are 20,000 palindromes in this range.
         * Since the range is so big and there are so few 
         * palindromes, it is far less computationally expensive
         * to instead generate palindromes and test those */


        printf("%"PRIu64"\n", count);
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

uint32_t isSquareSum(uint32_t i)
{
        /* We know that if it is the sum of squares, the maximum value
         * the sum can be is the square root of the number. We then take
         */
}

uint32_t generatePalindrome(uint32_t i)
{
        uint32_t rev = intrev(i);
        uint32_t rem;

        while(rev){
                

// Code Graveyard
/*
        for(uint32_t i = 0; i < LIMIT; i++){
//                if(!isPalindrome(i)) continue;
//                sum += isSquareSum(i);
                count += isPalindrome(i);

        }
*/

