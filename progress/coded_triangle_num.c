
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#define ARBITRARY_MAX           20000
#define FILE_PATH               "../res/coded_triangle_numbers"
#define FILE_BUFFER             10000
#define NUM_WORDS               2048
#define MAX_WORD_LEN            32
#define TRI_MAX                 50 

int main(int argc, char** argv);
char* readWords(FILE* file);
FILE* getFile(const char* path);
int validTriangleNum(uint32_t t, const uint32_t* triangles);
uint32_t* initTriangleSeq(uint32_t max);
uint32_t getWordTotal(const char* a);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        FILE* file = getFile(FILE_PATH);        
        char* words = readWords(file);
        uint32_t* tri = initTriangleSeq(TRI_MAX);
        uint32_t count = 0;

        char* tmp = *words;

        for(int i = 0; tmp[i] != EOF; i++){
                printf("%c", tmp[i]);

                if(tmp[i] == '\0') continue;

                uint32_t total = getWordTotal(tmp + i);
                /*
                printf("%s\n", (tmp + i));
                printf("%d\n", (int) total);
                */

                count += validTriangleNum(total, tri + 1);

                /* Get to the next word */
                while(*(tmp + i) != '\0') i++;

        }

        printf("%"PRIu32"\n", count);


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

char* readWords(FILE* file)
{
        size_t n = ARBITRARY_MAX;

        /* Having looked at the file, it appears there are 1786 words */
        char* words = malloc(n * sizeof(char));
        char** head = &words;
        char c = '\0';

        /* We don't want the first character */
        (void) fgetc(file); 

        for(uint32_t i = 0; i < n; i++){
                c = (char) fgetc(file);
                if(c == EOF) break;
                printf("%c", c);

                if(i + 1 == n){
                        puts("realloc");
                        n *= 2;
                        char* tmp = realloc(words, (n * sizeof(char)));
                        if(!tmp){
                                puts("OOM");
                                exit(2);
                        }
                        words = tmp;
                }
                words[i] =  c;
        }

        char* tmp = words;
        while(*tmp){
                if(*tmp == '"' || *tmp == ','){
                        *tmp = '\0';
                }

                tmp++;
        }
        *++tmp = EOF;

        return words;
} 

uint32_t* initTriangleSeq(uint32_t max)
{
        uint32_t* tmp = malloc(max * sizeof(uint32_t));
//        uint32_t** head = &tmp;

        for(uint32_t i = 1; i < max; i++){
                tmp[i] = (i * (i + 1)) / 2;
//               printf("%"PRIu32"\n", tmp[i]);
        }

        return tmp;
}

int validTriangleNum(uint32_t t, const uint32_t* tri)
{
        for(uint32_t i = 0; tri[i]; i++){

                if(t == tri[i]) return 1;
                
//                if(tri[i] < t) return 0;

        }

        return 0;

}
