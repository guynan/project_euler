/* How many distinct terms are in the 
 * sequence a^b where 2 <= a <= 100,
 * and 2 <= b <= 100 
 *
 * Project Euler: 29 */

/* Includes */
#include <stdio.h>
#include <math.h>

/* Definitions */
#define MAX_A   1000
#define MAX_B   1000
#define MAXLEN  1000000
unsigned long long int powers[MAXLEN];

/* Prototypes */
long len(unsigned long int list[]);
int inlist(long long int i, int count);
unsigned long long power(int a, int b);
int main();

int main()
{
        int temp = 0;
        int count = 0;
        unsigned long long int i = 0;

        int a; int b;

        for(a = 2; a <= MAX_A; a++){
                for(b = 2; b <= MAX_B; b++){
                        i = pow(a,b);
                        temp++;
                        
                        /* Insert in list of not already */
                        if (!inlist(i, count)){
                                powers[count] = i;
                                count++;
                        }

                }
        }

//        long int length = len(powers);
        printf("%d\n", count);
//        printf("%d\n", temp);

        return 0;

}                        



/* a to the power of b */
unsigned long long power(int a, int b)
{
        if (b == 0){
                return 1;
        }

        /* So we don't have to allocate 
         * the memory if b == 0 */
        register unsigned long long result = 1;

        for(int i = 0; i < b; i++){
                result *= a;
        }

        return result;
        
}


/* Check if i in array */
int inlist(long long int i, int count)
{
        int found = 0;

        /* Infinite loop... */
        for(long int a = 0; a < count+1; a++){
                /* Check if in list */
                if (powers[a] == i){
                        found = 1;
                        break;
                }
                /* Assume to be sorted; if value is
                 * bigger than current item, not in 
                 * the list */

/*
                if (powers[a] < i){
                        break;

                }
*/

        } 

        return found;
}

/* Find length of list */
long len(unsigned long int list[])
{
        long int i;

        for(i = 0; list[i] != '\0'; i++);

        return i;
}

