#include <stdio.h>
#include <string.h>

int main()
{
    FILE *in = fopen("prz.in","r");
    int n=0;
    int a[50001],b[50001];
    while(fscanf(in, "%d %d\n", &a[n], &b[n]) != EOF){
        n++;
    }
    fclose(in);
    
    int i,j,tmp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[j]<a[i]){
                tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
                tmp=b[j];
                b[j]=b[i];
                b[i]=tmp;
            }
        }
    }
    
    int aout[50001],bout[50001],k=0;
    aout[0]=a[0],bout[0]=b[0];
    for(i=1;i<n;i++){
        if(a[i]<=bout[k]){
            if(b[i]>bout[k]){
                bout[k]=b[i];
            }
        }
        else{
            k++;
            aout[k]=a[i];
            bout[k]=b[i];
        }
    }
    
    FILE *out = fopen("prz.out","w");
    for(i=0;i<=k;i++){
        fprintf(out,"%d %d\n",aout[i], bout[i]);
    }
    fclose(out);
    return 0;   
}
