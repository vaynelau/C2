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

short arr[8000000];
long long result[5000000];
char s[10000000];

int main(void)
{
    
    int i=0,j=0,m=0,k=0,n=0,l=0;
    FILE *in = fopen("arr.in","r");
    char *start, *end; 
    
    i=0;
    while(fgets(s,10000000,in) != NULL){
        j=strlen(s)-1;
        while(!isdigit(s[j])){
            s[j--]='\0';
        }
        start=s;
        j=0;
        while(*start != '\0'){
            arr[m*k+(i-m)*n+j]=(short)strtol(start,&end,10);
            start = end;
            j++;
        }
        if(i==0){
            n=k=j;
        }
        else if(j!=n){
            m=i;
            n=j;
        }
        i++;
    }
    m=i-k;
    
    int max_len=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            result[i*n+j]=0;
            for(l=0;l<k;l++){
                result[i*n+j]+=(long long)arr[i*k+l]*(long long)arr[m*k+l*n+j];
            }
            sprintf(s,"%lld",result[i*n+j]);
            max_len=MAX(max_len,strlen(s));
        }
    }
    max_len++;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sprintf(s,"%lld",result[i*n+j]);
            l=max_len-strlen(s);
            while(l--){
                putchar(' ');
            }
            printf("%s",s);
        }
        printf("\n");
    }
    fclose(in);
    return 0;
}
