#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 


int is_prime(int n)
{
    int i;
    
    if(n==1 || n>2 && n%2==0){
        return 0;
    }
    for(i=3;i*i<=n;i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int N;
int plus[]={1,3,7,9};

void is_nprime(int n, int width)
{
    if(!is_prime(n)){
        return;
    }
    if(width>=N){
        printf("%d\n",n);
        return;
    }
    int i;
    for(i=0;i<4;i++){
        is_nprime(n*10+plus[i], width+1);
    }
    
}



int main(void)
{
    scanf("%d", &N);
    int i;
    int init[]={2,3,5,7};
    for(i=0;i<4;i++){
        is_nprime(init[i],1);
        
    }
    
    return 0;
}

/*
N位质数

 

【问题描述】

 

给定一个整数N（2 <= N <= 8），生成所有的具有下列特性的特殊的N位质数：其前任意位都是质数。
例如，7331即是这样一个4位的质数，因为7、73和733也都是质数。
 

【输入形式】

 

标准输入上输入一个正整数N（2 <= N <= 8）。
 

【输出形式】

 

标准输出。 输出所有符合题意的N位质数，每个数占一行，且按升序排列。
 

【输入样例】

 

2
 

【输出样例】

 

23 
29 
31 
37 
53 
59 
71 
73 
79
 

【时间限制】

 

5s
 

【空间限制】

 

65536KB
 

【上传文件】

 

上传c语言源程序，文件名为nprime.c。
 */
