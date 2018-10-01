/* If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

 * Not all numbers produce palindromes so quickly. For example,

 * 349 + 943 = 1292,
 * 1292 + 2921 = 4213
 * 4213 + 3124 = 7337

 * That is, 349 took three iterations to arrive at a palindrome.
 *
 * Although no one has proved it yet, it is thought that some numbers,
 * like 196, never produce a palindrome. A number that never
 * forms a palindrome through the reverse and add process is called
 * a Lychrel number. Due to the theoretical nature of these numbers,
 * and for the purpose of this problem, we shall assume that a number
 * is Lychrel until proven otherwise. In addition you are given
 * that for every number below ten-thousand, it will either (i)
 * become a palindrome in less than fifty iterations, or, (ii) no one,
 * with all the computing power that exists, has managed so far
 * to map it to a palindrome. In fact, 10677 is the first
 * number to be shown to require over fifty iterations
 * before producing a palindrome:
 * 4668731596684224866951378664 (53 iterations, 28-digits).
 *
 * Surprisingly, there are palindromic numbers that are
 * themselves Lychrel numbers; the first example is 4994.

 * How many Lychrel numbers are there below ten-thousand?

 * Project Euler: 55
 *
 * Answer: 249 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             10000
#define BASE            10
#define ITER_MAX        50


uint64_t intrev(uint64_t i);
int lycherl(uint64_t i);
int is_palindrome(uint64_t i);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t count = 0;

        for(int32_t i = 0; i < MAX; count += lycherl(i++))
                ;

        printf("%"PRId32"\n", count);

        return 0;

}


/* Returns whether the integer is lycherl or not
 * by checking up to ITER_MAX iterations */
int lycherl(uint64_t i)
{

        int32_t count = 0;

        if(is_palindrome(i)){
                i += intrev(i);
                count++;
        }

        while(!is_palindrome(i)){

                i += intrev(i);

                if(count++ > ITER_MAX){
                        return 1;
                }
        }

        return 0;

}

uint64_t intrev(uint64_t i)
{
        uint64_t rev = 0;
        uint64_t rem;

        while(i){
                rem = i % BASE;
                rev *= BASE;
                rev += rem;
                i /= BASE;
        }

        return rev;
}


int is_palindrome(uint64_t i)
{
        return (i == intrev(i));
}

