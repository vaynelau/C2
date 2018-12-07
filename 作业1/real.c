#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *in, *out;
    in = fopen("real.in","r");
    char s[30];
    fgets(s,30,in);
    fclose(in);
    
    int i=0,format=0,state=0;
    for(i=0;!format && i<strlen(s);i++){
        switch(state){
            case 0: 
                if(s[i]=='+' || s[i]=='-') state=1;
                else if(s[i]=='0') state=2;
                else if(isdigit(s[i])) state=3; 
                else format=3; 
                break;
            
            case 1: 
                if(s[i]=='0') state=2;
                else if(isdigit(s[i])) state=3;
                else format=3;
                break;
            
            case 2: 
                if(s[i]=='\n') format=1;
                else if(s[i]=='.') state=4;
                else format=3;
                break;
            
            case 3: 
                if(s[i]=='\n') format=1;
                else if(isdigit(s[i])) state=3;
                else if(s[i]=='.') state=4;
                else if(s[i]=='E') state=6;
                else format=3;
                break;
            
            case 4:
                if(isdigit(s[i])) state=5;
                else format=3;
                break;
            
            case 5:
                if(s[i]=='\n') format=1;
                else if(isdigit(s[i])) state=5;
                else if(s[i]=='E') state=6;
                else format=3;
                break;
            
            case 6:
                if(s[i]=='+' || s[i]=='-') state=7;
                else if(s[i]=='0') state=8;
                else if(isdigit(s[i])) state=9; 
                else format=3; 
                break;
            
            case 7:
                if(s[i]=='0') state=8;
                else if(isdigit(s[i])) state=9;
                else format=3;
                break;
                
            case 8:
                if(s[i]=='\n') format=2;
                else format=3;
                break;
            
            case 9:
                if(s[i]=='\n') format=2;
                else if(isdigit(s[i])) state=9;
                else format=3;
                break;
                
            default:
                break;
        }
    }
    
    out = fopen("real.out","w");
    if(format==3) 
        fprintf(out,"Wrong\n");
    else 
        fprintf(out,"Format%d\n",format);
    fclose(out);
    
    return 0;
}
