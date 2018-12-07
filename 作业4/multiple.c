#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
#include <limits.h> 

int N;
int digit[10];

typedef struct node{
    int n,r;
    int deep;
    struct node *parent;
}Node;

int exist[5005];
Node *queue[5005];
int rear = -1;
int front = 0;

Node *bfs()
{
    Node *p,*next;
    int tmp,i;
    p = (Node *)malloc(sizeof(Node));
    p->n = p->r = p->deep = 0;
    p->parent = NULL;
    queue[++rear] = p;
    
    while(rear>=front){
        p = queue[front++];
        if(p->deep >= 500) break;
        for(i=0;i<10;i++){
            if(digit[i]){
                if(i==0 && p->deep==0)
                    continue;
                tmp = ((p->r)*10 + i) % N;
                if(exist[tmp])
                    continue;
                exist[tmp] = 1;
                next = (Node *)malloc(sizeof(Node));   
                next->n = i;
                next->r = tmp;
                next->parent = p;
                next->deep = p->deep+1;
                if(tmp==0){
                    return next;
                }
                queue[++rear]=next;
            }
        } 
    }
    return NULL;
}

void print(Node *p)
{
    FILE *out = fopen("multiple.out","w");
    int result[505],count=0;
    
    if(p!=NULL){
        while(p->deep>=1){
            result[count++] = p->n;
            p = p->parent;
        }
        while(count--){
            fprintf(out,"%d",result[count]);
        }
        fprintf(out,"\n");
    }
    else{
        fprintf(out,"0\n");
    }
    fclose(out);
}

int main(void)
{
    FILE *in = fopen("multiple.in","r");
    fscanf(in,"%d",&N);
    int d;
    while(fscanf(in,"%d",&d) != EOF){
        digit[d] = 1;
    }
    fclose(in);
    
    print(bfs());
    return 0;
}
