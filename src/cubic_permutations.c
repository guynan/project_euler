

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define N_PERMUTATIONS          5

struct _perm {
        int32_t* repr;
        int64_t val;
        int32_t dig_sum;
        int32_t count;
};

typedef struct _perm* Perm;

struct _arr {
        void* contents;
        int32_t capacity;
        int32_t len;
};

typedef struct _arr* List;


struct _perm* create_perm(int64_t n, int32_t dig_sum);
void* permutation_in_work_set(int64_t n, List perms);
void* list_index(List perms, int32_t index);
int equal_perm(int64_t n, Perm perm);
void list_add(List perms, Perm p);
void purge_list_assets(List list);
int main(int argc, char** argv);
int64_t cube(int64_t n);
List init_list(void);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        List perms = init_list();

        Perm tmp = NULL;

        int32_t i;
        for(i = 0; tmp == NULL; i++){
                tmp = permutation_in_work_set(cube(i), perms);

                /* Reduce working set when it changes order of magnitude */
                if(i == 999){
                        purge_list_assets(perms);
                        perms = init_list();
                }
        }

        printf("%"PRId64"\n", tmp->val);

        purge_list_assets(perms);

        return 0;


}

int64_t cube(int64_t n)
{
        return n * n * n;
}

int32_t digital_sum(int64_t n)
{
        int32_t sum = 0;

        for( ; n; n /= 10){
                sum += n % 10;
        }

        return sum;
}

void* permutation_in_work_set(int64_t n, List perms)
{
        Perm perm = NULL;
        int32_t dig_sum = digital_sum(n);

        for(int32_t i = 0; (perm = list_index(perms, i)); i++){

                /* Potentially a match, but saves us checking in earnest */
                if(perm->dig_sum == dig_sum){
                        if(equal_perm(n, perm)){
                                perm->count++;

                                if(perm->count == N_PERMUTATIONS){
                                        return perm;
                                }
                        }

                }
        }
        perm = create_perm(n, dig_sum);
        list_add(perms, perm);

        return NULL;

}

struct _perm* create_perm(int64_t n, int32_t dig_sum)
{
        Perm p = malloc(sizeof(struct _perm));
        int32_t* repr = calloc(10, sizeof(int32_t));

        p->val = n;
        p->dig_sum = dig_sum;
        p->count = 1;

        for( ; n; n /= 10){
                repr[n % 10]++;
        }

        p->repr = repr;

        return p;
}

void* list_index(List perms, int32_t index)
{
        if(index > perms->len){
                return NULL;
        }

        return ((Perm*)(perms->contents))[index];
}

int equal_perm(int64_t n, Perm perm)
{
        int32_t i = 0;
        int32_t* tmp = calloc(10, sizeof(int32_t));

        for(i = 0; n; n /= 10){
                tmp[n % 10]++;
        }

        for(i = 0; i < 10; i++){
                if(tmp[i] != perm->repr[i]){
                        goto _out;
                }
        }

_out:

        free(tmp);
        return (i == 10);

}

void list_add(List perms, Perm p)
{
        if(perms->len < perms->capacity){
                ((Perm*)(perms->contents))[perms->len++] = p;
                return;
        }

        perms->capacity *= 2;
        perms->contents = realloc(perms->contents, perms->capacity * sizeof(Perm));
        list_add(perms, p);

        return;

}

List init_list(void)
{
        List l = calloc(1, sizeof(struct _arr));

        l->len = 0;
        l->capacity = 1000;
        l->contents = calloc(l->capacity, sizeof(Perm));

        return l;

}

void purge_list_assets(List list)
{
        Perm* contents = list->contents;
        for(int32_t i = 0; i < list->len; i++){
                free(contents[i]->repr);
                free(contents[i]);
        }
        free(contents);

        free(list);

}

