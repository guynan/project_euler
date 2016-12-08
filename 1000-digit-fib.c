/* What is the first digit in the Fibonacci
 * sequence that will have over 1000 digits?
 *
 * Project Euler: 25
 * Answer: 4782 */

/* Includes */
#include <stdio.h>
#include <gmp.h>

/* FreeBSD : ln lib from /usr/local/lib to /usr/lib 
 * && ln gmp.h from /usr/local/include to /usr/include */

/* Definitions */
#define MAX 1000
mpz_t first;
mpz_t second;
mpz_t term;

/* Prototypes */
int main();
int len(mpz_t i);

int main()
{
        /* So we can set our mpz_t to 1 */
        unsigned long int one = 1;
        

        mpz_init(term); mpz_init(first); mpz_init(second); 
        /* Set these to one */
        mpz_set_ui(first, one); mpz_set_ui(second, one);
        int i = 3;

        for( ; ; i++){

                mpz_add(term, first, second);

                /* Set first = second */
                mpz_set(first, second);
                mpz_set(second, term);

                if (len(term) ==  MAX){
                        break;
                }

        }

        gmp_printf("%Zd\n\n", term);
        printf("%d\n", i);

        return 0;

}

int len(mpz_t i)
{
        int a = 0; char strngcpy[1001];

        /* Have to cast to string to 
         * get length */
        mpz_get_str(strngcpy, 10, i);

        for( ; strngcpy[a] != '\0'; a++);

        return a;
}
