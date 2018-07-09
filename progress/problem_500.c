
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define         BASE    2
#define         EXP     500500
#define         MODMASK 500500507

uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t m);
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m);
int main(int argc, char **argv);
int is_prime(int32_t s);

/* This method I got from thinking about highly composite numbers after
 * watching a numberphile video. In this instance, we want the smallest number
 * with the greatest number of divisors. This is, in effect, the definition for
 * a highly composite number. These numbers have a series of properties;
 *
 * First; the prime factorisation must be of consecutive primes,
 *
 * Secondly, the powers of the exponents must be weakly decreasing,
 *
 * Thirdly, the powers must not end with a squared term (unless it is 4 or 36),
 * which I hazard a guess that it is not.
 *
 * From this notion, we can use the divisor formula for highly composite
 * numbers;
 *
 * Given the prime factorisation of the number n is a prime raised to a power,
 *
 * The number of divisors can be calculated as the product of these powers + 1.
 *
 * If we denote each of these powers as c1, c2, ... ck;
 *
 * We know now now that 2**500500 = (c1 + 1) * (c2 + 1) * ... (ck + 1)
 *
 * That is still largely unhelpful since that there are ridiculous numbers of
 * these permutations of these numbers. We know the mod mask must allow us to
 * keep this under 500500507, which conveniently fits in 32 bits and the
 * largest value we could have to handle is roughly twice this, which makes
 * calculations much easier.
 *
 * We now look to solutions to numbers where the number of divisors is the
 * power of a two to see if we can find a pattern.
 *
 * Looking at the 20th highly composite number, we notice that we have 64
 * divisors. 2**6 = 64. We can see that for even powers of two that it is
 * raised to, the power that in the factorisation, 2 is raised to the power of
 * half the factorisation. This means that we can reduce this problem
 * significantly, only providing the necessity to find the solution to
 *
 * 2**500500 = (250250 + 1) * (c2 + 1) ... * (ck + 1)
 *
 * Additionally, we know that all subsequent powers must be weakly descending
 * and since that the modular function is multiplicative, we can say that
 *
 * 2 ** 500500 mod 500500507 == (c1 + 1) * (c2 + 1) .. (ck + 1) mod 500500507
 *
 * Once we provide the result to this, we will have to solve the prime
 * factorisation using the powers that we have gleaned from this calculation
 *
 * Additionally, we can use the Omega estimate for number of distinct prime
 * factors to infer an approximation of how many distinct prime factors we will
 * need.
 *
 * omega(n) ~ log log n;
 *
 * in Base 2, the factorisation of 2*500500 will yield approximately 20
 * distinct prime factors... wow that is so few, to take part of the estimation
 * out of this result and to normalise for all likeliness in this probability
 * distribution, we will square this result to attain a reasonable upper bound
 * for numbers that we will require.
 *
 * Just for a notion of magnitude, 2**500500 ~ 10 ** 150000 using;
 *
 * 500500 log(2) / log(10)
 *
 * */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;


        uint64_t mod_divis_count = pow_mod(BASE, EXP, MODMASK);
//        printf("%"PRIu64"\n",pow_mod(BASE, EXP, MODMASK));
        printf("%"PRIu64"\n",pow_mod(BASE, EXP/2 - 1, MODMASK));



}

int is_prime(int32_t s)
{
	int32_t res = !(s <= 2 || (s & 0x1) != 1);
	int32_t top = (int32_t) round(sqrt((float)s));

	for (int32_t i = 3; res && i <= top; i += ((res = !(s % i == 0)), 2)) ;

	return (res || s == 2);
}

uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t m)
{
	uint64_t r = m == 1 ? 0 : 1;
	while (b > 0) {
		if (b & 1)
			r = mul_mod(r, a, m);
		b = b >> 1;
		a = mul_mod(a, a, m);
	}
	return r;
}

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
	long double x;
	uint64_t c;
	int64_t r;
	if (a >= m)
		a %= m;
	if (b >= m)
		b %= m;
	x = a;
	c = x * b / m;
	r = (int64_t) (a * b - c * m) % (int64_t) m;
	return r < 0 ? r + m : r;
}

