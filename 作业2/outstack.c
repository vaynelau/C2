#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int n,i,j;
    int a[15];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    int tmp,flag=1;
    for(i=0;i<n && flag;i++){
        tmp=i;
        for(j=i+1;j<n && flag;j++){
            if(a[j]<a[i]){
                if(a[j]<a[tmp]){
                    tmp=j;
                }
                else{
                    flag=0;
                    break;
                }
            }
        }
    }
    
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}

/*
题目：判断出栈序列

 

【问题描述】

 

对于一个栈，已知元素的进栈序列，判断一个由栈中所有元素组成的排列是否是可能的出栈序列。
比如，进栈序列为1 2 3 4，则可能的出栈序列有4 3 2 1，1 4 3 2等。而1 4 2 3就不是。
 

【输入形式】

 

从标准输入读取输入。 第一行是一个整数N（3≤N≤10），代表有N个元素，其进栈序列是1 2 3 …… N。 第二行是以空格分隔的1~N的数字的一个排列。
 

【输出形式】

 

向标准输出打印结果。 如果该排列是可能的出栈序列，则打印“YES”，否则打印“NO”。在行末要输出一个回车符。
 

【输入样例】

 

4 
1 4 3 2
 

【输出样例】

 

YES
 

【时间限制】

 

1s
 

【空间限制】

 

65536KB
 

【上传文件】

 

上传c语言源程序，文件名为outstack.c。

*/ 
