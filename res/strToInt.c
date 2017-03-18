/* This function simply takes char array
 * arguments and converts them to their 
 * base 10 integer equivalent. */


/* Includes */
#include <stdint.h>


/* Function Prototype */
uint64_t strToInt(char *str);

/* Convert a string to a decimal integer */
uint64_t strToInt(char *str)
{
        uint32_t dec = 0;

        for( ; *str; dec = dec * 10 + (*str++ - '0'))
                ;

        return dec;
}

