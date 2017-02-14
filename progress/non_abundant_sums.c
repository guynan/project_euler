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
 * Project Euler 23 */

#include <stdio.h>
#include <stdlib.h>


#define MAX     28123 


int abundant(int i);
int main();


int main()
{
        printf("%d\n", abundant(4));

        return 0;


}



int abundant(int i)
{
        /* Make sure to change 50 */
        int intarr[50]; 
//        for(int f = 0; intarr[f]; f++){
 //               intarr[f] = '\0';
  //      }
        int index = 0;
        int sum;

        for(int a = 1; a < i; a++){
//                if(!i % a)
                if(i % a == 0){
                        intarr[index++] = a;
                        printf("a: %d\n", a);
                }

        }

        int *ptr = NULL;
        ptr = intarr;
        for(sum = 0; *ptr != '\0'; sum += *ptr++){

                printf("*ptr %d\n", *ptr);
        }
                
        return (sum > i);

}
