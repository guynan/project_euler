
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* one two three four five six seven eight nine */
int32_t ones[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4};

/* ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen
 * nineteen */
int32_t teens[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

/* twenty thirty forty fifty sixty seventy eighty ninety */
int32_t tens[] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6};


#define THOUSAND        8
#define HUNDRED         7
#define AND             3

int main(int argc, char** argv);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

	int32_t i;
	int32_t sum = 0;

	/* from 1 to 9 */
	for (i = 1; i < 10; i++) {
		sum += ones[i];
	}
	/* from 10 to 19 */
	for (i = 0; i < 10; i++) {
		sum += teens[i];
	}
	/* from 20 to 99 */
	for (i = 20; i < 100; i++) {
		sum += tens[i / 10] + ones[i % 10];
	}
	/* from 100 to 999 */
	for (i = 1; i < 10; i++) {
		int j;

		/* just i HUNDRED */
		sum += ones[i] + HUNDRED;
		/* from i HUNDRED AND one to i HUNDRED AND nine */
		for (j = 1; j < 10; j++) {
			sum += ones[i] + HUNDRED + AND + ones[j];
		}
		/* from i HUNDRED AND ten to i HUNDRED AND nineteen */
		for (j = 0; j < 10; j++) {
			sum += ones[i] + HUNDRED + AND + teens[j];
		}
		/* from i HUNDRED AND twenty to i HUNDRED AND ninety-nine */
		for (j = 20; j < 100; j++) {
			sum += ones[i] + HUNDRED + AND + tens[j / 10] + ones[j % 10];
		}
	}

	sum += ones[1] + THOUSAND;

	printf("%"PRId32"\n", sum);

	return 0;
}

