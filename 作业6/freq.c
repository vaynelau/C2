#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define todigit(c)  (isdigit(c) ? (c)-'0' : 0)
#define tochar(d)   ((d) + '0')
#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))

char s[2000500];
int count[26],sum;
 
int main(void)
{
    FILE *in = fopen("freq.in","r");
    FILE *out = fopen("freq.out","w");
    int i,j,n;
    
    n=fread(s,1,2000500,in);
    for(i=0;i<n;i++){
        if(isalpha(s[i])){
            count[tolower(s[i])-'a']++;
            sum++;
        }   
    }
    
    /*
    char c;
    while((c=fgetc(in))!=EOF){
        if(isalpha(c)){
            count[tolower(c)-'a']++;
            sum++;
        } 
    }
    */
    
    /*
    while(fgets(s,2000500,in)!=NULL){
        n=strlen(s);
        for(i=0;i<n;i++){
            if(isalpha(s[i])){
                count[tolower(s[i])-'a']++;
                sum++;
            }   
        }  
    }
    */
    
    /*
    while(fscanf(in,"%s",s)!=EOF){
        n=strlen(s);
        for(i=0;i<n;i++){
            if(isalpha(s[i])){
                count[tolower(s[i])-'a']++;
                sum++;
            }   
        }
    }
    */
    
    int max,tmp;
    for(i=0;i<10;i++){
        max=-1;
        for(j=0;j<26;j++){
            if(count[j]>max){
                max=count[j];
                tmp=j;
            }
        }
        if(i==0)
            fprintf(out,"%c%d",tmp+'a',max);
        else
            fprintf(out," %c%d",tmp+'a',max);
        count[tmp]=-1;
    } 
    for(j=0;j<26;j++){
        if(count[j]==max){
            fprintf(out," %c%d",j+'a',max);
        }
    }
    fprintf(out,"\n%d",sum);  
    fclose(in);
    fclose(out);
    return 0;
}
