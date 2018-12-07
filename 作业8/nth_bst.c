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

typedef struct node {
    char s[2048];
    int n;
    struct node *left,*right;
}Node;


char s[2048];
int n;
int cnt=0;

int main(void)
{
    freopen("nth.in","r",stdin);
    freopen("nth.out","w",stdout);
    gets(s);
    n=strtol(s,(char**)NULL,10);
    Node *head=NULL,*p;
    while(gets(s)!=NULL){
        int len = strlen(s);
        if(head==NULL){
            p=head=NEW(Node);
            cnt++;
            p->left=p->right=NULL;
            p->n=len;
            strcpy(p->s,s);
        }
        else{
            p=head;
            while(1){
                if(len<p->n){
                    if(p->left==NULL){
                        p=p->left=NEW(Node);
                        cnt++;
                        p->left=p->right=NULL;
                        p->n=len;
                        strcpy(p->s,s);
                        break;
                    }
                    else{
                        p=p->left;
                    }
                }
                else if(len>p->n){
                    if(p->right==NULL){
                        p=p->right=NEW(Node);
                        cnt++;
                        p->left=p->right=NULL;
                        p->n=len;
                        strcpy(p->s,s);
                        break;
                    }
                    else{
                        p=p->right;
                    }
                }
                else{
                    strcpy(p->s,s);
                    break;
                }
            }
        }
        if(cnt>n){
            p=head;
            Node *p2;
            if(p->left==NULL){
                head=p->right;
                free(p);
            }
            else{
                while((p->left)->left!=NULL){
                    p=p->left;
                }
                p2=p->left;
                p->left=(p->left)->right;
                free(p2);
            }
            cnt--;
        }
    }    
    p=head;
    while(p->left!=NULL){
        p=p->left;
    } 
    puts(p->s);
    return 0;
}
