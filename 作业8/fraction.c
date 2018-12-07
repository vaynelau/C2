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

char s[1000000];

typedef struct frac{
    int b,c;
}frac;

int gcd(int a, int b)
{
    while(b!=0){
        int tmp = a%b;
        a=b;
        b=tmp;
    }
    return a;
}

char *start,*end;

frac getval()
{
        frac ret;
        int a,b,c;
        int flag;
        
        a=strtol(start,&end,10);
        if(a<0){
            flag=-1;
            a=-a;
        }
        else{
            flag=1;
        }
        if(*end=='.'){
            start = end+1;
            b=strtol(start,&end,10);
            start = end+1;
            c=strtol(start,&end,10);
            ret.b = flag*(a*c+b);
            ret.c = c;
        }
        else if(*end=='/'){
            start = end+1;
            c=strtol(start,&end,10);
            ret.b = flag*a;
            ret.c = c;
        }
        else{
            ret.b = flag*a;
            ret.c = 1;
        }
        start = end;
        
        int m=gcd(ret.b,ret.c);
        ret.b/=m;
        ret.c/=m;
        return ret;
}


int main(void)
{
    freopen("fraction.in","r",stdin);
    //freopen("fraction.out","w",stdout);
    gets(s);
    int l = strlen(s)-1;
    while(isspace(s[l])){
        s[l--]='\0';
    }
    start=s;
    frac result=getval();
    
    
    while(*start!='\0'){
        while(isspace(*start)) start++;
        char op=*start++;
        frac tmp=getval();
        int m,n; 
        switch(op){
            case '+':
                m=gcd(result.c, tmp.c);
                n=result.c*tmp.c/m;
                result.b = result.b*tmp.c/m + tmp.b*result.c/m;
                result.c = n;
                break;
            case '-':
                m=gcd(result.c, tmp.c);
                n=result.c*tmp.c/m;
                result.b = result.b*tmp.c/m - tmp.b*result.c/m;
                result.c = n;
                break;
            case '*':
                result.b = result.b*tmp.b;
                result.c = result.c*tmp.c;
                break;
            case '/':
                result.b = result.b*tmp.c;
                result.c = result.c*tmp.b;
                break;
        }
        m=gcd(result.b,result.c);
        result.b/=m;
        result.c/=m;
    }
    if(result.c==1){
        printf("%d\n",result.b);
    }
    else if(result.b>result.c){
        printf("%d.%d/%d\n",result.b/result.c,result.b%result.c,result.c);
    }
    else{
        printf("%d/%d\n",result.b,result.c);
    }
    return 0;
}
