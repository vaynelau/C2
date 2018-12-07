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
#define MIN_3(a,b,c)    ((a) < MIN(b,c) ? (a) : MIN(b,c))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))


int s[2005][2005];
int a,n,m;

int main(void)
{
    FILE *in = fopen("squares.in","r");
    FILE *out = fopen("squares.out","w");
    int i,j;
    char buf[3000];
    fscanf(in,"%d",&a);
    n=0;
    while(fscanf(in,"%s",buf)!=EOF){
        m=0;
        for(i=0;i<strlen(buf);i++){
            if(buf[i]=='1' || buf[i]=='0'){
                s[n][m++]=todigit(buf[i]);
            }
        }
        n++;
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(s[i][j]==1){
                s[i][j]=MIN_3(s[i-1][j],s[i][j-1],s[i-1][j-1])+1;
            }
        }
    }
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s[i][j]>=a){
                count++;
            }
        }
    }
    fprintf(out,"%d",count);
    fclose(in);
    fclose(out);    
    return 0;
}
