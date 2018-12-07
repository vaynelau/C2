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


int main(void)
{
    //FILE *in = fopen("mb.in","r");
    //FILE *out = fopen("mb.out","w");
    char *s = "+123  -23 \n";
    char *start = s;
    char *end;
    int n=strtol(start,&end,10);
    printf("n:%d end:%s\n",n,end);
    start=end;
    n=strtol(start,&end,10);
    printf("n:%d end:%s\n",n,end);
    if(*end==' '){
        printf("md");
    }
    start=end;
    n=strtol(start,&end,10);
    printf("n:%d end:%s\n",n,end);
    //fclose(in);
    //fclose(out);    
    return 0;
}
