#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>


char filename[1024];
 
int main(void)
{
    gets(filename);
    FILE *in=fopen(filename, "r");
    int addr,n;
    while(scanf("%d",&addr)!=EOF){
        fseek(in,addr,SEEK_SET);
        char c;
        while((c=getchar())!=',');
        scanf("%d",&n);
        while(!isalpha(c=getchar()));
        int size=1;
        switch(c){
            case 'b':
                size=1;
                break;
            case 'h':
                size=2;
                break;
            case 'w':
                size=4;
                break;
            case 'd':
                size=8;
                break;
            default:
                break;
        }
        void *data=malloc(size*n);
        fread(data, size, n, in);
        while(!isalpha(c=getchar()));
        int i,j,k,l;
        char s[1000];
        switch(c){
            case 'b':
                for(i=0;i<n*size;i++){
                    int tmp = ((char *)data)[i];
                    k=0;
                    for(k=0;k<8;k++){
                        s[k] = tmp&1;
                        tmp>>=1;
                    }
                    for(l=k-1;l>=0;l--){
                        printf("%d ",s[l]);
                    }
                }
                break;
            case 'c':
                for(i=0;i<size*n;i++){
                    printf("%c ",((char *)data)[i]);
                }
                break;
            case 'd':
                switch(size){
                case 1:
                    for(i=0;i<n;i++){
                        printf("%d ",((char *)data)[i]);
                    }
                    break;
                case 2:
                    for(i=0;i<n;i++){
                        printf("%d ",((short *)data)[i]);
                    }
                    break;
                case 4:
                    for(i=0;i<n;i++){
                        printf("%d ",((int *)data)[i]);
                    }
                    break;
                case 8:
                    for(i=0;i<n*2;i++){
                        printf("%d ",((int *)data)[i]);
                    }
                    break;
                default:
                    break;
                }
                break;
            case 'o':
                switch(size){
                case 1:
                    for(i=0;i<n;i++){
                        printf("%o ",((char *)data)[i]);
                    }
                    break;
                case 2:
                    for(i=0;i<n;i++){
                        printf("%o ",((short *)data)[i]);
                    }
                    break;
                case 4:
                    for(i=0;i<n;i++){
                        printf("%o ",((int *)data)[i]);
                    }
                    break;
                case 8:
                    for(i=0;i<n*2;i++){
                        printf("%o ",((int *)data)[i]);
                    }
                    break;
                default:
                    break;
                }
                break;
            case 'x':
                switch(size){
                case 1:
                    for(i=0;i<n;i++){
                        printf("%x ",((char *)data)[i]);
                    }
                    break;
                case 2:
                    for(i=0;i<n;i++){
                        printf("%x ",((short *)data)[i]);
                    }
                    break;
                case 4:
                    for(i=0;i<n;i++){
                        printf("%x ",((int *)data)[i]);
                    }
                    break;
                case 8:
                    for(i=0;i<n*2;i++){
                        printf("%x ",((int *)data)[i]);
                    }
                    break;
                default:
                    break;
                }
                break;
               
            default:
                break;
        }
        putchar('\n');
    }
    fclose(in);
    return 0;
}

