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

char s1[100],s2[100];

int flag=0;
void match(int i,int j)
{
    if(s1[i]=='\0'&&s2[j]=='\0'){
        flag=1;
        return;
    }
    
    if(s1[i]=='\0'|| flag){
        return;
    }
    
    if(s1[i]==s2[j] || s1[i]=='?'&&s2[j]!='\0'){
        match(i+1,j+1);        
    }
    else if(s1[i]=='*'){
        i++;
        while(1){
            match(i,j);
            if(s2[j]=='\0'){
                break;
            }
            j++;
        }   
    }
    
}


int main(void)
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    gets(s1);
    while(gets(s2)!=NULL){
        flag=0;
        match(0,0);
        if(flag){
            puts(s2);
        }
    }
    
    return 0;
}
