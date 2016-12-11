/* The decimal number, 585 = 10010010012 
 * (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than 
 * one million, which are palindromic in
 * base 10 and base 2.
 *
 * Project Euler: 36 */

/* Pretty messy code and doesn't work for 
 * other data sets */

#include <stdio.h>

#define MAX     1000000

/* Prototypes */
int main();
int is_palindrome(int i);
int len(int i);

int main()
{

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


int len(int i)
{
        int a = 0; char strcpy[64];
        
        sprintf(strcpy, "%d", i);
        for(; strcpy[a] != '\0'; a++);

        return a;
}

