/* The binomial coefficients nCk can be arranged in triangular form, Pascal's
 * triangle, like this:

 * It can be seen that the first eight rows of Pascal's triangle contain twelve
 * distinct numbers: 1, 2, 3, 4, 5, 6, 7, 10, 15, 20, 21 and 35.

 * A positive integer n is called squarefree if no square of a prime divides n. Of
 * the twelve distinct numbers in the first eight rows of Pascal's triangle, all
 * except 4 and 20 are squarefree. The sum of the distinct squarefree numbers in
 * the first eight rows is 105.

 * Find the sum of the distinct squarefree numbers in the first 51 rows of
 * Pascal's triangle.
 *
 * #203; */



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>


struct _arr {
        void* contents;
        uint32_t capacity;
        uint32_t len;
};

typedef struct _arr* List;


#define NMAX            51
#define LIST_CAPACITY   64


uint64_t sum_squarefree_combinations(uint32_t nmax);
uint64_t binomial_coeff(uint64_t n, uint64_t k);
int squarefree(uint64_t n, List sqprimes);
void list_add(List list, uint64_t n);
List generate_sqprimes(uint64_t max);
void purge_list_assets(List list);
int inlist(List list, uint64_t n);
int main(int argc, char** argv);
uint64_t sum_list(List list);
List init_list(void);
int is_prime(uint64_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu64"\n", sum_squarefree_combinations(NMAX));

        return 0;
}


uint64_t sum_squarefree_combinations(uint32_t nmax)
{
        /* The maximum value of this is approximately n / 2. Since over that
         * will only generate collisions, there is no point in checking */
        uint64_t n_items = binomial_coeff(nmax, nmax/2 + 1);

        List list = init_list();
        List primes = generate_sqprimes(n_items);

        for(uint32_t n = 1; n < nmax; n++){

                uint32_t limit = (n & 0x1) ? n / 2 + 1 : n / 2;

                for(uint32_t r = 1; r <= limit; r++){

                        uint64_t k = binomial_coeff(n, r);

                        if(squarefree(k, primes) && !inlist(list, k)){
                                list_add(list, k);
                        }

                }


        }

        uint64_t sum = sum_list(list);

        purge_list_assets(primes);
        purge_list_assets(list);

        return sum;

}

/* Iterates over our generated list of square primes and tests iteratively if
 * any of those will divide the number `n` */
int squarefree(uint64_t n, List sqprimes)
{
        uint64_t* contents = sqprimes->contents;

        for(uint32_t i = 0; i < sqprimes->len; i++){

                if(n % contents[i] == 0){
                        return 0;
                }
                /*
                if(contents[i] > n){
                        return 0;
                }
                */
        }

        return 1;

}

/* Generate the square of primes up to the max. The max is the largest possible
 * number that we could have to test. Note, we only have to search up to the
 * square of that to see if it is a factor, and only up to the square of that
 * number to test whether that number is the *square* of the prime. Taking the
 * fourth root *significantly reduces our search space */
List generate_sqprimes(uint64_t max)
{
        max = (uint64_t) round((double) sqrt(sqrt(max)));
        List primes = init_list();

        list_add(primes, 4);

        for(uint64_t i = 3; i < max; i += 2){

                if(is_prime(i)){
                        list_add(primes, i * i);

                }
        }

        return primes;

}

int is_prime(uint64_t s)
{
        if (s <= 2 || s % 2 == 0)
                return (s == 2);

        uint64_t top = (uint64_t) round((double) sqrt(s));

        for(uint64_t i = 3; i <= top; i+=2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}


uint64_t sum_list(List list)
{
        uint64_t sum = 0;
        uint64_t* arr = list->contents;

        for(uint64_t i = 0; i < list->len; i++){
                sum += arr[i];
        }

        return sum;

}


/* Calculates the binomial coefficient by cancelling the numerator and
 * denominator as it goes so that the result is *less* likely to overflow a
 * 64 bit integer */
uint64_t binomial_coeff(uint64_t n, uint64_t k)
{
	uint64_t res = 1;

	if (k > n - k){
		k = n - k;
        }

	for (uint32_t i = 0; i < k; ++i){

		res *= (n - i);
		res /= (i + 1);
	}

	return res;

}

void list_add(List list, uint64_t n)
{
        if(list->len < list->capacity){
                ((uint64_t*)(list->contents))[list->len++] = n;
                return;
        }

        list->capacity *= 2;
        list->contents = realloc(list->contents, list->capacity *
                                sizeof(uint64_t));
        ((uint64_t*)(list->contents))[list->len++] = n;

        return;

}

List init_list(void)
{
        List l = calloc(1, sizeof(struct _arr));

        l->len = 0;
        l->capacity = LIST_CAPACITY;
        l->contents = calloc(l->capacity, sizeof(uint64_t));

        return l;

}

/* Remove all of the associated resources from the List objects */
void purge_list_assets(List list)
{
        free(list->contents);
        free(list);

}

/* We *could* have inserted in order, but that ends up using up more time than
 * actually just searching what is a tiny search space */
int inlist(List list, uint64_t n)
{
        uint64_t* contents = list->contents;

        for(uint64_t i = 0; i < list->len; i++){

                if(contents[i] == n){
                        return 1;
                }

        }

        return 0;

}

