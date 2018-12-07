#include <stdio.h>
#include <math.h> 

int main(void)
{
    FILE *in = fopen("poisson.in", "r");
    double m,log_p,tmp=0;
    int k;
    fscanf(in,"%lf %d",&m,&k); 
    int i;
    for(i=1;i<=k;i++){
        tmp+=log(i);
    }
    log_p=k*log(m)-m-tmp;
    
    FILE *out=fopen("poisson.out","w");
    fprintf(out,"%.6e\n",exp(log_p));
    fclose(in);
    fclose(out);
    return 0;
}

/*
题目：泊松分布

 

【问题描述】

 

泊松分布是一种常用的离散型概率分布，数学期望为m的泊松分布的分布函数定义如下：
P(m, k) = mk * e-m/k!  (k = 0, 1, 2, 3, …)

对于给定的m和k (0<m<2000, 0<= k < 2500)，计算其概率，以科学格式输出，保留小数点后6位有效数字。

 

可以使用数学库函数，误差不超过0.000001。

 

【输入形式】

 

输入文件为当前目录下的poisson.in。 文件中包含两个数字，分别为m,k的值。
 

【输出形式】

 

输出文件为当前目录下的poisson.out。 文件中输出泊松分布的值，值以科学格式输出，保留小数点后6位有效数字。
 

【输入样例】

 

1 0
 

【输出样例】

 

3.678794e-01
 

【时间限制】

 

1s
 

【空间限制】

 

65536KB
 

【上传文件】

 

上传c语言源程序，文件名为poisson.c。

*/ 
