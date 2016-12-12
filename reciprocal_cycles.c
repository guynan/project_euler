/* Find the value of d < 1000 for 
 * which 1/d contains the longest recurring
 * cycle in its decimal fraction part.

 * Project Euler: 26 */

#include <stdio.h>
#include <gmp.h>

#define MAX     1000

int main();
int count(spec_type i);
spec_type inverse(int i);

int main()
{
        int longest;

        spec_type inverse;

        for(int i = 2; i <= MAX; i++){
                inverse = inverse(i);
                longest = (count(inverse) > longest) ? i : longest;
        }
                       
        printf("%d\n", longest)

        return 0;
}

int count(spec_type i)
{
        return 0;
}


spec_type inverse(int i)
{
        return 0;
}
