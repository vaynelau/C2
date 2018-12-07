#include <stdio.h>
#include <string.h>

int a[60005];

int main(void)
{
    int n;
    scanf("%d",&n);
    
    int i,j,k;
    for(i=2;i<=n;i++) {
        k=i;
        for(j=2;j<=k;j++){
            if(k%j==0){
                k/=j;
                a[j]++;
                j--;
            }
        }
    }
    
    int flag=0;
    for(i=2;i<=n;i++){
        if(a[i]!=0){
            if(flag==0)
                flag=1;
            else
                printf("*");
                
            if(a[i]==1)
                printf("%d",i);
            else
                printf("%d^%d",i,a[i]);
        }
    }

    return 0;
}
