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

typedef struct item{
    char name[1000];
    int value;
    struct item *next;
} item;


typedef struct{
    int st, end;
    char name[1000];
    item *mem; 
} op;


op ops[1000];

FILE *in;
int typ,val;
char s[1000];
int l;
char c;
int dataflag = 0;
int base;

void nextch()
{
    
    while(!isalnum(c) && c!='_' && c!='=' && (!dataflag && c !='}' || dataflag && c !=')') && c !=EOF){
        c = fgetc(in);
    }
    if(!dataflag && c =='}' || dataflag && c ==')'){
        typ = 2;
        c = fgetc(in);
        return;
    }
    if(c==EOF){
        typ=3;
        return;
    }
    if(c=='='){
        typ = 4;
        c = fgetc(in);
        return;
    }
    typ = 1;
    l = 0;
    while(isalnum(c) || c=='_'){
        if(!isdigit(c)){
            typ = 0;
        }
        s[l++] = c;
        c = fgetc(in);
    }
    s[l]='\0';
    
    //puts(s);
    char *end;
    val = strtol(s,&end,base);
    
    
}

int result;

int main(void)
{
    in = fopen("data.in","r");
    item *p;
    int n = 0;
    int last;
    c = fgetc(in);
    nextch();
    while(typ!=3){
        
            if(strcmp(s,"Data")!=0){
                strcpy(ops[n].name, s);
                base = 10;
                nextch();
                ops[n].st = val;
                nextch();
                ops[n].end = val;
                base = 16;
                nextch();
                p = ops[n].mem = NEW(1,item);
                strcpy(p->name,s);
                p->next = NULL;
                nextch();
                if(typ==1){
                    last = p->value = val;
                    nextch();
                }else{
                    last = p->value = 0;
                }
                while(typ!=2){
                    p = p->next = NEW(1,item);
                    strcpy(p->name,s);
                    p->next = NULL;
                    nextch();
                    if(typ==1){
                        last = p->value = val;
                        nextch();
                    }else{
                        p->value = ++last;
                    }
                }
                nextch();
                n++;
            }
            else{
                dataflag=1;
                result = 0;
                while(typ!=2){
                    nextch();
                    int i;
                    for(i=0;i<n;i++){
                        if(strcmp(ops[i].name,s)==0){
                            int st  = ops[i].st;
                            int end = ops[i].end;
                            int tmp=((1<<(st-end+1))-1)<<end;
                            
                            p = ops[i].mem;
                            nextch();
                            while(p!=NULL){
                                if(strcmp(p->name,s)==0){
                                    result |= ((p->value << end) & tmp);
                                    break;
                                }
                                p=p->next;
                            }
                            break;
                        }
                    }
                }
                printf("0x%08X\n",result);
                nextch();
            }
        }
     
    
    
    
    
    fclose(in); 
    return 0;
}