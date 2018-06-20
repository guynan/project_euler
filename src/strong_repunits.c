
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define MAX             1000000000000
#define LIST_CAPACITY   64

struct _arr {
        void* contents;
        uint32_t capacity;
        uint32_t len;
};

typedef struct _arr* List;


int main(int argc, char** argv);
void list_add(List list, int64_t n);
void purge_list_assets(List list);
int inlist(List list, int64_t n);
int64_t sum_list(List list);
int intcmp(const void * a, const void * b);
List init_list(void);
int strong_repunit(int64_t n);

/* We know that every number will have at least one base repunit, this will be
 * in base n - 1). This means that we only need to search (or generate) up to
 * find at least one other repunit. I started by thinking about this in binary,
 * how to generate all of the numbers under the limit with binary repunit
 * representation. Starting with one, we do one right shift and then and or
 * with 1. This `algorithm` is the same as multiplying by the base and adding
 * one, like so;
 *
 *              i <<= 1;
 *              i |= 0x1;
 *
 * We can also deduce that we need only generate for n -> sqrt(max) since
 * that there is an exponential term in here. Adding distinct solutions to a
 * list, we may then sum this for the range */


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int64_t max = (int64_t) round(sqrt((double) MAX));

        List repunits = init_list();
        for(int64_t base = 2; base < max; base++){

                for(int64_t repunit = 1; ; repunit++){

                        if(repunit > MAX){
                                break;
                        }

                        /* There will be an overwhelming number of 1's in this
                         * set. Therefore to get rid of this problem, we don't
                         * add them at all to make the array smaller and easier
                         * to traverse. We simply add one to the result */
                        if(base != repunit - 1 && repunit != 1){

                                list_add(repunits, repunit);
                        }

                        repunit *= base;

                }

        }

        printf("%"PRId64"\n", sum_list(repunits) + 1);

        purge_list_assets(repunits);


        return 0;

}


void list_add(List list, int64_t n)
{
        if(list->len < list->capacity){
                ((int64_t*)(list->contents))[list->len++] = n;
                return;
        }

        list->capacity *= 2;
        list->contents = realloc(list->contents, list->capacity *
                                sizeof(int64_t));
        ((int64_t*)(list->contents))[list->len++] = n;

        return;

}


List init_list(void)
{
        List l = calloc(1, sizeof(struct _arr));

        l->len = 0;
        l->capacity = LIST_CAPACITY;
        l->contents = calloc(l->capacity, sizeof(int64_t));

        return l;

}

/* Remove all of the associated resources from the List objects */
void purge_list_assets(List list)
{
        free(list->contents);
        free(list);

}

int inlist(List list, int64_t n)
{
        int64_t* contents = list->contents;

        for(int64_t i = 0; i < list->len; i++){

                if(contents[i] == n){
                        return 1;
                }

        }

        return 0;

}

int64_t sum_list(List list)
{
        int64_t sum = 0;
        int64_t* arr = list->contents;

        qsort(arr, list->len, sizeof(int64_t), intcmp);

        int64_t last = -1;

        for(int64_t i = 0; i < list->len; i++){

                if(arr[i] == last){
                        continue;
                }

                last = arr[i];
                sum += last;
        }

        return sum;

}

int intcmp(const void * a, const void * b)
{
        return (*(int64_t*) a - *(int64_t*) b);
}

