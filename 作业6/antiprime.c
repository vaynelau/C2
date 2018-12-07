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

int prime[]={2,3,5,7,11,13,17,19,23,29};
int len=LEN(prime);
int count[LEN(prime)];
int n,max_divisors,max_antiprime;

void dfs(int start, int product)
{
    int i,j,tmp,divisors;
    for(i=start;i<len;i++){
        tmp = product*prime[i];
        if(tmp>n || product != tmp/prime[i]){
            divisors=1;
            for(j=0;j<=i;j++){
                divisors *= count[j]+1;
            }
            if(divisors>max_divisors || (divisors==max_divisors && max_antiprime>product)){
                max_divisors = divisors;
                max_antiprime = product;
            }
            break;
        }
        count[i]++;
        dfs(i,tmp);
        count[i]--;
    }   
}

int main(void)
{
    FILE *in = fopen("antiprime.in","r");
    FILE *out = fopen("antiprime.out","w");
    fscanf(in,"%d",&n);
    dfs(0,1);
    fprintf(out,"%d\n",max_antiprime);
    fclose(in);
    fclose(out);
    return 0;
}
