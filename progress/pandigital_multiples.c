

/* Project Euler: 38 */

#include <stdio.h>
#include <stdlib.h>


#define MAX             987654321
#define PANDIGIT_STR    "123456789"

int main(int argc, char** argv);
int compare(void* a, void* b);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;


        /*
        for(uint32_t i = 0; i < MAX; i++){
        }
        */
}

int compare(void* a, void* b)
{
        return (*((char*)a) < *((char*)b));
}
