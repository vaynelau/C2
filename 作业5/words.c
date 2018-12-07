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

char s[1100];
int v[26],d[26];
int G[26][26];
int a,b;
int queue[26],inqueue[26];
int rear=-1,front=0;

int bfs()
{
    int i,tmp;
    queue[++rear]=a;
    inqueue[a]=1;
    
    while(rear>=front){
        tmp=queue[front++];
        for(i=0;i<26;i++){
            if(G[tmp][i] && !inqueue[i]){
                queue[++rear]=i;
                inqueue[i]=1;
            }
        } 
    }
    for(i=0;i<26;i++){
        if(v[i]!=inqueue[i]){
            return 0;
        }
    }
    return 1;
}


int main(void)
{
    while(scanf("%s",s) != EOF){
        a=s[0]-'a';
        b=s[strlen(s)-1]-'a';
        v[a]=v[b]=1;
        d[a]++;
        d[b]--;
        G[a][b]=G[b][a]=1;
    }
    
    int i,result=1,flag=0;
    for(i=0;i<26;i++){
        if(d[i]!=0 && d[i]!=1 && d[i]!=-1){
            result=0;
            break;
        }
        if(d[i]==1){
            flag++;
        }
    }
    if(result){
        result=(flag==1 || flag==0);
    }
    if(result){
        result = bfs();
    }
    printf("%s\n",result ? "yes":"no");
    return 0;
}
