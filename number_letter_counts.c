/* Includes */
#include <stdio.h>

/* Lots of header definitions */

int ones[11] =  {0,3,3,5,4,4,6,5,5,4,3};
int teen[10] =  {0,6,6,8,7,7,9,9,8};
int tens[9] =   {0,6,6,6,5,5,7,6,6};
int hundred =   7;

int main():
{
        int sum = 0;

        for(int i = 1; i < 1000; i++){
                if(i < 11){
                        sum += ones[i];
                }
                if(11 < i && i < 20){
                        sum += teen[i - 10];
                }
                if(
