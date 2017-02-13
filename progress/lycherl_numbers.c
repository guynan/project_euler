/* If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

 * Not all numbers produce palindromes so quickly. For example,

 * 349 + 943 = 1292,
 * 1292 + 2921 = 4213
 * 4213 + 3124 = 7337

 * That is, 349 took three iterations to arrive at a palindrome.
 * 
 * Although no one has proved it yet, it is thought that some numbers, 
 * like 196, never produce a palindrome. A number that never 
 * forms a palindrome through the reverse and add process is called
 * a Lychrel number. Due to the theoretical nature of these numbers, 
 * and for the purpose of this problem, we shall assume that a number 
 * is Lychrel until proven otherwise. In addition you are given 
 * that for every number below ten-thousand, it will either (i) 
 * become a palindrome in less than fifty iterations, or, (ii) no one, 
 * with all the computing power that exists, has managed so far 
 * to map it to a palindrome. In fact, 10677 is the first 
 * number to be shown to require over fifty iterations 
 * before producing a palindrome: 
 * 4668731596684224866951378664 (53 iterations, 28-digits).
 * 
 * Surprisingly, there are palindromic numbers that are 
 * themselves Lychrel numbers; the first example is 4994.

 * How many Lychrel numbers are there below ten-thousand?

 * Project Euler: 55 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX             10000
#define ITER_MAX        50 


int isPalindrome(char *string);
char * strCopy(char *string);
int strLength(char *string);
int stringInt(char *str);
char *strrev(char *str);
int lycherl(int i);
int main();


int main()
{
        int i = 1; int count = 0;
        
        for( ; i < MAX; i++){

                printf("%d\n", i);
                if(lycherl(i)) count++;

        }

        printf("%d\n", MAX - count);


}


int lycherl(int i)
{
          
        int counter = 0; int sum;
        char *reverse;
        char *str = malloc(30 * sizeof(char));

        sprintf(str, "%d", i);

        while(!isPalindrome(str)){
                reverse = strrev(strCopy(str));
                sum = stringInt(str) + stringInt(reverse);

                if(counter > ITER_MAX) return 1;

                sprintf(str, "%d", sum);

                counter++;
        }

        return 0;

} 


int isPalindrome(char *s)
{
	int l; int i = 0;

	l = strLength(s);

	for(i = 0; i < l/2; i++){
		if ( s[i] != s[l-i-1] ) return 0; 
	}

	return 1;
}


int strLength(char *string)
{
	int i = 0;

	for( ; *string; i++)
                ;
        
        return i;
}



char * strCopy(char *string)
{
        static char copy[30];

        for(int i = 0 ; *string; copy[i++] = *string++);

        return copy;

}


int stringInt(char *str)
{
        int dec = 0;

        for( ; *str; dec = dec + 10 * *str++ - '0');

        return 0;
}
                


char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strLength(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

