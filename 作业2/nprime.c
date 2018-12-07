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
Nλ����

 

������������

 

����һ������N��2 <= N <= 8�����������еľ����������Ե������Nλ��������ǰ����λ����������
���磬7331��������һ��4λ����������Ϊ7��73��733Ҳ����������
 

��������ʽ��

 

��׼����������һ��������N��2 <= N <= 8����
 

�������ʽ��

 

��׼����� ������з��������Nλ������ÿ����ռһ�У��Ұ��������С�
 

������������

 

2
 

�����������

 

23 
29 
31 
37 
53 
59 
71 
73 
79
 

��ʱ�����ơ�

 

5s
 

���ռ����ơ�

 

65536KB
 

���ϴ��ļ���

 

�ϴ�c����Դ�����ļ���Ϊnprime.c��
 */
