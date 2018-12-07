#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
 
#define TO_NUM(c) (isdigit(c) ? (c)-'0' : 0)
#define TO_CH(n) ((n)+'0')

char* strrev(char* s)
{
    char* h = s;
    char* t = s;
    char ch;
    while(*t){
        t++;
    }
    t--;
    
    while(h < t) {
        ch = *h;
        *h++ = *t;
        *t-- = ch;
    }
    return s;
}

int mul(char *product, char *s1, char *s2)
{
    char tmp[1000];
    memset(tmp,0,1000);
    int carry,sum,i,j;
    int len_s1=strlen(s1),len_s2=strlen(s2);
    
    for(i=0;i<len_s1;i++){
        carry=0;
        for(j=0;j<len_s2;j++){
            sum = TO_NUM(s1[i])*TO_NUM(s2[j])+TO_NUM(tmp[i+j])+carry;
            tmp[i+j]=TO_CH(sum%10);
            carry=sum/10;
        }
        while(carry>0){
            tmp[i+j]=TO_CH(carry%10);
            carry/=10;
            j++;
        }  
    }
    strcpy(product,tmp);
    return 0;
}


int main(void)
{
    FILE *in=fopen("factor.in","r");
    int n;
    char s1[1000],s2[1000];
    fscanf(in,"%d",&n);
    fclose(in);
    
    sprintf(s1,"%d",n);
    strrev(s1);
    n--;
    while(n>0){
        sprintf(s2,"%d",n);
        strrev(s2);
        mul(s1,s1,s2);
        n--;
    }
    
    FILE *out=fopen("factor.out","w");
    int i;
    strrev(s1);
    for(i=0;i<strlen(s1);i++){
        fputc(s1[i],out);
        if((i+1)%50==0){
            fputc('\n',out);
        }
    }
    fclose(out);
    return 0;
}
