/* Find the pair of pentagonal numbers
 * for which their sum and difference are 
 * pentagonal. What is the value of their
 * difference?

 * Answer: 5482660
 * Project Euler: 44 */

#include <stdio.h>

/* Should be less than 10000 */
#define MAX     3000

long long pentagons[MAX];

/* Prototypes */
int main();
void initPentagons();
int isPentagonal(long long n);

int main()
{
        int difference; register long long k, j;

        /* k = 2167, j = 1020 */
        initPentagons();

        for(int a = 5; a < MAX; a++){
                for(int b = 5; b < MAX; b++){
                                
                        if(a == b){
                                break;
                        }

                        k = pentagons[a]; j = pentagons[b];

                        if(isPentagonal(k + j) && isPentagonal(k - j)){
                                difference = k - j ;
                                break;
                        }
                }

                if(difference != 0){
                        break;
                }
        }

        printf("%d\n", difference);

        return 0;
}

/* Initialise list of
 * pentagonal numbers */
void initPentagons()
{
        for(int n = 0; n < MAX; n++){
                pentagons[n] = (n * (3*n - 1))/2;
        }

}

int isPentagonal(long long n)
{
        
        for(int i = 0; i < MAX; i++){
                if(n == pentagons[i]){
                        return 1;
                }

                if(n < pentagons[i]){
                        return 0;
                }

        }

        return 0;

}

