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

int n,m;
int result[22];

void comb(int len,int start)
{
    int i;
    if(len>=m){
        for(i=0;i<m-1;i++){
            printf("%d ",result[i]);
        }
        printf("%d\n",result[i]);
        return;
    }
    
    for(i=start;i<=n;i++){
        result[len]=i;
        comb(len+1,i+1);
    }
}

int main(void)
{
    scanf("%d %d",&n,&m);
    comb(0,1);
    return 0;
}
