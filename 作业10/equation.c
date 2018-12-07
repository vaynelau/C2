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

FILE *in;
char s[1005];

int a[60][60];
int n;

void swap(int i, int j){
    int k;
    for(k=0;k<n+1;k++){
        int tmp = a[i][k];
        a[i][k]=a[j][k];
        a[j][k]=tmp;
    }
}


int gcd(int a,int b){
    while(b!=0){
        int tmp = a%b;
        a=b;
        b=tmp;
    }
    return a;
}

void add(int i, int j){
    int k;
    int tmp = gcd(abs(a[i][i]),abs(a[j][i]));
    int tmp1 = a[i][i]/tmp;
    int tmp2 = a[j][i]/tmp;

    for(k=0;k<n+1;k++){
        a[j][k] = a[j][k]*tmp1-a[i][k]*tmp2;
    }
}


int main(void)
{
    in = fopen("equation.in","r");
    
    for(n=0;fgets(s,1005,in)!=NULL;n++){
        int l=strlen(s)-1;
        while(isspace(s[l])){
            s[l--]='\0';
        }
        char *start=s;
        char *end;
        int i=0;
        do{
            a[n][i++]=strtol(start,&end,10);
            start=end; 
        }while(*end!='\0');
    }
    int i;
    int j;
    for(i=0;i<n;i++){
        if(a[i][i]==0){
            for(j=i+1;j<n;j++){
                if(a[j][i]!=0){
                    swap(i,j);
                    break;
                }
            }
        }
        for(j=0;j<n;j++){
            if(j==i)
                continue;
            if(a[j][i]!=0){
                add(i,j);
            }
        }
    }
    
    for(i=0;i<n;i++){
        printf("%.2f ",(double)a[i][n]/a[i][i]);
    }
    
    fclose(in);
    return 0;
}
