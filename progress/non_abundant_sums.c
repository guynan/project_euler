/* A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of 
 * the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, 
 * which means that 28 is a perfect number.

 * A number n is called deficient if the sum of its proper 
 * divisors is less than n and it is called abundant if this sum exceeds n.

 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
 * the smallest number that can be written as the sum of two 
 * abundant numbers is 24. By mathematical analysis,
 * it can be shown that all integers greater than 28123 can
 * be written as the sum of two abundant numbers. 
 * However, this upper limit cannot be reduced any 
 * further by analysis even though it is known that the greatest
 * number that cannot be expressed as the sum of 
 * two abundant numbers is less than this limit.

 * Find the sum of all the positive integers 
 * which cannot be written as the sum of two abundant numbers.
 *
 * Project Euler 23 
 * Answer: 4179871 */

/* This is really fucking slow - please optimise */
/* As the numbers which aren't abundant are much 
 * smaller, try having that as your search space */
 

#include <stdio.h>
#include <stdlib.h>


#define MAX     28123 
static int abund[MAX];
static int abundc = 0;


int sumAbundant(int i);
int abundant(int i);
int main();


int main()
{
        for(int i = 0; i < MAX; i++){
                if(abundant(i)) abund[abundc++] = i;
        }

        int sum = 0;
        for(int i = 1; i < MAX; i++){
                sum += (!sumAbundant(i)) ? i : 0;
        }

        printf("%d\n", sum);

        return 0;


}


int abundant(int i)
{
        int sum = 0;

        for(int a = 1; a < i; a++){
                if(!(i % a)) sum += a;
        }

        return (sum > i);

}

int sumAbundant(int i)
{
        int *ptr = abund; int sum;

        for( ; *ptr; ){
                for(int a = 0; abund[a] != '\0'; a++){

                        if(abund[a] > i) break;

                        sum = *ptr + abund[a];

                        if(sum == i) return 1;
                        if(sum > i) break;

                }

                if(*ptr++ > i) return 0;

        }

        return 0;

}

