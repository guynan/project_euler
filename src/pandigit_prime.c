/* We shall say that an n-digit number is
 * pandigital if it makes use of all the
 * digits 1 to n exactly once. For 
 * example, 2143 is a 4-digit pandigital
 * and is also prime. What is the largest
 * pandigital prime that exists? 

 * Project Euler: 41 
 * Answer: 7652413 */


#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <inttypes.h> 
#include <math.h> 


/* The key here is noting that the greatest pandigit 1 - 9 is 987654321, 
 * though by use of the divisibility rule, by taking the sum over all the 
 * digits we note that all permutations of the maxima across 9******** and also
 * 8*******, we note that their digital sums are 45 and 36 respectively which 
 * means that they are both at least divisible by 3. Thus these can be excluded
 * from the search as for the number to be prime it must not be divisible by
 * anything aside from one and itself. Thus our search space has been cut down
 * massively and we start searching from 7654321 and decreasing each time by
 * two (as we know that our number must too be odd) we find the number */


#define MAX             7654321
#define MAX_DIGIT_LEN   9 


int main(int argc, char** argv);
int contains(char *str, int i);
int isPandigit(uint64_t i);
int isPrime(uint64_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t i;

        for(i = MAX; i > 0; i-= 2){
		if (isPandigit(i) && isPrime(i)) {
                                goto done;
                }
        }

        done:
                printf("%"PRIu64"\n", i);

        return 0;
}


/* Convoluted way of checking if the number is a pandigit */
int isPandigit(uint64_t i)
{
        
        static char str[MAX_DIGIT_LEN];

        sprintf(str, "%" PRIu64, i);

        for(int c = 1; str[c - 1] != '\0'; c++){

                /* If it contains 0, not pandigital */
                if(!(str[c - 1] - '0')) return 0;

                if(!contains(str, c)) return 0;

        }

        return 1;
        
}


int isPrime(uint64_t s)
{
        /* Theoretically shouldn't get values
         * less than zero due to type safety */
        if (s < 2) return 0;

        /* Preventing rounding errors */
        uint64_t top = (uint64_t) round(sqrt(s) + 1);

        for(uint64_t i = 2; i < top + 1; i++){

                if(i == top) return 1;

                if(s % i == 0) break;
        }

        return 0;
}



/* Iterates through string to see if it is indeed in there */
int contains(char* string, int i)
{
        for(char* tmp = string; *tmp != '\0'; ){
                if((*tmp++ - '0') == i) return 1;
        }

        return 0;
}

