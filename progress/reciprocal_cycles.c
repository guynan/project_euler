/* Find the value of d < 1000 for 
 * which 1/d contains the longest recurring
 * cycle in its decimal fraction part.

 * Project Euler: 26 */

#include <stdio.h>
#include <gmp.h>

#define MAX             1000
#define STR_LEN         1000

int main();
int count(spec_type i);
mpf_t inverse(int i);

int main()
{
        int longest;

        mpf_t inv;

        for(int i = 2; i <= MAX; i++){

                /* Skip a couple of low hanging fruit */ 
                if(!(i % 2 || i % 3 || i % 5)) continue;

                inv = inverse(i);
                longest = (count(inverse) > longest) ? i : longest;
        }
                       
        printf("%d\n", longest)

        return 0;
}

int count(mpf_t i)
{
        char *strcp = malloc(STRLEN * sizeof(char));
        char *recip = malloc(STRLEN * sizeof(char));

        /* Don't know if this is the method */
        gmp_get_str(strcp, 10, i);
        for( ; *strcp; ){

                        
        return 0;
}


mpf_t inverse(int i)
{
        return 0;
}
