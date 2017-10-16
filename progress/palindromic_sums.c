

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define LIMIT           100000000
//#define LIMIT           1000
#define BASE            10

uint32_t generatePalindrome(uint32_t i, uint32_t flag);
uint32_t generateSquares(uint32_t limit);
uint32_t numLength(uint32_t i);
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
        uint32_t p = 1;
        /* R is a flag to designate whether we need to generate an odd
         * or an even length palindrome. */
        for(uint32_t r = 0; r < 2; r++){
                for(uint32_t i = 1; ; i++){
                        p = generatePalindrome(i, r);
                        if(p > LIMIT) break;
                        count++;
                }
        }
        

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

uint32_t generatePalindrome(uint32_t i, uint32_t flag)
{
        uint32_t rev = (i);
        uint32_t rem;

        if(flag){
                i /= BASE;
        }

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

uint32_t longestConsec(uint32_t* primes, uint32_t max)
{
        uint32_t largest = 0;
        uint32_t length = 0;

        /* Naive solution */
        for(int i = 0; primes[i]; i++){
                
                uint64_t sum = 0;

                for(int j = i; primes[j]; j++){
                        sum += primes[j];

                        if(sum > max) break;

                        if(isIn(sum, (primes + j))){
                                uint32_t diff = j - i;

                                if(diff > length){
                                        largest = sum;
                                        length = diff;
                                }
                        }
                }
        }

        return largest;


}


uint32_t generateSquares(uint32_t limit)
{

