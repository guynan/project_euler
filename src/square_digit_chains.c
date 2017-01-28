/* A number chain is created by continuously adding 
 * the square of the digits in a number to form a 
 * new number until it has been seen before.

 * For example,

 * 44 → 32 → 13 → 10 → 1 → 1
 * 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

 * Therefore any chain that arrives at 1 or 89 will 
 * become stuck in an endless loop. What is most 
 * amazing is that EVERY starting number will 
 * eventually arrive at 1 or 89.

 * How many starting numbers below ten million 
 * will arrive at 89?
 *
 * Project Euler: 92
 * Answer: 8581146 */


/* Inclusions */
#include <stdio.h>
#include <math.h>


/* Definitions */
#define MAX     10000000


/* Function Prototypes */
int main();
char * castIntString(int i);
int strtoint(char *string);
int satisfies(int i);

int main()
{
        int count;

        for(int i = 1; i < MAX; i++){

                count += (satisfies(i)) ? 1 : 0;
        }

        printf("%d\n", count);


        return 0;

}


/* Here we do some cheeky string hacking 
 * to check if the number chain ends in 89 */
int satisfies(int i)
{
        int sum = 0;
        char *strptr = castIntString(i);

        for( ; ; strptr = castIntString(sum)){

                /* Finds the sum of square of numbers in loop */
                for(sum = 0; *strptr != '\0'; sum += pow((*strptr++ - '0'), 2));

                if(sum == 89 || sum == 1) break;

        }

        return (sum == 89);

}


/* Simply casts an integer to a string */
char * castIntString(int i)
{
        static char string[32];

        /* I don't want to have to do 
         * it like this but I am also sleepy */
        sprintf(string, "%d", i);

        return string;
}


/* Convert a string to a decimal integer */
int strtoint(char *string)
{
        int dec;

        for(dec = 0; *string != '\0'; ){
                dec = dec * 10 + (*string++ - '0');
        }

        return dec;
}

