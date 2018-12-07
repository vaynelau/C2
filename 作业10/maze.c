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
#define LEN(a)      (sizeof(a)/sizeof(a[0]))
#define NEW(type)   (type*)malloc(sizeof(type)) 
#define NEW_N(n,type)   (type*)malloc(n*sizeof(type)) 

FILE *in;
int m,n;
int a[15][15];

int step[1000];
int l;
int visit[15][15];
int flag;

void dfs(int i,int j)
{
    if((i<0 || i>=m)||(j<0||j>=n)){
        flag=1;
        int k;
        for(k=0;k<l;k++){
            switch(step[k]){
                case 0:
                    printf("U");
                    break;
                case 1:
                    printf("D");
                    break;
                case 2:
                    printf("L");
                    break;
                case 3:
                    printf("R");
                    break;
            }
        }
        printf("\n");
        return;
    }
    int k,tmp;
    visit[i][j]=1;
    for(k=0;k<4;k++){
        tmp = (1<<k);
        if((a[i][j]&tmp)==0){
            step[l++]=k;
            switch(k){
                case 0:
                    if(!visit[i-1][j])
                        dfs(i-1,j);
                    break;
                case 1:
                    if(!visit[i+1][j])
                        dfs(i+1,j);
                    break;
                case 2:
                    if(!visit[i][j-1])
                        dfs(i,j-1);
                    break;
                case 3:
                    if(!visit[i][j+1])
                        dfs(i,j+1);
                    break;
            }
            l--;
        }
    }
    visit[i][j]=0;
}

int main(void)
{
    in = fopen("maze.in","r");
    int i = 0,j = 0;
    char c;
    while((c = fgetc(in))!=EOF){
        if(c=='\n'){
            if(j!=0){
                i++;
                n = j;
                j = 0; 
            }
            
        }
        else if(isalnum(c)){
            if(isdigit(c)){
                a[i][j]=c-'0';
            }
            else{
                a[i][j]=tolower(c)-'a'+10;
            }
            j++;
        }
    }
    if(j==0)
        m = i;
    else
        m = i+1;
    dfs(m-1,0);
    if(!flag){
        puts("NO");
    }
    fclose(in);
    return 0;
}
