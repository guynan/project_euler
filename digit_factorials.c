/* 145 is a curious number, as 
 * 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are 
 * equal to the sum of the factorial of their digits.

 * Note: as 1! = 1 and 2! = 2 are 
 * not sums they are not included.
 * Project Euler: 34 */

/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX     2540160  
#define LEN     21 /* Will be << n! */
long long factorials[LEN];

/* Prototypes */
int is_digit_factorial(long long i);
int init_factorials();
int ctoint(char c);
int len(long long i);
int main();


int main()
{
        int count = 0;
        init_factorials();

        for(long long c = 10; ; c++){

                if(is_digit_factorial(c)){
                        printf("%lli\n", c);
                        count++;
                }

//                if(factorials[c] > MAX){
 //                       break;
  //              }
        }

        printf("%d\n", count);

        return 0;

}


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

int is_digit_factorial(long long i)
{
        char strcpy[32]; long sum = 0;
        int indexnum;

        sprintf(strcpy, "%lli", i);

        for(int c = 0; c < len(i); c++){
                indexnum = ctoint(strcpy[c]);
                sum += factorials[indexnum];
        }

        return(sum == i);  
}

int len(long long i)
{
        char strcpy[32]; int c = 0; char *p = strcpy;

        sprintf(strcpy, "%lli", i);

        for(; strcpy[c] != '\0'; c++);

        return c;
}

int ctoint(char c)
{
        return c - 48;
}
