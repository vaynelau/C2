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

char s[30*1024*1025+5];
char *ps[60005];

int main(void)
{
    FILE *in = fopen("invert.in","r");
    FILE *out = fopen("invert.out","w");
    
    int n=0,i;
    char *p = s;
    while(fgets(p,2010,in)!=NULL){
        ps[n++]=p;
        p+=strlen(p)+1;
    }
    for(i=n-1;i>=0;i--){
        fputs(ps[i],out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
