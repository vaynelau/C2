/* 存在不明bug */
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


typedef struct node{
    char s[10];
    double v;
    struct node *left,*right;
} Node;

char s[10];
int l=0;
char c;
int ret;

int getword()
{
    while(c!='\n'&&isspace(c) || c==':'){
        c=getchar();
    }
    if(c=='\n'){
        c=getchar();
        return ret ='\n';
    }
    if(c==EOF){
        return ret = EOF;
    }
    l=0;
    while(!isspace(c) && c!=EOF && c!=':'){
        s[l++]=c;
        c=getchar();
    }
    s[l]='\0';
    return ret=0;
}

Node *stack[10000],*leaf[10000];
int top=-1;
int x=0;
int errflag =0;

double cal(Node *p)
{
    if(p->left==NULL && p->right==NULL){
        return p->v;
    }
    if(p->right==NULL){
        if(strcmp(p->s,"sin")==0){
            return sin(M_PI*cal(p->left)/180.0);
        }
        else{
            return cos(M_PI*cal(p->left)/180.0);
        }
    }
    
    if(strcmp(p->s,"+")==0){
        return cal(p->left)+cal(p->right);
    }
    if(strcmp(p->s,"-")==0){
        return cal(p->left)-cal(p->right);
    }
    if(strcmp(p->s,"*")==0){
        return cal(p->left)*cal(p->right);
    }
    if(strcmp(p->s,"/")==0){
        int tmp;
        if((tmp=cal(p->right))!=0)
            return cal(p->left)/tmp;
        else{
            errflag = 1;
            return 0;
        }
    }
    return 0;
}

char *op[]={"+","-","*","/","sin","cos"};

int main(void)
{
    freopen("express.in","r",stdin);
    c=getchar();
    Node *p;
    while(getword()!='\n'){
        int i,flag=1;
        for(i=0;i<LEN(op);i++){
            if(strcmp(s,op[i])==0){
                flag=0;
                p=NEW(Node);
                strcpy(p->s,s);
                if(i<4){
                    p->right=stack[top--];
                }
                else{
                    p->right=NULL;
                }
                p->left=stack[top--];
                stack[++top]=p;
                break;
            }
        }
        if(flag){
            p=stack[++top]=NEW(Node);
            p->right=p->left=NULL;
            if(isalpha(s[0])){
                leaf[x++]=p;
                strcpy(p->s,s);
                p->v=0;
            }
            else{
                (p->s)[0]='\0';
                p->v=strtod(s,(char**)NULL);
            }
        }
    }
    getword();
    int i;
    while(ret!=EOF){
        errflag = 0;
        int cnt=0;
        while(ret!='\n' && ret!=EOF){
            int flag=1;
            for(i=0;i<x;i++){
                if(strcmp(s,leaf[i]->s)==0){
                    flag=0;
                    cnt++;
                    getword();
                    leaf[i]->v=strtod(s,(char**)NULL);
                    break;
                }
            }
            if(flag){
                errflag=1;
                getword();
            }
            getword();
        }
        if(errflag || cnt<x){
            puts("error");
            getword();
            continue;
        }
        double d = cal(stack[0]);
        char buf[1000];
        if(errflag){
            puts("error");
        }
        else{
            printf("%g\n",d);
        }
        getword();
    }
    
    
    return 0;
}
