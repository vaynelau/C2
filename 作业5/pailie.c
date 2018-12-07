#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
#include <limits.h> 

#define todigit(c)  (isdigit(c) ? (c)-'0' : 0)
#define tochar(d)   ((d) + '0')
#define FOR(i,m,n)  for(i=m; i<n; i++)
#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))

int n,m;
int result[12],visit[12];

void pailie(int d)
{
    int i;
    if(d>=m){
        for(i=0;i<d-1;i++){
            printf("%d ",result[i]);
        }
        printf("%d\n",result[i]);
        return;
    }    
    for(i=1;i<=n;i++){
        if(!visit[i]){
            result[d]=i;
            visit[i]=1;
            pailie(d+1);
            visit[i]=0;
        }
    }
    
}

int main(void)
{
    scanf("%d %d",&n,&m);
    pailie(0);
    return 0;
}
