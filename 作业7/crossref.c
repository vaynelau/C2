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
#define LEN(a)      (sizeof(a)/sizeof(a[0]))
#define NEW(n,type) (type*)malloc(n*sizeof(type)) 


typedef struct line{
    int n;
    struct line *next;
} Line;

typedef struct node{
    char w[25];
    struct node *left,*right; 
    Line *next;
}Node;

const char *sp[] = {"a", "an", "the", "and"};
char s[20005], w[30], w2[30];

void inorder(Node *p)
{
    if(p->left != NULL){
        inorder(p->left);
    }
    
    printf("%s:",p->w);
    Line *q = p->next;
    while(q->next!=NULL){
        printf("%d,",q->n);
        q=q->next;
    }
    printf("%d\n",q->n);
    
    if(p->right != NULL){
        inorder(p->right);
    }
}

int main(void)
{
    int n = 1, len;
    int i,j,k;
    Node *head = NULL,*p,*p2;
    Line *q;
    while(fgets(s,20003,stdin)!=NULL){
        len = strlen(s);
        if(len<=1){
            break;
        }
        for(i=0;i<len;i++){
            if(isalpha(s[i]) || s[i]=='-'){
                j=0;
                while(isalpha(s[i]) || s[i]=='-'){
                    w[j]=s[i];
                    w2[j++]=tolower(s[i++]);
                }
                w[j]=w2[j]='\0';
                if(w[0]=='-'|| w[j-1]=='-'){
                    continue;
                }
                for(k=0;k<4;k++){
                    if(strcmp(w2,sp[k])==0){
                        break;
                    }
                }
                if(k<4){
                    continue;
                }
                if(head==NULL){
                    head = NEW(1, Node);
                    strcpy(head->w, w);
                    head->left=head->right=NULL;
                    q = head->next = NEW(1, Line);
                    q->n=n;
                    q->next=NULL;
                }
                else{
                    p=head;
                    while(p!=NULL){
                        p2 = p;
                        if(strcmp(w,p->w)<0){
                            p = p->left;
                        }
                        else if(strcmp(w,p->w)>0){
                            p = p->right;
                        }
                        else{
                            q=p->next;
                            while(q->next!=NULL){
                                q = q->next;
                            }
                            if(q->n < n){
                                q = q->next = NEW(1, Line);
                                q->n = n;
                                q->next = NULL;
                            }
                            break;
                        }
                    }
                    if(p==NULL){
                        p=p2;
                        if(strcmp(w,p->w)<0){
                            p = p->left = NEW(1,Node);
                        }
                        else if(strcmp(w,p->w)>0){
                            p = p->right = NEW(1,Node);
                        }
                        p->left = p->right = NULL;
                        strcpy(p->w,w);
                        q = p->next = NEW(1,Line);
                        q->n=n;
                        q->next=NULL;
                    }
                }
            }
        }
        n++;
    }
    if(head != NULL){
        inorder(head);
    }
    return 0;
}
