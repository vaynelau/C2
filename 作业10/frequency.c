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
    char s[128];
    int cnt;
    struct node *left, *right;
} Node;


char c;
char s[128];
int l;
int lfcnt, sycnt;

int inword()
{
    while(isspace(c) && c!='\n'&& c!=EOF){
        c = getchar();
    }
    if(c==EOF){
        return c;
    }
    if(c=='\n'){
        lfcnt++;
        c=getchar();
        return '\n';
    }
    
    lfcnt=0;
    if(isdigit(c)){
        l=0;
        while(isdigit(c) || c=='\'' || c=='-'){
            s[l++]=c;
            c=getchar();
        }
        s[l]='\0';
        return 0;
    }
    
    if(isalpha(c)){
        l=0;
        while(isalnum(c) || c=='\'' || c=='-'){
            if(l==0 && isalpha(c)){
                s[l++]=tolower(c);
            }
            else{
                s[l++]=c;
            }
            c=getchar();
        }
        s[l]='\0';
        return 0;
    }
    sycnt++;
    c=getchar();
    return 1;
}

int typ;

void getword()
{
    while((isspace(c) || c=='+') && c!='\n'&& c!=EOF){
        c = getchar();
    }
    if(c==EOF){
        typ=EOF;
        return;
    }
    if(c=='\n'){
        typ=c;
        c = getchar();
        return;
    }
    
    l=0;
    while(isalnum(c) || c=='_' || c=='\'' || c=='-'){
        if(l==0 && isalpha(c)){
            s[l++]=tolower(c);
        }
        else{
            s[l++]=c;
        }
        c=getchar();
    }
    s[l]='\0';
    typ=0;
    return;
}

int main(void)
{
    freopen("frequency.in","r",stdin);
    Node *head = NULL;
    c = getchar();
    while(lfcnt<4){
        if(!inword()){
            if(head==NULL){
                head = NEW(Node);
                head->left=head->right=NULL;
                strcpy(head->s,s);
                head->cnt=1;
            }
            else{
                Node *p=head;
                while(1){
                    int cmp = strcmp(s,p->s);
                    if(cmp<0){
                        if(p->left!=NULL){
                            p=p->left;
                        }
                        else{
                            p=p->left=NEW(Node);
                            p->left=p->right=NULL;
                            strcpy(p->s,s);
                            p->cnt=1;
                            break;
                        }
                    }
                    else if(cmp>0){
                        if(p->right!=NULL){
                            p=p->right;
                        }
                        else{
                            p=p->right=NEW(Node);
                            p->left=p->right=NULL;
                            strcpy(p->s,s);
                            p->cnt=1;
                            break;
                        }
                    }
                    else{
                        p->cnt++;
                        break;
                    }
                }
            } 
        }
    }
    getword();
    int tmp;
    while(typ!=EOF){
        int cnt = 0;
        int n;
        while(typ!='\n' && typ!=EOF){
            if(s[0]=='_' && strcmp(s,"_PUNCT_")==0){
                cnt+=sycnt;
            }
            else{
                Node *p=head;
                while(p!=NULL){
                    n=strcmp(s,p->s);
                    if(n<0){
                        p=p->left;
                    }
                    else if(n>0){
                        p=p->right;
                    }
                    else{
                        cnt+=p->cnt;
                        break;
                    }
                }
            }
            getword();
        }
        printf("%d\n",cnt);
        getword();
        tmp++;
    }
    
    
    return 0;
}
