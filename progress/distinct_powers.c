/* How many distinct terms are in the 
 * sequence a^b where 2 <= a <= 100,
 * and 2 <= b <= 100 
 *
 * Project Euler: 29 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


/* Definitions */
#define MAX_A   100
#define MAX_B   100
#define MAXLEN  10000
char powers[MAXLEN];

/* Prototypes */
long len(unsigned long int list[]);
void append(mpz_t i, int count);
int inlist(mpz_t i);
void bubble_sort(long list[], long n);
int main();


int main()
{
        int count = 0;
        unsigned long long int a = 2;
        unsigned long long int b = 2;

        /* As we have a theoretical maximum 
         * of 100**100 we need to initialise
         * mpz_t ints so we don't overflow */

        mpz_t i;
        mpz_init(i);

        /*
        for (int f = 0; f < MAXLEN; f++) {
                    mpz_init2(powers[f], 1024);
        }

	extern mpz_t *powers;
	powers = malloc(MAXLEN * sizeof(mpz_t));
	mpz_array_init(*powers, MAXLEN, 1024);
        */

        /* HACK: Instead of array of mpz_t, convert all of them 
         * to char and then mpz_set_str to conv them back to mpz_t
         * and compare the ints */

        for(a = 2; a <= MAX_A; a++){
                for(b = 2; b <= MAX_B; b++){

			/* Set i = a ** b */
                        mpz_ui_pow_ui(i, a, b);
                        
                        /* Insert in list of not already */
                        if (!inlist(i)){
                                append(i, count); 
                                count++;
                        }

                }
        }

        printf("%d\n", count);

        return 0;

}                        


/* Check if i in array */
int inlist(mpz_t i)
{
        mpz_t compare;
        mpz_init(compare);
	/* Removed sorting until the
         * rest works 

        int length = len(powers);
        bubble_sort(powers, length);

	*/

        /* Temporary end cond, more efficient will be
         * to insert elements in a sorted array */

        for(long int a = 0; powers[a] != '\0'; a++){
                /* Check if in list */
                mpz_set_str(compare, powers[a], 10);
                if (compare == i){
                        return 1;
                }

                /* Assume to be sorted; if value is
                 * bigger than current item, not in 
                 * the list */

//                if (powers[a] > i){
//                        return 0;
 //               }

        } 

        return 0;
}


/* Find length of list */
long len(unsigned long int list[])
{
        long int i;

        for(i = 0; list[i] != '\0'; i++)
                ;

        return i;
}


/* Good for nearly sorted  array */
void bubble_sort(long list[], long n)
{
 	long c, d, t;
 
	for (c = 0; c < (n - 1); c++){
		for (d = 0; d < n - c - 1; d++){
			if (list[d] > list[d + 1]){
				t = list[d];
				list[d] = list[d + 1];
				list[d + 1] = t;
                        }
                }
        }
}

void append(mpz_t i, int count)
{
        /* Something along these lines */
        char * string[1024];
        mpz_get_str(string, 10, i);
        powers[count] = string;
}
