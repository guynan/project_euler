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
int isBinPalindrome(char *string);
char *stringcpy(char *string);
void stringrev(char *string);
int isPalindrome(int i);
char *strrev(char *str);
char *bin(int x);
int intrev(int i);
int main(int argc, char** argv);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int sum = 0;

        for(int i = 0; i < MAX; i++){
                sum += (isPalindrome(i) && isBinPalindrome(bin(i))) ? i : 0;
        }

        printf("%d\n", sum);

        return 0;

}

int isPalindrome(int i)
{
        if(i < 10) return 1;

        return (i == intrev(i));
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


/* Argument has to be a `char *' to
 * preserve leading zeroes */
int isBinPalindrome(char *string)
{
        char* reverse = stringcpy(string);

        strrev(reverse); 

        return 0 == strcmp(string, reverse);
}

/* Copies a string */
char * stringcpy(char *string)
{
        char* copy = malloc(64 * sizeof(char));

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

int intrev(int i)
{
        int rev = 0;
        while(i){
                rev *= 10;
                rev += (i % 10);
                i /= 10;
        }

        return rev;

}

