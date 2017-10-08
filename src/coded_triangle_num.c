/* The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1);
 * so the first ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its
 * alphabetical position and adding these values we form a word value. For
 * example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word
 * value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt, a 16K text file
 * containing nearly two-thousand common English words, how many are triangle
 * words?
 *
 * Project Euler: 42
 *
 * Answer 162 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


#define FILE_PATH               "../res/coded_triangle_numbers"
#define FILE_BUFFER             20000
#define TRI_MAX                 50 


int validTriangleNum(uint32_t t, const uint32_t* triangles);
uint32_t* initTriangleSeq(uint32_t max);
uint32_t getWordTotal(const char* a);
uint32_t countTriangleNumbers(void);
int main(int argc, char** argv);
FILE* getFile(const char* path);
char* readWords(FILE* file);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        printf("%"PRIu32"\n", countTriangleNumbers());

        return 0;

}


uint32_t countTriangleNumbers(void)
{

        FILE* file = getFile(FILE_PATH);        
        char* words = readWords(file);
        uint32_t* tri = initTriangleSeq(TRI_MAX);

        uint32_t count = 0;

        for(int i = 0; words[i] != EOF ; i++){

                if(words[i] == '\0') continue;

                uint32_t total = getWordTotal(words + i);

                count += validTriangleNum(total, tri + 1);

                /* Get to the next word */
                while(*(words + i) != '\0') i++;

        }

        free(words);
        free(tri);

        return count;

}


uint32_t getWordTotal(const char* a)
{
        /* The ampersand character takes
         * a capital letter to being the integer 
         * representation of its alpha position */
        uint32_t sum = 0;

        for( ; *a; sum += *a++ - '@')
                ;

        return sum;
}


FILE* getFile(const char* path)
{
	FILE* file = NULL;

	if(!(file = fopen(path, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}

        return file;
}


char* readWords(FILE* file)
{
        size_t n = FILE_BUFFER;

        /* Having looked at the file, it appears there are 1786 words */
        char* words = malloc(n * sizeof(char));
        memset(words, 0, (n * sizeof(char)));

        char c;

        /* We don't want the first character */
        (void) fgetc(file); 

        for(uint32_t i = 0; i < n; i++){

                c = (char) fgetc(file);

                if(c == EOF) break;

                if(i + 1 == n){
                        n *= 2;
                        char* tmp = realloc(words, (n * sizeof(char)));

                        if(!tmp) exit(2);

                        words = tmp;
                }

                words[i] =  c;
        }

        char* tmp = words;

        /* Replace the delimeters with null characters so we can pass in 
         * addresses to substrings from the same character array */
        while(*tmp){
                *tmp = (*tmp == '"' || *tmp == ',') ? '\0' : *tmp;
                tmp++;
        }

        /* So we know when to stop iterating */
        *++tmp = EOF;

        fclose(file);

        return words;
} 


uint32_t* initTriangleSeq(uint32_t max)
{
        uint32_t* tmp = malloc(max * sizeof(uint32_t));

        for(uint32_t i = 1; i < max; i++){
                tmp[i] = (i * (i + 1)) / 2;
        }

        return tmp;
}


int validTriangleNum(uint32_t t, const uint32_t* tri)
{
        while(*tri){

                if(t == *tri) return 1;
                
                if(*tri > t) return 0;

                tri++;

        }

        return 0;

}

