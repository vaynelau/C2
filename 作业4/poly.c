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

int A[105], B[105];
int C[205];
char x = 'x';

void read_poly(FILE *in, int *array)
{
    char c;
    int sign, a, n;
    c = fgetc(in);
    while(c != '\n'){   
        sign=0;
        if(c=='-'){
            sign=1;
            c=fgetc(in);
        }
        else if(c=='+'){
            c=fgetc(in);
        }
        while(c==' '){
            c=fgetc(in);
        }
        a=0;
        while(isdigit(c)){
            a = a*10+todigit(c);
            c=fgetc(in);
        }
        a = (a==0) ? 1 : a;
        a = sign ? -a : a;
        if(!isalpha(c)){
            array[0] = a;
            continue;
        }
        x=c;
        c=fgetc(in);
        n=0;
        while(isdigit(c)){
            n = n*10+todigit(c);
            c=fgetc(in);
        }
        n = (n==0) ? 1 : n;
        array[n] = a;
        while(c==' '){
            c=fgetc(in);
        }
    }
}



int main(void)
{
    FILE *in = fopen("poly.in","r");
    read_poly(in, A);
    read_poly(in, B);
    char c = fgetc(in);
    int i,j;
    if(c=='+'){
        FOR(i,0,100){
            C[i] = A[i]+B[i];
        }
    }
    else if(c=='-'){
        FOR(i,0,100){
            C[i] = A[i]-B[i];
        }
    }
    else if(c=='*'){
        FOR(i,0,100){
            FOR(j,0,100){
               C[i+j] += A[i]*B[j]; 
            }
        }
    }
    int flag=0;
    for(i=200;i>=0;i--){
        if(C[i]!=0){
            if(!flag){
                if(C[i]<0){
                    fputs("-",stdout);
                    C[i] = -C[i];
                }
                flag=1;
            }
            else{
                if(C[i]<0){
                    fputs(" - ",stdout);
                    C[i]=-C[i];
                }
                else
                    fputs(" + ",stdout);
            }
            
            if(C[i]==1 && i!=0){
                if(i!=1)
                    printf("%c%d",x,i);
                else
                    printf("%c",x);
            }
            else if(i!=0){
                if(i!=1)
                    printf("%d%c%d",C[i],x,i);
                else
                    printf("%d%c",C[i],x);
            }
            else{
                printf("%d",C[i]);
            }
        }
    }
  
    fclose(in); 
    return 0;
}
