#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))
#define LEN(a)      (sizeof(a)/sizeof(a[0]))
#define NEW(type)   (type*)malloc(sizeof(type)) 
#define NEW_N(n,type)   (type*)malloc(n*sizeof(type)) 


typedef struct var{
    char s[10];
    double v;
} var;

var tab[10000];
int t;

char expr[1000000],exptmp[1000000];
char s[1000000];

double stack[1000000];
int top;

void cal(char *s)
{
    top=-1;
    char *token;
    token = strtok(s," ");
    int errflag = 0;
    
    while(token!=NULL){
        if(strcmp(token, "sin")==0){
            if(top<0){
                errflag=1;
                break;
            }
            stack[top]=sin(M_PI*stack[top]/180.0);
        }
        else if(strcmp(token, "cos")==0){
            if(top<0){
                errflag=1;
                break;
            }
            stack[top]=cos(M_PI*stack[top]/180.0);
        }
        else if(strcmp(token, "+") == 0){
            if(top <= 0){
                errflag=1;
                break;
            }
            stack[top - 1] += stack[top];
            top--;
        }
        else if(strcmp(token, "-") == 0){
            if(top <= 0){
                errflag=1;
                break;
            }
            stack[top - 1] -= stack[top];
            top--;
        }
        else if(strcmp(token, "*") == 0){
            if(top <= 0){
                errflag=1;
                break;
            }
            stack[top - 1] *= stack[top];
            top--;
        }
        else if(strcmp(token, "/") == 0){
            if(top <= 0||stack[top] == 0){
                errflag=1;
                break;
            }
            stack[top - 1] /= stack[top];
            top--;
        }
        else if(isalpha(token[0])){
            int i;
            for(i=0;i<t;i++){
                if(strcmp(token,tab[i].s)==0){
                    stack[++top]=tab[i].v;
                    break;
                }
            }
            if(i==t){
                errflag=1;
                break;
            }
        }
        else{
            stack[++top]=strtod(token,NULL);
        }
        token = strtok(NULL," ");
    }
    
    if(top==0 && !errflag){
        printf("%g\n", stack[top]);
    }
    else{
        puts("error");
    }
}



int main(void)
{
    char *token;
    
    freopen("express.in","r",stdin);
    gets(expr);
    while(gets(s)!=NULL){
        strcpy(exptmp,expr);    
        token = strtok(s," :");
        t=0;
        while(token!=NULL){
            strcpy(tab[t].s,token);
            token = strtok(NULL, " :");
            tab[t].v = strtod(token, NULL);
            t++; 
            token = strtok(NULL, " :");
        }
        cal(exptmp);
    }
    return 0;
}

