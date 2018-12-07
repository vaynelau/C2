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

char *str[100005];

int comp(const void *p1,const void *p2){
    return strlen(*(char **)p2) - strlen(*(char **)p1);
}

int main(void)
{
    freopen("nth.in","r",stdin);
    freopen("nth.out","w",stdout);
    gets(s);
    n=strtol(s,(char**)NULL,10);
    int i;
    for(i=0;gets(s)!=NULL;i++){
        str[i]=NEW_N(strlen(s)+1,char);
        strcpy(str[i],s);
    }
    qsort(str,i,sizeof(char *),comp);
    int j,k=0;
    for(j=0;j<i;j++){
        if(j==i-1 || strlen(str[j])!=strlen(str[j+1])){
            k++;
            if(k==n){
                puts(str[j]);
                break;
            }
        }
    }
    return 0;
}
