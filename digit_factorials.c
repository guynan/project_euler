/* 145 is a curious number, as 
 * 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are 
 * equal to the sum of the factorial of their digits.

 * Note: as 1! = 1 and 2! = 2 are 
 * not sums they are not included.
 * Project Euler: 34 */

#include <stdio.h>

#define MAX     9999999999
#define LEN     21 /* Will be << n! */
long long factorials[LEN];
int init_factorials();

int main();

int main()
{
        int count; 
        init_factorials();

        for(int i = 0; i < 56; i++){
                printf("%lli\n", factorials[i]);
        }
        for(int c = 0; ; c++){
                if(is_digit_factorial(c)){
                        count++;
                }

                if(

        return 0;

}

long long 

int init_factorials()
{
        factorials[0] = 1; factorials[1] = 1;
        factorials[2] = 2;
        long long last = 2;
        for(long long i = 3; i < LEN; i++){
                factorials[i] = last * i;
                last = factorials[i];
        } 

        return 0;
}

int is_digit_factorial(int i)
{
        char strcpy[32];

        sprintf(strcpy, "%d", i);

        for 



}

int len(int i)
{
        char strcpy[32]; int c = 0

        sprintf(strcpy, "%li", i);

        for(; strcpy[c] != '\0'; c++);

        return c;
}

int ctoint(char c)
{
        return char - 48;
}
