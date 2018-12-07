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

typedef struct frac{
    short x,y;
} Frac;

 
Frac array[7600000];
int count = 0;
short visit[5001][5000]; 
 
int gcd(int m, int n)
{
    if(visit[m][n]){
        return visit[m][n];
    }
    
    if(m%n==0){
        visit[m][n] = n;
    } 
    else{
        visit[m][n] = gcd(n,m%n);
    }
    return visit[m][n]; 
}

int comp(const void *p, const void *q)
{
    Frac *p1 = (Frac *)p;
    Frac *q1 = (Frac *)q;
    return (int)(p1->x)*(int)(q1->y)-(int)(q1->x)*(int)(p1->y);
}

char s[100];

int main(void)
{
    int n, a, b;
    int i,j;
    char *start, *end;
    scanf("%d %s",&n,s);
    
    start = s;
    if(isdigit(*start)){
        a = strtol(start,&end,10) - 1;
        start = end+1;
    }
    else{
        a = 0;
        start++;
    }
    
    if(isdigit(*start)){
        b = strtol(start,&end,10) - 1;
    }
    else{
        b = INT_MAX;
    }
    
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++){
            if(gcd(i,j)==1){
                array[count].x = j;
                array[count].y = i;
                count++;
            }
        }
    }
    qsort(array,count,sizeof(Frac),comp);
    b = MIN(b,count-1);
    for(i=a;i<b;i++){
        printf("%d/%d ",array[i].x,array[i].y);
    }
    printf("%d/%d\n",array[i].x,array[i].y);
    return 0;
}