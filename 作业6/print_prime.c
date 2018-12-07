int prime[10000]={2};
int l=1;

void print_prime()
{
    int i,j,flag;
    for(i=3;i<10000;i+=2){
        flag=1;
        for(j=0;j<l && prime[j]*prime[j]<=i;j++){
            if(i%prime[j]==0){
                flag=0;
                break;
            }
        }
        if(flag){
            prime[l++]=i;
        }   
    }
}
