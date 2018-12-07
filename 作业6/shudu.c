#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define todigit(c)  (isdigit(c) ? (c)-'0' : 0)
#define tochar(d)   ((d) + '0')
#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))

int rows[10][10];
int columns[10][10];
int blocks[10][10];
int result[10][10];
FILE *in,*out;

void dfs(int n)
{
    int i,j,k;
    if(n>=81){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                fprintf(out,"%d",result[i][j]);
            }
            fprintf(out,"\n");
        }
        exit(0);
    }
    
    i=n/9,j=n%9;
    if(!result[i][j]){
        for(k=1;k<=9;k++){
            if(!rows[i][k] && !columns[j][k] && !blocks[i/3*3+j/3][k]){
                rows[i][k]=columns[j][k]=blocks[i/3*3+j/3][k]=1;
                result[i][j]=k;
                dfs(n+1);
                result[i][j]=0;
                rows[i][k]=columns[j][k]=blocks[i/3*3+j/3][k]=0;
            }
        }
    }
    else{
        dfs(n+1);
    }
}

int main(void)
{
    in = fopen("shudu.in","r");
    out = fopen("shudu.out","w");
    char buf[25];
    int i,j,k;
    for(i=0;i<9;i++){
        fgets(buf,20,in);
        for(j=0;j<9;j++){
            k=todigit(buf[j]);
            rows[i][k]=columns[j][k]=blocks[i/3*3+j/3][k]=1;
            result[i][j]=k;
        }
    }
    
    dfs(0);
    fclose(in);
    fclose(out);
    return 0;
}
