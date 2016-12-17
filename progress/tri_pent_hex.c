/* Includes */
#include <stdio.h>

/* Definitions */
#define MAX     100000
#define LEN     400
long tri[MAX];
long pent[MAX];
long hex[MAX];
long res[LEN];

/* Prototypes */ 
int main();
void init_tri();
void init_pent();
void init_hex(int start);

int main()
{
        int index = 0;

        init_tri(); init_pent(); 

        for(int i = 0; i < MAX; i++){
                for(int a = 0; a < MAX; a++){
                        if(tri[i] == pent[a]){
                                res[index] = tri[i];
                                index++;
                        }

                        if(a > i){
                                break;
                        }
                }
        }

        int found;

        init_hex(res[0]);
        for(int i = 0; i < MAX; i++){
                for(int x = 0; res[x] != '\0'; x++){
                        if(hex[i] == res[x]){
                                found = res[x];
                                break;
                        }
                }
        }

        printf("%d\n", found);

        return 0;

                        
}

void init_tri()
{
        int t;

        for(int n = 1; n < MAX; n++){
                t = n* ((n + 1) / 2); 
                tri[n] = t;
        }
}


void init_pent()
{
        int p;
        for(int n = 1; n < MAX; n++){
                p = n* ((3*n - 1) / 2); 
                pent[n] = p;
        }
}


void init_hex(int start)
{
        int h;

        for(int n = start; n < MAX; n++){
                h = n* (2*n - 1); 
                hex[n] = h;
        }
}

