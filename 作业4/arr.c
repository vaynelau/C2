#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

int a[200][200],b[200][200],c[200][200];

int main(void)
{
    char s[1350];
    int i,j,m=0,k=0,n=0,num;
    FILE *in = fopen("arr.in","r");
    while(fgets(s,1300,in) != NULL){
        if(sscanf(s,"%d",&num)==EOF){
            break;
        }
        k=0;
        for(i=0;i<strlen(s);i++){
            sscanf(s+i,"%d",&a[m][k]);
            k++;
            while(isdigit(s[i]) && i<strlen(s)){
                i++;
            }
            while(!isdigit(s[i]) && i<strlen(s)){
                i++;
            }
            i--;
        }
        m++;
    }
    
    for(i=0;i<k;i++){
        fgets(s,1300,in);
        n=0;
        for(j=0;j<strlen(s);j++){
            sscanf(s+j,"%d",&b[i][n]);
            n++;
            while(isdigit(s[j]) && j<strlen(s)){
                j++;
            }
            while(!isdigit(s[j]) && j<strlen(s)){
                j++;
            }
            j--;
        }
        
    }
    int l;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            for(l=0;l<k;l++){
                c[i][j]+=a[i][l]*b[l][j];
            }
            printf("%8d ",c[i][j]);
        }
        printf("\n");
    }
    fclose(in);
    
    return 0;
}
