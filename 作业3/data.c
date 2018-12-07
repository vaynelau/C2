#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

typedef struct{
    int input_order;
    int mark_num;
    long long num; 
} Nums;
Nums nums[200005];

int comp1(const void *x, const void *y)
{
    Nums *x1 = (Nums *)x;
    Nums *y1 = (Nums *)y;
    return (x1->num > y1->num) - (x1->num < y1->num);
}

int comp2(const void *x, const void *y)
{
    Nums *x1 = (Nums *)x;
    Nums *y1 = (Nums *)y;
    return (x1->input_order > y1->input_order) - (x1->input_order < y1->input_order);
}


int main(void)
{
    int n=0;
    while(scanf("%lld",&nums[n].num)!=EOF){
        nums[n].input_order=n;
        n++;
    }
    
    /*
    long long tmp=0;
    char c,c1;
    while(scanf("%lld%c",&nums[n].num,&c)==2){
        nums[n].input_order=n;
        n++;
        if(c!=' '){
            break;
        }
    }*/
    
    /*
    int flag=0;
    c=getchar(); 
    while(c!='\n'){
        if(c=='-'){
            flag=1;
            c=getchar();
        }else if(isdigit(c)){
            tmp=0;
            while(isdigit(c)){
                tmp=10*tmp+c-'0';
                c=getchar();
            }
            tmp = (flag==1) ? -tmp:tmp;
            nums[n].num=tmp;
            nums[n].input_order=n;
            n++;
            flag=0;
        }else{
            c=getchar();
        }  
    }*/
    
    qsort(nums, n, sizeof(Nums),comp1);
    
    int i,mark=1;
    nums[0].mark_num=mark;
    for(i=1;i<n;i++){
        if(nums[i].num>nums[i-1].num){
                        mark++;
        }
        nums[i].mark_num=mark;
    }
    
    qsort(nums, n, sizeof(Nums),comp2);
    
    for(i=0;i<n-1;i++){
        printf("%d ",nums[i].mark_num);
    }
    printf("%d\n",nums[i].mark_num);
    return 0;
}
