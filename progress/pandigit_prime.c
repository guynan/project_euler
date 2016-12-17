/* NOT DONE */

/* We shall say that an n-digit number is
 * pandigital if it makes use of all the
 * digits 1 to n exactly once. For 
 * example, 2143 is a 4-digit pandigital
 * and is also prime. What is the largest
 * pandigital prime that exists? 
 * Project Euler: 41 */

/* Includes */
#include <stdio.h> 

/* Definitions */
#define START   2143 /* Skip a couple */
static int long long MAX = 999999999;
static int integers[10] = {1,2,3,4,5,6,7,8,9};

/* Protoypes */
int is_pandigit(long int i);
int len(long int i);
int isprime(long s);
int main();

int main()
{
        unsigned long int i;
        unsigned long int longest = 0;

        if (is_pandigit(12345)){
                printf("is pandigit\n");
        } else {
                printf("is not pandigit\n");
        }

/*
        for(i = 0; i < MAX; i++){
		if (is_pandigit(i)) {

//                        printf("%li\n",i);

			if (isprime(i)){
                                longest = i;
			}
                }
        }
*/

//        printf("longest %li", longest);

        return 0;
}

int len(long int i)
{
        /* Convert int to str */
        char copy[9]; int a;

        sprintf(copy, "%li", i);
        for(a = 0; copy[a] != '\0'; a++)
                ;

        return a;

}

/* Convoluted way of checking if
 * the number is a pandigit */
int is_pandigit(long i)
{
        int found; /* Boolean */

        int length = len(i);	
        char copy[9]; int curr;
        int total; 
        int contains = 0; /* Boolean */

        /* Generate string copy of the 
         * digit so you can iterate over 
         * the values in array */
        sprintf(copy, "%lli", i);

        for(curr = 0; curr < length + 1; curr++){
                for(int f = curr; f < (length); f++){
                        found = 0;
                        int nonascii = (copy[f] - 48);

                        if (nonascii == curr){
                                found = 1;
                        }

                        total += found;
                }

        }
        
        if (total == length){
                contains = 1;
        }


        return contains;
        
}

/* Detect whether s is prime */
int isprime(long s)
{
        int isprime = 0; /* False */

        for(int i = 2; i < s+1; i++){
                if (s % i == 0){
                        break;
                }

                if(i == s){
                        isprime = 1; /* True */
                        break; 
                }

        }

        return isprime;
}
