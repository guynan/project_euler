/* Project Euler 13

 * This involves finding the sum of 100 50 digit numbers
 * Since we only need to find the first 10 digits of the
 * sum, I have fit the first 15 characters of the number
 * into a 64 bit integer and then summed that. 

 * Answer : 5537376230 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define FILE_PATH       "../res/large_sum.txt"
#define NUM_COUNT       100
#define LINE_LENGTH     50

int64_t * getNumbers(const char* path);
int64_t sumNumbers(int64_t *x);
int main(int argc, char** argv);

int main(int argc, char** argv)
{
        int64_t* nums = getNumbers(FILE_PATH);
        printf("%" PRIu64"\n", sumNumbers(nums));
        return 0;

}

int64_t* getNumbers(const char* path)
{

        FILE* file;

	if(!(file = fopen(path, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}


	int64_t* nums = malloc(NUM_COUNT * sizeof(int64_t));

        char* line = malloc((LINE_LENGTH + 2) * sizeof(char));

        /* Digit is 50 char long + '\n' + '\0' */
	for(int i = 0; fgets(line, LINE_LENGTH + 2, file); i++){
                line[14] = '\0';
                nums[i] = (int64_t) strtoll(line, NULL, 10);
	} 

        fclose(file);
        free(line);

	return nums;

}

int64_t sumNumbers(int64_t* x)
{
        int64_t k = 0;
        for( ; *x; k+= *x++);

        return k;
}

