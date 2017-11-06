/* The number, 197, is called a circular prime 
 * because all rotations of the digits: 
 * 197, 971, and 719, are themselves prime.

 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

 * How many circular primes are there below one million?

 * Project Euler: 35 
 * Answer: 55 */ 


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


/* Definitions */
#define MAX             1000000
#define PRIME_C         80000 

static uint32_t result[60];
static uint32_t resc = 0;


/* Prototypes */
int in(uint32_t i, uint32_t *array);
uint32_t oneRotation(uint32_t i);
int main(int argc, char** argv);
void append(uint32_t* array);
void circulate(uint32_t i);
int isPrime(uint32_t s);


int main(int argc, char** argv)
{
        for(uint32_t i = 1; i < MAX; i+= 2){
                circulate(i);
                
        }

        int counter = 0;
        for(uint32_t i = 0 ; i < 60; i++){
                if(result[i] != 0){
                        counter++;
                }
        }

        printf("%d\n", counter + 1);

        return 0;
        
}        


/* Checks if an integer is a prime
 * in the most efficient way I know */
int isPrime(uint32_t s)
{
        if (s <= 1) return 0;

        if (s == 2) return 1;

        /* Hopefully preventing rounding errors */
        int top = (int) round(sqrt(s) + 1);

        for(int i = 2; i < top + 1; i++){
                if(i == top) return 1;

                if (s % i == 0) return 0;
        }

        return 0;
}


/* A real monty of a function:
 * We first have a look through all possible 
 * circular iterations of the integer `i`. 
 * If they are all prime numbers themselves; 
 * we chuck them in the `result` array using `append` */
void circulate(uint32_t i)
{
        uint32_t rotated, count = 0;
        uint32_t *circular = malloc(16 * sizeof(uint32_t));

        /* This is so we dont start rotating
         * one index uint32_tegers */
        if(i < 10){
                if(isPrime(i)) result[resc++] = i;
                return;
        }

        /* Do one rotation so we can enter the loop */
        rotated = oneRotation(i);

        /* Return if it isn't even a prime */
        if(!isPrime(i)){
                return;
        }

        else circular[count++] = i;
                
        /* While rotated value != i */
        while(i != rotated){

                if(isPrime(rotated)){
                        rotated = oneRotation(rotated);
                        circular[count++] = rotated;
                }

                else return;
                        
        }

        append(circular);
        free(circular);

}


uint32_t oneRotation(uint32_t i)
{
        uint32_t len = floor(log10(i));
        uint32_t first = i % 10;
        i /= 10;
        return pow(10, len) * first + i;
}


/* Inserts the items of the array into the `result` array */
void append(uint32_t* tmp)
{
        uint32_t* array = tmp;
        /* Only need to check if one item is
         * in the list to know all the circular
         * primes are indeed in the list */
        if(in(*array, result)){
                return;
        }

        int value;

        /* Inserts unordered into `result` */
        while(*array != '\0'){
                value = *array++;
                if(!in(value, result)){
                        result[resc++] = value;
                }
        }

}

/* Pretty simple search; could make this faster by
 * appending in order and be able to break earlier */
int in(uint32_t i, uint32_t* array)
{
        uint32_t* tmp = array;
        while(*tmp != '\0'){
                if(i == *tmp++) return 1;
        }

        return 0;
}

