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

int G[60][60];
int queue[60];
int inqueue[60];
int rear = -1, front = 0;

int main(void)
{
    FILE *in = fopen("collect.in","r");
    FILE *out = fopen("collect.out","w");
    int n,m,i,tmp;
    fscanf(in,"%d %d",&n,&m);
    
    for(i=1;i<=n+m;i++){
        fscanf(in,"%d",&tmp);
        while(tmp!=0){
            if(i<=n){
                inqueue[tmp]=1;
                queue[++rear]=tmp;
            }
            else{
                G[i][tmp]=1;
            }
            fscanf(in,"%d",&tmp);
        }
    }
    
    while(rear>=front){
        tmp = queue[front++];
        for(i=n+1;i<=n+m;i++){
            if(G[tmp][i]==1 && !inqueue[i]){
                inqueue[i]=1;
                queue[++rear]=i;
            }
        }
    }
    int flag = 1;
    for(i=n+1;i<=n+m;i++){
        if(!inqueue[i]){
            flag = 0;
            fprintf(out,"%d ", i);
        }
    }
    if(flag){
        fprintf(out,"%d",-1);
    }
    fclose(in);
    fclose(out);
    return 0;
}
