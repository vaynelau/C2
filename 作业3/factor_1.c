#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
#define TO_NUM(c) ((c)-'0')
#define TO_CH(n) ((n)+'0')
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX_S(s1, s2) (strlen(s1) > strlen(s2) ? (s1) : (s2))

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


int add(char *sum, char *s1, char *s2)
{
    char tmp[1000];
    memset(tmp,0,1000);
    int carry=0,i;
    int max_len = MAX(strlen(s1), strlen(s2));
    int min_len = MIN(strlen(s1), strlen(s2));
    char *max_s = MAX_S(s1, s2);
    
    for(i=0;i<min_len;i++){
        tmp[i]=TO_CH((TO_NUM(s1[i])+TO_NUM(s2[i])+carry)%10);
        carry=(TO_NUM(s1[i])+TO_NUM(s2[i])+carry)/10; 
    }
    for(;i<max_len;i++){
        tmp[i]=TO_CH((TO_NUM(max_s[i])+carry)%10);
        carry=(TO_NUM(max_s[i])+carry)/10; 
    }
    while(carry>0){
        tmp[i++]=TO_CH(carry%10);
        carry/=10;
    }
    tmp[i]='\0';
    strcpy(sum,tmp);
    return 0;
}


int mul(char *product, char *s1, char *s2)
{
    char tmp[1000],pro_tmp[1000];
    memset(pro_tmp,0,1000);
    int carry=0,i,j;
    int len_s1=strlen(s1),len_s2=strlen(s2);
    
    for(i=0;i<len_s1;i++){
        carry=0;
        memset(tmp,0,1000);
        memset(tmp,'0',i);
        for(j=0;j<len_s2;j++){
            tmp[i+j]=TO_CH((TO_NUM(s1[i])*TO_NUM(s2[j])+carry)%10);
            carry=(TO_NUM(s1[i])*TO_NUM(s2[j])+carry)/10;
        }
        while(carry>0){
            tmp[i+j]=TO_CH(carry%10);
            j++;
            carry/=10;
        }
        tmp[i+j]='\0';
        add(pro_tmp,tmp,pro_tmp);
    }
    strcpy(product,pro_tmp);
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
        n--;
        mul(s1,s1,s2);
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
