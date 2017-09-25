#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRIANGLE_HEIGHT         16
#define TRIANGLE_WIDTH          16 
#define LINE_SIZE               64
#define TRIANGLE_FILE_PATH      "../res/max_path_sum_1"


void processLine(char* line, long* gridline);
void printTriangle(long*** head);
long*** initTriangle(char* path);
int main(int argc, char** argv);
void freeTriangle(long*** tri);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        long*** triangle = initTriangle(TRIANGLE_FILE_PATH);
//        printTriangle(triangle);


        freeTriangle(triangle);


        return 0;

}
        

long*** initTriangle(char* path)
{

        FILE* file;

	if(!(file = fopen(path, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}

	long** triangle = malloc(TRIANGLE_HEIGHT* sizeof(long*));
	long*** head = &triangle;

	for(int i = 0; i < TRIANGLE_HEIGHT; i++){
		triangle[i] = malloc(TRIANGLE_WIDTH* sizeof(long));
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
	for(char* tmp = line; *tmp != '\n'; tmp++){
		if(*tmp == ' '){
			*tmp = '\0';
		}
	}

	for(int i = 0; *line && *line != '\n'; i++){
		gridline[i] = strtol(line, NULL, 10);
		line += 3;
	}

	return;
}

void printTriangle(long*** head)
{
        long** tri = *head;

        while(*tri){
                long* t = *tri;
                while(*t){
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

void freeTriangle(long*** head)
{
        long** tri = *head;

        while(*tri){
                free(*tri++);
        }


}
