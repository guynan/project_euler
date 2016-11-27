/* A palindromic number reads the same both ways.
 * The largest palindrome made from the product
 * of two 2-digit numbers is 9009 = 91 x 99.
 *
 * Find the largest palindrome made from
 * the product of two 3-digit numbers.
 * Project Euler: 4 */

/* Pretty messy code and doesn't work for 
 * other data sets */

#include <stdio.h>

#define MAX     999

/* Prototypes */
int main();
int is_palindrome(int i);
int len(int i);

int main()
{
        register int test; int longest;

        /* Fuck this waterfall, like really */
        for(int i = 0; i < MAX; i++){
                for(int a = 0; a < MAX; a++){
                        test = i * a;
                        if(is_palindrome(test)){
                                if(test > longest){
                                        longest = test;
                                }
                        }
                }
        }
        printf("%d\n\n", is_palindrome(1221));

        printf("%d\n", longest);

        return 0;

}

/* Checks if it is a palindrome
 * through string manipulation */
int is_palindrome(int i)
{
        int length = len(i);
        char strcpy[length]; char check[length];
        
        sprintf(strcpy, "%d", i);

        length--;

        /* Creates array reverse of i */
        for(int a = 0; length >= 0; length--, a++){
                check[length] = strcpy[a];
        }

        for(int l = 0; check[l] != '\0' ; l++){
                if(check[l] != strcpy[l]){
                        return 0;
                }
        }

        return 1;

}


/* lol will return 6 always */
int len(int i)
{
        int a = 0; char strcpy[64];
        
        sprintf(strcpy, "%d", i);
        for(; strcpy[a] != '\0'; a++);

        return a;
}

