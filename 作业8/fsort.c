#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))
#define LEN(a)      (sizeof(a)/sizeof(a[0]))
#define NEW(type)   (type*)malloc(sizeof(type)) 
#define NEW_N(n,type)   (type*)malloc(n*sizeof(type)) 

char s[2048];
int n;
int cnt=0;

char *str[10000005];

int comp(const void *p1,const void *p2){
    return strcmp(*(char **)p1,*(char **)p2);
}

int main(void)
{
    freopen("fsort.in","r",stdin);
    gets(s);
    n=strtol(s,(char**)NULL,10);
    int i;
    for(i=0;gets(s)!=NULL;i++){
        str[i]=NEW_N(strlen(s)+1,char);
        strcpy(str[i],s);
    }
    if(i>=n){
        qsort(str,i,sizeof(char *),comp);
        puts(str[n-1]);
    }
    else{
        puts("error");
    }
    return 0;
}
