#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

long long my_pow(int x,int y)
{
    long long result=1;
    while(y--){
        result*=x;
    }
    return result;
}

int main(void)
{
    int k,x,m,n;
    FILE *in = fopen("sigma.in","r");
    fscanf(in,"%d%d%d%d",&k,&x,&m,&n);
    fclose(in);
    long long sum1;
    double sum2;
    char s[20];
    
    if(x!=1){
        sum1=k*(my_pow(x,n+1)-1)/(x-1);
        sum2=(k-(double)k/my_pow(x,m))/(x-1);
        sum1+=(long long)sum2;
        sum2-=(long long)sum2;
        sprintf(s,"%.14f",sum2);
        printf("%lld%s",sum1,s+1);
    }
    else{
        sum1=k*(m+n+1);
        printf("%.14f",(double)sum1);
    }
    
    return 0;
}
