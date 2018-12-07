#include <stdio.h>


int main(void)
{
    int n;
    scanf("%d",&n);
    n*=100;
    
    int i,count=0;
    for(i=0;i<=n;i+=5){
        count+=(n-i)/2+1;
    }
    printf("%d\n",count);
     
    return 0;
}
