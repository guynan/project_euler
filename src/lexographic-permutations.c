/* A permutation is an ordered arrangement of objects.
 * For example, 3124 is one possible permutation of 
 * the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it 
 * lexicographic order. The lexicographic permutations of 
 * 0, 1 and 2 are:

 * 012   021   102   120   201   210

 * What is the millionth lexicographic permutation 
 * of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

 * Project Euler: 24

 * Answer: 2783915460 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>


#define MAX                     1000000
#define PERM_LENGTH             11 


int main(int argc, char** argv);
void swap(char* a, char* b);
void strrev(char *str);
void permute(char* a);


int main(int argc, char** argv)
{

        (void) argc;
        (void) argv; 

        char* a = calloc(PERM_LENGTH, sizeof(char));
        strncpy(a, "0123456789", PERM_LENGTH);

        /* Please don't ask me why it is max - 1 */
        for(uint32_t i = 0; i < MAX - 1; i++){
                permute(a);
        }

        printf("%s\n", a);

        return 0;

}


void swap(char* a, char* b)
{
        char tmp = *b;
        *b = *a;
        *a = tmp;

        return;
}


/* Generate the next lexographic permutation */
void permute(char* a)
{
        size_t len = strlen(a);

        uint32_t kmax = (uint32_t) -1;

        /* Find the largest index k such that a[k] < a[k + 1]. If no index
         * exists, then this is the last permutation */
        for(uint32_t k = 0; k < len - 1; k++){
                if(a[k] < a[k + 1]){
                        kmax = k;
                }

        }


        /* Last permutation */
        if(kmax == (uint32_t) -1){
                return;
        }

        uint32_t lmax = 0;
        /* Find the largest index `l` greater than k such that a[k] < a[l] */
        for(uint32_t l = 0; l < len; l++){
                if(a[kmax] < a[l]){
                        lmax = l;
                }
        }

        /* Swap elements a[kmax] and a[lmax] */
        swap(a + kmax, a + lmax);

        /* Reverse the elements in the proceeding string past a[kmax] */
        strrev(a + kmax + 1);

}


/* Reverses a string in the assumption that there are distinct characters */
void strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return;

      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return;
}

