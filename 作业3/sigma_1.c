#include<stdio.h>
#include<string.h>

long long power(int n, int m)
{
    int i;
    long long integer = 1;
    for(i = 0; i < m; i++){
        integer *= n;
    }
    return integer;
}

long long cal_integer_part(int k, int x, int n) //������������
{
    long long integer = 0;
    integer = (power(x, n + 1) - 1) / (x - 1);
    return integer * k;
}

double cal_decimal_part(int k, int x, int m)    //����С������
{
    int i;
    double decimal = 1.0 * k * (power(x, m) - 1) / (x - 1);
    //Ҫ�ȳ���k�����������������x^m���ٳ���k�������൱�ڽ��������������Ŵ���k����

    for(i = 0; i < m; i++){
        decimal *= 1.0 / x;
    }

    return decimal;
}

int main()
{
    int i;
    int k, x, m, n;
    long long integer;
    double decimal;
    char tmp[20] = {0};

    freopen("sigma.in", "r", stdin);

    scanf("%d%d%d%d", &k, &x, &m, &n);

    if(x == 1){                             //ǧ��ע�ⲻҪdivided by zero
        printf("%d", k * (m + n + 1) );
        putchar('.');
        for(i = 0; i < 14; i++){            //���14��0
            putchar('0');
        }
        putchar('\n');
    }
    else{
        integer = cal_integer_part(k, x, n);
        decimal = cal_decimal_part(k, x, m);

        while(decimal > 1){                 //С������*k����>1�������������ת�Ƶ�integer
            decimal -= 1;
            integer += 1;
        }

        sprintf(tmp, "%.14lf", decimal);    //���С����tmp

        printf("%lld", integer);
        puts(tmp + 1);                      //��ȡС���㼰֮���С������
    }

    return 0;
}


