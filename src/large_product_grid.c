#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE       20
#define FILE_PATH       "../res/large_product_grid"
#define LINE_SIZE	64
#define MAX(x,y)	((x) > (y) ? (x) : (y))
			

void maxDirectionalProduct(long*** gridptr, long *max, int x, int y);
long diagonalDownProduct(long*** gridptr, int x, int y);
long verticalProduct(long*** gridptr, int x, int y);
long horizontalProduct(long* gridLine, int index);
void processLine(char* line, long* gridline);
long maxProduct(long*** gridptr);
int main(int argc, char** argv);
long*** initGrid(FILE* file);

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

	FILE* file;

	if(!(file = fopen(FILE_PATH, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}

	long*** gridptr = initGrid(file);

	printf("%li\n", maxProduct(gridptr));

	return 0;

}	

long*** initGrid(FILE* file)
{
	long** grid = malloc(GRID_SIZE * sizeof(long*));
	long*** gridHead = &grid;

	for(int i = 0; i < GRID_SIZE; i++){
		grid[i] = malloc(GRID_SIZE * sizeof(long));
	}

	char* line = malloc(LINE_SIZE * sizeof(char));

	for(int i = 0; fgets(line, LINE_SIZE, file); i++){
		processLine(line, grid[i]);
	}

	return gridHead;

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

long maxProduct(long*** gridptr)
{
	long** grid = *(gridptr);

	long max = 0; 

	for(int y = 0; y < GRID_SIZE; y++){
		for(int x = 0; x < GRID_SIZE; x++){
			maxDirectionalProduct(gridptr, &max, x, y);
		}
	}

	return max;

}


long horizontalProduct(long* gridLine, int index)
{
	long prod = 1;

	if(!(index + 4 < GRID_SIZE)) return prod;

	for(int i = 0 ; i < 4; i++){
		prod *= gridLine[index + i];
	}

	return prod;

}


/* For constant x sum over 4 vertically adjacent values */
long verticalProduct(long*** gridptr, int x, int y)
{
	long** grid = *(gridptr);

	long prod = 1;

	if(!(y + 4 < GRID_SIZE)) return prod;

	for(int i = 0 ; i < 4; i++){
		prod *= grid[y + i][x];
	}

	return prod;

}

long diagonalDownProduct(long*** gridptr, int x, int y)
{
	if(!(x + 4 < GRID_SIZE) || !(y + 4 < GRID_SIZE)) return 1;

	long prod = 1;
	long** grid = *(gridptr);
	
	for(int i = 0; i < 4; i++){
		prod *= grid[y + i][x + i];
	}

	return prod;

}

long diagonalUpProduct(long*** gridptr, int x, int y)
{
	if((x - 4 < 0) || (y + 4 > GRID_SIZE)) return 1;

	long prod = 1;
	long** grid = *(gridptr);
	
	for(int i = 0; i < 4; i++){
		prod *= grid[y + i][x - i];
	}

	return prod;

}
	

void maxDirectionalProduct(long*** gridptr, long *max, int x, int y)
{
	
	long** grid = *(gridptr);
	long hz, vert, diagUp, diagDown;
	hz = horizontalProduct(grid[y], x);
	vert = verticalProduct(gridptr, x, y);
	diagDown = diagonalDownProduct(gridptr, x, y);
	diagDown = diagonalUpProduct(gridptr, x, y);

	*max = MAX(hz, *max);
	*max = MAX(vert, *max);
	*max = MAX(diagDown, *max);
	*max = MAX(diagDown, *max);

	return;

}


