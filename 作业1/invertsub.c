#include <stdio.h>
#include <string.h>

void __strrev(char *s, int i, int j)
{
    char c;
    while(i<j){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
        i++;
        j--;
    }
}


int main(void)
{
    FILE *in, *out;
    char s[100], t[100];
    in = fopen("invertsub.in", "r"); 
    fgets(s, 100, in);
    fgets(t, 100, in);
    fclose(in);
    int ls = strlen(s)-1;
    int lt = strlen(t)-1;
    int i, j, k;
    for(i=0;i<ls;i++){
        for(j=0, k=i; j<lt && k<ls && s[k]==t[j];j++,k++);
        if(j==lt){
            __strrev(s, i, k-1);
            break;
        }
    }
    out = fopen("invertsub.out", "w");
    fputs(s,out);
    fclose(out);
    return 0; 
}
