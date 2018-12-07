#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

int main(void)
{
    int n; 
    scanf("%d",&n);
    int i;
    for(i=1;i*(i+1)/2<n;i++);
    n-=(i*(i-1)/2);
    if(i%2!=0){
        printf("%d/%d\n",i+1-n,n);
    }
    else{
        printf("%d/%d\n",n,i+1-n);
    }
    
    return 0;
}

/*
题目：Cantor表的第n项

 

【问题描述】

 

现代数学的著名证明之一是Georg Cantor用下面这一张表证明了有理数是可枚举的。以Z形方式顺序给表中的每一项编号。第一项是1/1，然后是1/2，2/1，3/1，2/2，…。从标准输入上读入一个整数N(1≤N≤10000000)，在标准输出上输出表中第N项所对应的分数。


 

【输入形式】

 

一个正整数，占一行，整数的前后均无空白符。
 

【输出形式】

 

以a/b形式表示的分数，以换行符结束。分数的前及各个字符间均无空格。
 

【输入样例】

 

9
 

【输出样例】

 

3/2
 

【时间限制】

 

1s
 

【空间限制】

 

65.536KB
 

【上传文件】

 

上传c语言源程序，文件名为cantor.c。
*/ 
