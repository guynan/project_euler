/* The first known prime found to exceed one million digits was discovered in
 * 1999, and is a Mersenne prime of the form 269725931; it contains exactly
 * 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p1, have
 * been found which contain more digits.
 *
 * However, in 2004 there was found a massive non-Mersenne prime which contains
 * 2,357,207 digits: 28433×27830457+1.
 *
 * Find the last ten digits of this prime number.
 *
 * Project Euler: 97
 *
 * Answer: 8739992577 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MOD_MASK                10000000000
#define EXP                     7830457 


typedef unsigned __int128 uint128_t;

int main(int argc, char** argv);
uint128_t modex(uint128_t base, uint128_t exp, uint128_t modulus);

int main(int argc, char** argv)
{
        uint128_t prod = 28433 * modex(2, EXP, MOD_MASK) + 1;
        prod %= MOD_MASK;

        printf("%"PRIu64"\n", (uint64_t) prod);

}


uint128_t modex(uint128_t base, uint128_t exp, uint128_t modulus)
{
	base %= modulus;

	uint128_t res = 1;

	while (exp) {
		if (exp & 1) res= (res * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}

	return res;
}

