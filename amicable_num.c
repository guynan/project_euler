#include <stdio.h>

#define MAX     10000

int main();
int is_amicable(int n);


int main()
{
        int sum = 0;

        for(int n = 1; n < MAX; n++){
               sum += (is_amicable(n)) ? n : 0;
        }
        printf("%d\n", sum); 

        return 0;

}


int is_amicable(int n)
{
        int sum = 0; int a;
        int partner_sum = 0;

        /* Find sum of factors of n*/
        for(int i = 1; i < n; i++){
                sum += (n % i == 0) ? i : 0;
        }


        /* Find sum of factors of sum */
        for(a = 1; a < sum; a++){
                partner_sum += (sum % a == 0) ? a : 0;
        }

        return (partner_sum == n && n != a);

}

