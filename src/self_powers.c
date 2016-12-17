/* x^x for 1 <= x <= 1000
 * Find the last ten digits
 * of the sum of this series
 *
 * Answer: 9110846700 
 * Project Euler: 48 */


#include <stdio.h>
#include <gmp.h>


#define MAX 1000
mpz_t sum;
mpz_t power;
char string[4096];


int main();
int len(char *string);


int main()
{
        mpz_init(sum); mpz_init(power);

        unsigned long int i;

        for(i = 1; i <= MAX; i++){
                mpz_ui_pow_ui(power, i, i);
                mpz_add(sum, sum, power);
        }
        
        mpz_get_str(string, 10, sum); 
        int length = len(string);

        for(int c = length - 10; c <= length; c++){
                printf("%c", string[c]);
        }

        printf("\n");

        return 0;
}

int len(char *string)
{
        int i = 0;

        for(; string[i] != '\0'; i++);

        return i;
}
