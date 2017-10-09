

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define MOD_MASK                10000000000


int main(int argc, char** argv);
uint64_t ipow(uint64_t base, uint64_t exp);
uint64_t modpow(uint64_t base, uint64_t exp, uint64_t modulus);



int main(int argc, char** argv)
{
        uint64_t exp = 7830457;

        uint64_t prod = 1;

        uint64_t bit = 0x1;

        while(bit){
                uint64_t k = exp & bit;
                if(k){

                        printf("%"PRIu64"\n", k);
                 
                        prod *= modpow(2, k, MOD_MASK);
                        
                        printf("%"PRIu64"\n", prod);
                        
//                        printf("%"PRIu64"\n", sum);
                } 

                bit <<= 1;

        }
        
        prod = modpow(2, exp, MOD_MASK);

        printf("prod %"PRIu64"\n", prod);

}


uint64_t ipow(uint64_t base, uint64_t exp)
{
		
        if(exp > 30){
                return ipow(base, exp / 2) % MOD_MASK * ipow(base, exp / 2) % MOD_MASK;
        }

	uint64_t result = 1;
//        printf("%"PRIu64" %"PRIu64"\n", exp, result);
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
//        printf("%"PRIu64" %"PRIu64"\n", exp, result);
        printf("res %"PRIu64"\n", result);

	return result;
}
 

uint64_t modpow(uint64_t base, uint64_t exp, uint64_t modulus)
{
	base %= modulus;
	uint64_t result = 1;

	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
                printf("%"PRIu64"\n", result);
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}
