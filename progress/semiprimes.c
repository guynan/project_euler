/* A composite is a number containing at least 
 * two prime factors. For example, 15 = 3 × 5; 
 * 9 = 3 × 3; 12 = 2 × 2 × 3.

 * There are ten composites below thirty containing 
 * precisely two, not necessarily distinct, prime 
 * factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

 * How many composite integers, n < 10**8, have
 * precisely two, not necessarily distinct, prime factors?

 * Project Euler: 187 */

#include<stdio.h>
#include<math.h>


//#define MAX     100000000
#define MAX     4


/* Prototypes */
int isPrime(unsigned int s);
int hasTwoPrimeFac(int i);
int main();

int main()
{
        int counter = 0;

        for(int i = 0; i < MAX; i++){
//                counter += (hasTwoPrimeFac(i)) ? 1 : 0;
                if(hasTwoPrimeFac(i)){
                        counter++;
                        printf("%d\n", i);
                }
        }


        printf("%d\n", counter);
}


/* Detects whether int is prime */
int isPrime(unsigned int s)
{
        if (s == 0 || s == 1){
                return 0;
        }

        if (s == 2){
                return 1;
        }

        int top = (int) round(sqrt(s) +1);

        for(int i = 2; i < top+1; i++){
                if(i == top){
                        return 1;
                }

                if (s % i == 0){
                        return 0;
                }
        }

        return 0;
}


int hasTwoPrimeFac(int i)
{
        int primec = 0;

        for(int f = 1; f <= i; f++){

                /* If is a factor of... */
                if(i % f == 0){

                        /* If `f' is a prime... */
                        primec += (isPrime(f)) ? 1 : 0;
                }
                
                if(primec == 2){
                        return 1;
                }

        }

        return 0;

}

