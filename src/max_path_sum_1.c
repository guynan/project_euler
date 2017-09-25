/* Project Euler 18 
 *
 * Answer : 1074
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRIANGLE_HEIGHT         15
#define TRIANGLE_WIDTH          15
#define LINE_SIZE               64
#define TRIANGLE_FILE_PATH      "../res/max_path_sum_1"
#define MAX(a, b)               

typedef long*** tri_ptr;

void processLine(char* line, long* gridline);
void lineSums(long* upper, long* lower);
tri_ptr initTriangle(const char* path);
long maxPathSum(tri_ptr triangle);
void printTriangle(tri_ptr head);
int main(int argc, char** argv);
void freeTriangle(tri_ptr tri);
long max(long a, long b);
void printline(long* t);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        tri_ptr triangle = initTriangle(TRIANGLE_FILE_PATH);

        printf("%li\n", maxPathSum(triangle));

        return 0;

}

void printline(long* t)
{
        for( ; *t; printf("%li ", *t++));
        puts("");
}
        
long maxPathSum(tri_ptr head)
{
        long** triangle = *head;

        long* upper; long* lower;

        
        for(int i = 0; i < TRIANGLE_HEIGHT - 1; i++){
                lower = triangle[TRIANGLE_HEIGHT -1 -i]; 
                upper = triangle[TRIANGLE_HEIGHT -2 -i]; 
                lineSums(upper, lower);
        }

        return **triangle;

}

void lineSums(long* upper, long* lower)
{
        for(int i = 0; i < TRIANGLE_WIDTH; i++){
                if(!upper[i]) break;
                upper[i] += max(lower[i], lower[i + 1]);
        }
}

tri_ptr initTriangle(const char* path)
{

        FILE* file;

	if(!(file = fopen(path, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}

	long** triangle = malloc((TRIANGLE_HEIGHT + 1)* sizeof(long*));
	tri_ptr head = &triangle;

        triangle[TRIANGLE_HEIGHT] = NULL;

	for(int i = 0; i < TRIANGLE_HEIGHT; i++){
		triangle[i] = malloc((TRIANGLE_WIDTH + 1)* sizeof(long));
                triangle[i][TRIANGLE_HEIGHT] = '\0';
	}

        /* Line Size must be bigger than triangle width
         * as it includes the char spaces */
	char* line = malloc(LINE_SIZE * sizeof(char));

	for(int i = 0; fgets(line, LINE_SIZE, file); i++){
		processLine(line, triangle[i]);
	} 

        free(line);
        fclose(file);

	return head;

}

void processLine(char* line, long* gridline)
{
	/* Null terminate all the spaces such that we
	 * can pass in pointers to the string directly */
	for(char* tmp = line; *tmp && *tmp != '\n'; tmp++){
		if(*tmp == ' '){
			*tmp = '\0';
		}
	}

	for(int i = 0; *line && *line != '\n'; i++){
		gridline[i] = strtol(line, NULL, 10);
//                printf("%li\n", gridline[i]);
		line += 3;
	}

	return;
}

/*
void printTriangle(tri_ptr head)
{
        long** tri = *head;

        while(*(tri + 1)){
                long* t = *tri;
                while(*t){
                        if(!t) return;
                        if(*t < 10){
                                printf("0%li ", *t++);
                                continue;
                        }

                        printf("%li ", *t++);
                }

                printf("\n");
                tri++;
        }
}
*/

void printTriangle(tri_ptr head)
{
        long** tri = *head;

        for(int i = 0; i < TRIANGLE_HEIGHT; i++){
                long* t = tri[i];
                for(int j = 0; j < TRIANGLE_WIDTH; j++){

                        if(!t[j]) continue;

                        if(t[j] < 10){
                                printf("0%li ", t[j]);
                                continue;
                        }

                        printf("%li ", t[j]);
                }

                printf("\n");
        }
}

void freeTriangle(tri_ptr head)
{

        while(*head){
                free(*head++);
        }


}

long max(long a, long b)
{
        return (a > b) ? a : b;
}


