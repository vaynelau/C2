#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

int a[128];
char s[110];
int n=0;

void arrange(int len)
{
    if(len>=n){
        puts(s);
    }
    int i;
    for(i=0;i<128;i++){
        if(a[i]>0){
            s[len]=i;
            a[i]--;
            arrange(len+1);
            a[i]++;
        }
    }
}

int main(void)
{
    char c;
    while((c=getchar())!='\n'){
        a[c]++;
        n++;
    }
    arrange(0);
    return 0;
}
