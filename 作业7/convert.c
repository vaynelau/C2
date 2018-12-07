#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))
#define LEN(a)      (sizeof(a)/sizeof(a[0]))
#define NEW(type)   (type*)malloc(sizeof(type))
#define NEW_N(n,type)   (type*)malloc(n*sizeof(type))

int gcd(int a, int b) // ��������a��b�����Լ�����ݹ鷽��
{
    if (b == 0)// �ݹ���ֹ�������ж�
        return a;
    return gcd(b, a % b);
}

void gen_noncirc(int a, char *s)
{
    int i, k, m, n = 1;
    for (i = m = 0; isdigit(s[i]); i++) {
        m = m * 10 + s[i] - '0';
        n *= 10;
    }
    k = gcd(m, n);
    printf("%d/%d\n", a * (n / k) + m / k, n / k);
}

void gen_circ(int a, char *s)
{
    int a_val, i, k, m, n = 1, u;
    char *bp;
    bp = strchr(s, '_'); 
    *bp = '\0'; 
    bp++; // �ָ�ѭ��С��
    for (i = m = 0; isdigit(s[i]); i++) {// ����x1...xm
        m = m * 10 + s[i] - '0';
        n *= 10;
    }
    a_val = m;
    for (i = u = 0; isdigit(bp[i]); i++) {// ����x1...xmy1...yn
        m = m * 10 + bp[i] - '0';
        u = u * 10 + 9;
    }
    m -= a_val;//����x1...xmy1...yn -x1...xm
    u *= n;
    k = gcd(m, u);
    printf("%d/%d\n", a * (u / k) + m / k, u / k);
}

int main()
{
    char s[1000], *p;
    int a;
    gets(s);
    p = strchr(s, '.');// �ָ�������С��
    *p = '\0';
    a = atoi(s);// ��׼���������ַ���ת��Ϊint
    if (strchr(p + 1, '_') == NULL)// �ж�С�������Ƿ���'_'
        gen_noncirc(a, p + 1);// ��ѭ��С��
    else
        gen_circ(a, p + 1); // ��ѭ��С��
    return 0;
}
