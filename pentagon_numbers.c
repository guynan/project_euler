/* Find the pair of pentagonal numbers
 * for which their sum and difference are 
 * pentagonal. What is the value of their
 * difference?

 * Project Euler: 44 */

#include <stdio.h>

/* Should be less than 1000 */
#define MAX     10
#define LEN     300

int pentagons[500];

/* Prototypes */
int main();
void initPentagons();
int isPentagonal(int n);

int main()
{
        int difference = 0;

        initPentagons();

        for(int a = 0; a < MAX; a++){
                for(int b = 0; b < MAX; b++){
                        a = pentagons[a];
                        b = pentagons[b];

                        if(isPentagonal(a + b) && isPentagonal(a - b)){
                                difference = a - b ;
                                printf("%d\n", difference);
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
        long l = 0;

        for(int n = 0; pentagons[n] != '\0'; n++){
                printf("got here m8 %d\n", n);
                l = n * (3*n - 1)/2;
                pentagons[n] = l;
        }

}

int isPentagonal(int n)
{

        
        for(int i = 0; pentagons[i] != '\0'; i++){
                if(n == pentagons[i]){
                        return 1;
                }

                if(n > pentagons[i]){
                        return 0;
                }

        }

        return 0;

}

