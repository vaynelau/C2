#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

int a[401][201],c[200][200];

int main(void)
{
    char s[1350];
    int i,j,m,k,n;
    FILE *in = fopen("arr.in","r");
    char *start, *end; 
    
    i=0;
    while(fgets(s,1300,in) != NULL){
        j=strlen(s)-1;
        while(!isdigit(s[j])){
            s[j--]='\0';
        }
        start=s;
        j=0;
        while(*start != '\0'){
            a[i][j]=strtol(start,&end,10);
            start = end;
            j++;
        }
        if(i==0){
            k=j;
        }
        i++;
    }
    n=j;
    m=i-k;
    
    int l;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            for(l=0;l<k;l++){
                c[i][j]+=a[i][l]*a[m+l][j];
            }
            printf("%-11d ",c[i][j]);
        }
        printf("\n");
    }
    fclose(in);
    
    return 0;
}
