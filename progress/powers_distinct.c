

#include <stdio.h>
#include <gmp.h>


#define MAX     100
#define LEN     10000
mpz_t powers[LEN];
register mpz_t power;
int count = 0;

int main();
void insert(mpz_t power);
int is_distinct(mpz_t power);

int main()
{
        unsigned long int a; unsigned long int b;

        for(a = 2; a <= MAX; a++){
                for(b = 2; b <= MAX; b++){
                        mpz_ui_pow_ui(power, a, b);
                        count += (is_distinct(power)) ? 1 : 0;
                }
        }
                                     
        printf("%d\n", count);

        return 0;
}
         

int is_distinct(mpz_t power)
{
        for(int i = 0; powers[i] != '\0'; i++){
                if(powers[i] == power){
                        return 0;
                }

                /* Relies on array being sorted */
                if(powers[i] < power){
                        break;
                }

                insert(power);

        }

        return 1; 
}

/* Who knows if this is efficient, I'm sleepy */
void insert(mpz_t power)
{
        int i;

        for(i = 0; power > powers[i]; i++);

        for(; powers[i] != '\0'; i++){
                powers[i+1] = powers[i];
        }
}
        
