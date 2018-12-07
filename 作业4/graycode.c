#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
#include <limits.h> 

char s[100];

int main(void)
{
    int i,start;
    char tmp;
    while(scanf("%s",s) != EOF){
        if(s[1]=='g'){
            for(i=2;i<strlen(s);i++){
                if(i==2){
                    putchar(s[i]);
                }
                else{
                    putchar(((s[i-1]-'0')^(s[i]-'0'))+'0');
                }
            }  
        }
        else {
            if(s[1]=='b')
                start = 2;
            else
                start = 0;
                
            for(i=start;i<strlen(s);i++){
                if(i==start){
                    tmp = s[i];
                    putchar(tmp);
                    
                }
                else {
                    tmp = ((s[i]-'0')^(tmp-'0'))+'0';
                    putchar(tmp);
                }
            }
        }
        putchar('\n');
    }
     
    return 0;
}
