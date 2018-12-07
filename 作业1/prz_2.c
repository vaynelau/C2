#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
char array[2000005];

int main(void)
{
    FILE *in = fopen("prz.in","r");
    FILE *out = fopen("prz.out","w");
    
    int a,b;
    
    while(fscanf(in, "%d %d", &a, &b) == 2){
        memset(array+2*a,-1,2*b-2*a+1);
    }
    fclose(in);
    
    int i=0;
    for(i=0;i<2000005;i++){
        if(array[i]!=0){
            a=i;
            while(array[i]!=0){
                i++;    
            }
            b=--i;
            fprintf(out,"%d %d\n",a/2,b/2);
        }
    }
    
    fclose(out);
    return 0;
}
