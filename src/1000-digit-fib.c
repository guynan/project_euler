/* What is the first digit in the Fibonacci
 * sequence that will have over 1000 digits?
 *
 * Project Euler: 25
 * Answer: 4782 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <gmp.h>


/* FreeBSD : ln lib from /usr/local/lib to /usr/lib
 * && ln gmp.h from /usr/local/include to /usr/include */


#define MAX     1000
#define BASE    10


int main(int argc, char** argv);
size_t mpz_len(mpz_t i);


int main(int argc, char** argv)
{

        (void) argc;
        (void) argv;

        mpz_t first, second, term;

        mpz_init(first);
        mpz_init(second);
        mpz_init(term);

        /* Set these to one */
        mpz_set_ui(first, (uint64_t) 1);
        mpz_set_ui(second, (uint64_t) 1);

        /* Index is 3 as we set first & second to 1 */
        uint64_t index = 3;

        for( ; ; index++){

                /* term = first + second */
                mpz_add(term, first, second);

                /* Set first = second
                 * and second = term*/
                mpz_set(first, second);
                mpz_set(second, term);

                if(mpz_len(term) ==  MAX) break;
        }

        printf("%"PRIu64"\n", index);

        /* Release resources from mpz allocations */
        mpz_clears(first, second, term, NULL);

        return 0;

}


/* Find the length of a number in base `BASE` subsequently freeing the
 * resources that gmp allocates */
size_t mpz_len(mpz_t i)
{
        /* Cast to string to get length */
        char* tmp = mpz_get_str(NULL, BASE, i);

        size_t len = strlen(tmp);

        free(tmp);

        return len;
}

