
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define MAX             10000000
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

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        init_primes





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

