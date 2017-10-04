
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#define ARBITRARY_MAX           10000
#define FILE_PATH               "../res/coded_triangle_numbers"
#define FILE_BUFFER             10000
#define NUM_WORDS               2048
#define MAX_WORD_LEN            32

int main(int argc, char** argv);
char** readWords(FILE* file);
FILE* getFile(const char* path);
uint32_t getWordTotal(const char* a);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        FILE* file = getFile(FILE_PATH);        
        char** words = readWords(file);

        printf("%d\n", (int)getWordTotal("SKY"));

        return 0;

}

uint32_t getWordTotal(const char* a)
{
        uint32_t sum = 0;
        for( ; *a; sum += *a++ - '@')
                ;
        return sum;
}


FILE* getFile(const char* path)
{
	FILE* file;

	if(!(file = fopen(path, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}

        return file;
}

char** readWords(FILE* file)
{
        size_t n = FILE_BUFFER;

        /* Having looked at the file, it appears there are 1786 words */
        char* words = malloc(NUM_WORDS * sizeof(char*));
        char** head = &words;

        while(!fgets(words, n, file)){
                puts("realloc");
                n *= 2;
                if(!realloc(words, n)){
                        puts("OOM");
                        exit(2);
                }
        }

        while(*words){
                if(*words == '"' || *words == ','){
                        *words = '\0';
                }

                words++;
        }

        return head;
} 












