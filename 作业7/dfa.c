#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define todigit(c)  (isdigit(c) ? (c)-'0' : 0)
#define tochar(d)   ((d) + '0')
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))
#define NEW(n,type) (type*)malloc(n*sizeof(type))

#define LEN 50
#define MAX 500

typedef struct {
    char next[LEN];
    int nextNum;
    char outStr[LEN];
} FUN;

typedef struct {
    FUN fun[MAX];
    char stateStr[LEN];
} STATE;

FILE *in;
STATE state[MAX];
char initState[LEN], *inArray[MAX], *inChar[MAX], outArray[MAX];
int inCharNum = 0, stateNum = 0, inArrayNum = 0;


void input()
{
    int i, k;
    char buf[100000];

    fgets(buf,100000,in);
    char *token = strtok(buf," \n");
    token = strtok(NULL," \n");
    i=0;
    while(token){
        inChar[i] = (char *)malloc(LEN);
        strcpy(inChar[i],token);
        token = strtok(NULL," \n");
        i++;
    }
    inCharNum = i;
    
    for(i=0;fgets(buf,100000,in)!=NULL;i++){
        token = strtok(buf," ,\n"); 
        strcpy(state[i].stateStr,token); 
        token = strtok(NULL," ,\n");
        if(token==NULL){
            break;
        }
        for(k=0;token!=NULL;k++){
            strcpy(state[i].fun[k].next,token);
            token = strtok(NULL," ,\n");
            strcpy(state[i].fun[k].outStr,token);
            token = strtok(NULL," ,\n");
        }
    }
    stateNum = i;
    
    strcpy(initState, state[i].stateStr);
    
    fgets(buf,100000,in);
    token = strtok(buf," \n");
    for(i=0;token!=NULL;i++){
        inArray[i] = (char *)malloc(LEN);
        strcpy(inArray[i],token);
        token = strtok(NULL," \n");
    }
    inArrayNum = i;
}

void setState()
{
    int i, j, k;

    for (i = 0; i < stateNum; i++) {
        for (j = 0; j < inCharNum; j++) {
            for (k = 0; k < stateNum; k++) {
                if (strcmp(state[i].fun[j].next, state[k].stateStr) == 0) {
                    state[i].fun[j].nextNum = k;
                    break;
                }
            }
        }
    }
}

void run()
{
    int i, j, curState, nextState, temp;
    
    for (i = 0; i < stateNum; i++) {
        if (strcmp(initState, state[i].stateStr) == 0) {
            curState = i;
            break;
        }
    }
    outArray[0] = '\0';
    for (i = 0; i < inArrayNum; i++) {
        temp = 0;
        for (j = 0; j < inCharNum; j++) {
            if (strcmp(inArray[i], inChar[j]) == 0){
                temp = j;
                break;
            } 
        }
        nextState = state[curState].fun[temp].nextNum;
        strcat(outArray, state[curState].fun[temp].outStr);
        if (i == inArrayNum - 1)
            strcat(outArray, "\n");
        else
            strcat(outArray, " ");
        curState = nextState;
    }
    printf("%s\n%s", state[curState].stateStr, outArray);
}

int main()
{
    in = fopen("dfa.in", "r");
    input();
    setState();
    run();
    fclose(in);
    return 0;
}




