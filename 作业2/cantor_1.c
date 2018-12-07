#include<stdio.h>
int main(){	int n,s,k;	while(scanf("%d",&n)==1)	{		s=0;k=1;		while(1)		{			s+=k;			if(s>=n)			{				if(k%2==0) 					printf("%d/%d\n",(k+1)-(s-n+1),s-n+1);				else 					printf("%d/%d\n",s-n+1,(k+1)-(s-n+1));				break;			}			k++;		}	}	return 0;}


