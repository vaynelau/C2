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

long long cal_integer_part(int k, int x, int n) //计算整数部分
{
    long long integer = 0;
    integer = (power(x, n + 1) - 1) / (x - 1);
    return integer * k;
}

double cal_decimal_part(int k, int x, int m)    //计算小数部分
{
    int i;
    double decimal = 1.0 * k * (power(x, m) - 1) / (x - 1);
    //要先乘以k，而不是在做完除以x^m后再乘以k，那样相当于将除法产生的误差放大了k倍！

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

    if(x == 1){                             //千万注意不要divided by zero
        printf("%d", k * (m + n + 1) );
        putchar('.');
        for(i = 0; i < 14; i++){            //输出14个0
            putchar('0');
        }
        putchar('\n');
    }
    else{
        integer = cal_integer_part(k, x, n);
        decimal = cal_decimal_part(k, x, m);

        while(decimal > 1){                 //小数部分*k可能>1，如果是则将整数转移到integer
            decimal -= 1;
            integer += 1;
        }

        sprintf(tmp, "%.14lf", decimal);    //输出小数到tmp

        printf("%lld", integer);
        puts(tmp + 1);                      //获取小数点及之后的小数部分
    }

    return 0;
}


