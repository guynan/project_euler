/* The decimal number, 585 = 10010010012 
 * (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than 
 * one million, which are palindromic in
 * base 10 and base 2.
 *
 * Project Euler: 36 
 * Answer: 872187 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX     1000000
#define STR     64

/* Prototypes */
int stringcmp(char *this, char *that);
int isBinPalindrome(char *string);
char *stringcpy(char *string);
void stringrev(char *string);
void strprint(char *string);
int stringlen(char *this);
int isPalindrome(int i);
char *strrev(char *str);
char *bin(int x);
int len(int i);
int main();

int main()
{

        int sum = 0;

        for(int i = 0; i < MAX; i++){
                sum += (isPalindrome(i) && isBinPalindrome(bin(i))) ? i : 0;
        }

        printf("%d\n", sum);

        return 0;

}

/* Checks if it is a palindrome
 * through string manipulation */
int isPalindrome(int i)
{
        if(i < 10) return 1;

        char *string = malloc(64 * sizeof(char));
        sprintf(string, "%d", i);

        char *reverse = stringcpy(string);
        strrev(reverse);

        return stringcmp(string, reverse);
}


/* Checks the length of an integer */
int len(int i)
{
        int a = 0; 
        char *strcpy = malloc(STR * sizeof(char));
        sprintf(strcpy, "%d", i);
        for(; strcpy[a] != '\0'; a++);

        return a;
}


/* Decimal to binary conversion */
char *bin(int x)
{
        size_t bits = (x == 0) ? 1 : log10((double) x)/log10(2) + 1;

        char *ret = malloc((bits + 1) * sizeof (char));

        for (size_t i = 0; i < bits ; i++) {
                ret[bits - i - 1] = (x & 1) ? '1' : '0';
                x >>= 1;
        }

        ret[bits] = '\0';

        return ret;
}


/* Print a string */
void strprint(char *string)
{
        for( ; *string != '\0'; printf("%c", *string++));
        printf("\n");
}


/* String comparison function to compare
 * both `this` and `that` */
int stringcmp(char *this, char *that)
{
        for( ; *this != '\0'; ){
                if(*this++ != *that++) return 0;
        }

        return (*that != '\0') ? 0 : 1;
}


int stringlen(char *this)
{
        int i;
        for(i = 0; *this++ != '\0'; i++);

        return i;
}


/* Argument has to be a `char *' to
 * preserve leading zeroes */
int isBinPalindrome(char *string)
{
        char *reverse = stringcpy(string);

        strrev(reverse); 

        return stringcmp(string, reverse);
}


/* Copies a string */
char * stringcpy(char *string)
{
        char *copy = malloc(64 * sizeof(char));

        for(int i = 0; *string != '\0'; i++){
                copy[i] = *string++;
        }

        return copy;
}


/* Reverses a string */
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
