/* The palindromic number 595 is interesting because it can be written as the
 * sum of consecutive squares: 6^2  7^2  8^2  9^2  10^2  11^2  12^2.
 *
 * There are exactly eleven palindromes below one-thousand that can be written
 * as consecutive square sums, and the sum of these palindromes is 4164. Note
 * that 1 = 02  12 has not been included as this problem is concerned with the
 * squares of positive integers.
 *
 * Find the sum of all the numbers less than 10^8 that are both palindromic and
 * can be written as the sum of consecutive squares
 *
 * Project Euler: 125
 *
 * Answer: */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


//#define LIMIT           100000000
#define LIMIT           1000
#define BASE            10

uint32_t generatePalindrome(uint32_t i, uint32_t flag);
uint32_t isSquareSum(uint32_t* squares, uint32_t pal);
uint32_t* generateSquares(uint32_t limit);
uint32_t numLength(uint32_t i);
int main(int argc, char** argv);
uint32_t intrev(uint32_t i);
int isPalindrome(uint32_t i);



int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t sum = 0;
        uint64_t count = 0;

        uint32_t* squares = generateSquares(LIMIT);

        /* Note there are 20,000 palindromes in this range.
         * Since the range is so big and there are so few 
         * palindromes, it is far less computationally expensive
         * to instead generate palindromes and test those */

        uint32_t p = 1;

        /* R is a flag to designate whether we need to generate an odd
         * or an even length palindrome. */
        for(uint32_t r = 0; r < 2; r++){
                for(uint32_t i = 10; ; i++){
                        p = generatePalindrome(i, r);
                        count++;
                        if(p > LIMIT) break;
                        if(isSquareSum(squares, p)){
                                printf("%"PRIu32"\n", p);
                                sum += p;
                        }
                        
                }
        }


        printf("%"PRIu64"\n", sum);
        printf("count %"PRIu64"\n", count);
        free(squares);

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



uint32_t generatePalindrome(uint32_t i, uint32_t flag)
{
        uint32_t rev = (i);

        if(flag) i /= BASE; 

        while(rev){
                i = i * BASE + (rev % BASE);
                rev /= BASE;
        }

        return i;

}

                
uint32_t numLength(uint32_t i)
{
        uint32_t rem;
        uint32_t base = BASE;
        uint32_t n = 1;

        while(i % base != i){
                base *= 10;
                n++;
        }

        return n;
}


uint32_t isSquareSum(uint32_t* squares, uint32_t pal)
{

        /* Naive solution */

        for(uint32_t i = 0; squares[i]; i++){
                
                if(squares[i] > pal) return 0;

                uint64_t sum = 0;

                for(int j = i; squares[j]; j++){
                        sum += squares[j];

                        if(sum > pal) break;

                        if(pal == sum){
                                return 1;
                        }
                }

        }

        return 0;


}


uint32_t* generateSquares(uint32_t limit)
{
        /* Should be about 10000 squares before limit is hit */   

        uint32_t* squares = malloc(100000 * sizeof(uint32_t));

        for(uint32_t i = 1;  ; i++){

                squares[i - 1] = i * i;
                if(squares[i] > limit) return squares;

        }

        return squares;

}

