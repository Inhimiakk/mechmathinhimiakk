#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>


int task4_1()
{
    double x;
    printf("Введите x: ");
    scanf("%lf", &x);

    unsigned n;
    printf("Введите n: ");
    scanf("%u", &n);

    double y = x;

    for (unsigned i = 1; i <= n; i++)
    {
        y = sin(y);
    }

    printf("Результат после %u итераций синуса: %lf\n", n, y);
}

int task4_2(){
    unsigned n;
    printf("Введите n: ");
    scanf("%u", &n);

    printf("%u! = 1", n);

    for (int i = 2; i <= n; i++)
    {
        printf("*%d", i);
    }

    printf("\n %u! = %u", n, n);
    for (int i = n-1; i >= 1; i--)
    {
        printf("*%d", i);
    }
}

int task4_3a(){
    int n = 3;
    int x = 2;
    int a = 1;
    int res = 1;

    for (int i = 1; i <= n;i++){
        a *= x;
        res += a;
    }
    printf("y = %d", res);
}

int task4_3b()
{
    int n = 4;
    int x = 1;
    int y = 2;
    int x2 = x * x;
    int x_pow = 1;
    int y_pow = 1;
    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        y_pow *= y;
        x_pow *= x2;
        res += y_pow*x_pow;
    }
    printf("res = %d", res);
}

int task4_4()
{
    unsigned n;
    double x;
    printf("Введіть n: ");
    scanf("%u", &n);
    printf("Введіть x: ");
    scanf("%lf", &x);

    int a = 1;
    double res = 0;

    for (int i = 1; i <= n; i++)
    {
        a *= x;
        res += i*a;
    }
    printf("y = %lf", res);
}


unsigned task4_5()
{
    unsigned n;
    printf("Введіть n: ");
    scanf("%u", &n);
    unsigned res = 1;

    if (n % 2 == 0)
    {
        for (int i = 2; i <= n; i += 2)
        { 
            res *= i;
        }
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        { 
            res *= i;
        }
    }

    printf("%u!! = %u\n", n, res);
}

int task4_6()
{
    int n;
    scanf("%d", &n);
    // a)
    double a = 0.;
    for (int i = 0; i < n; i++)
    {
        a = sqrt(a + 2.);
    }

    printf("a) %lf\n", a);

    // b)
    double b = 0.;
    for (int i = 0; i < n; i++)
    {
        b = sqrt(3 * (n - i) + b);
    }

    printf("b) %lf\n", b);
}

int task4_7(){

    int n;
    double x;
    double res = 1;
    double prom = 1;

    do
    {
        printf("Введіть n : ");
        scanf("%d", &n);

        if (n < 0)
        {
            printf("n >= 0!!!\n");
        }

    } while (n < 0);

    do
    {
        printf("Введіть x : ");
        scanf("%lf", &x);

        if (x >= 1 || x <= -1)
        {
            printf("|x| повинно бути менше 1!!!\n");
        }
    } while (x >= 1 || x <= -1);

    for (int i = 1; i <= n; i++){
        prom = (prom * x) / i;
        res += prom;
    }

    printf("res = %lf", res);
}

int task4_8(){
    int m;
    int count = 0;
    do
    {
        printf("Введіть m>=1 : ");
        scanf("%d", &m);

        if (m < 1)
        {
            printf("m >= 1!!!\n");
        }

    } while (m < 1);

    while (m>=4)
    {
        m /= 4;
        count += 1;
    }

    printf("count= %d", count);
}

int task4_9(){
    unsigned n;
    int r = 0;
    int res = 2;
    printf("n = ");
    scanf("%u", &n);

    while (n >= 2)
    {
        n /= 2;
        r += 1;
    }

    for (int i = 1; i <= r;i++){
        res *= 2;
    }

    printf("2^r>=%u = %d", n, res);
}

int task4_10()
{
    printf("%.18lf\n", DBL_EPSILON);

    double a = 1.;
    do
    {
        a /= 2.;
    } while (1. != a + 1.);

    printf("%.18lf\n", a * 2.);
}

int task4_11()
{
    double av = 0., av_h = 0.;

    int i = 0;
    while (1)
    {
        printf("a[%d]=", i);
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        i++;
        av += n;
        av_h += 1. / n;
    }
    av = av / i;
    av_h = i / av_h;

    printf("av = %lf\n", av);
    printf("av_h = %lf\n", av_h);
}

uint64_t subfact(unsigned n)
{
    // !0 = 1
    // !1 = 0
    if (n < 2)
    {
        return 1 - n;
    }
    // n >= 2: !n = !(n-1) * n + (-1)^n
    return subfact(n - 1) * n + (n % 2 == 0 ? 1 : -1);
}

int task4_12()
{
    unsigned n;
    scanf("%u", &n);

    printf("!%u = %" PRIu64 "\n", n, subfact(n));
}

int main()
{
    // task4_1();
    // task4_2();
    // task4_3a();
    // task4_3b();
    // task4_4();
    // task4_5();
    // task4_6();
    // task4_7();
    // task4_8();
    // task4_9();
    // task4_10();
    // task4_11();
    // task4_12();
}
