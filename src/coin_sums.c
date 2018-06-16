

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char** argv);
int32_t len(int32_t* arr);
int32_t count_permutations(int32_t* coins, int32_t total);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        static int32_t coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

        int32_t perm = count_permutations(coins, 200);

        printf("%"PRId32"\n", perm);

        return 0;

}

int32_t count_permutations(int32_t* coins, int32_t total)
{
        int32_t n = len(coins);

        int32_t* table = calloc(total + 1, sizeof(int32_t));

        table[0] = 1;

        for(int32_t i = 0; i < n; i++){
                for(int32_t j = coins[i]; j <= total; j++){
                        table[j] += table[j - coins[i]];
                }
        }

        free(table);

        return table[total];

}

int32_t len(int32_t* arr)
{
        int32_t count = 0;
        for( ; *(arr + count); count++)
                ;
        return count;
}

