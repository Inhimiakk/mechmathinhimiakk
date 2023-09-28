#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdint.h>

int task3_1(){
    unsigned x;
    printf("Введіть трьохзначне x= ");
    scanf("%u", &x);

    unsigned x1 = x / 100;
    unsigned x2 = (x / 10) - x1 * 10;
    unsigned x3 = x % 10;

    unsigned sum = x1 + x2 + x3;
    unsigned num = x3 * 100 + x2 * 10 + x1;

    printf("%u %u %u\n %u\n %u\n", x1, x2, x3, sum, num);
}

int task3_2(){
    unsigned x;
    printf("Введіть трьохзначне x= ");
    scanf("%u", &x);

    unsigned x1 = x / 100;
    unsigned x2 = (x / 10) - x1 * 10;
    unsigned x3 = x % 10;

    if (x1 != x2 && x1 != x3 && x2 != x3)
    {
        unsigned num1 = x3 * 100 + x2 * 10 + x1;
        unsigned num2 = x2 * 100 + x1 * 10 + x3;
        unsigned num3 = x1 * 100 + x3 * 10 + x2;
        printf("%u %u %u", num1, num2, num3);
    }
    else{
        printf("Цифри не дуже, поміняй пж");
    }
}

uint16_t uint8mul(uint8_t a, uint8_t b)
{
    return (uint16_t)a * (uint16_t)b;
}

int task3_3()
{
    uint8_t a, b;
    printf("Введіть два числа: ");
    scanf("%hhu %hhu", &a, &b);
    printf("%u\n", uint8mul(a, b));
    return 0;
}

int task3_4()
{
    unsigned a, b, c;
    //a,b,c < 2^10
    scanf("%u %u %u", &a, &b, &c);
    printf("a) %u\n", a * b * c);

    unsigned long long d, e, f;
    //d,e,f < 2^20
    scanf("%llu %llu %llu", &d, &e, &f);
    printf("b) %llu\n", d * e * f);
}

int task3_5(){
    double x, y;
    printf("Введіть x, y= ");
    scanf("%lf %lf", &x, &y);

    if(x>y){
        printf("x= %lf > y = %lf", x, y);
    }
    else if(x==y){
        printf("x = y = %lf", x);
    }
    else{
        printf("x= %lf < y = %lf", x, y);
    }
}

int task3_6(){
    double a, b, c;
    printf("Введіть a, b, c= ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a<0){
        a = a * (-1);
    }

    if (b<0)
    {
        b = b * (-1);
    }

    if (c < 0){
        c = c * (-1);
    }

    double max;

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    printf("max = %lf\n", max);
}

int task3_7_a(){

    const double eps = 1E-9;
    double a, b, c;
    printf("Введіть a, b, c= ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double d = b * b - (4 * a * c);

    if (d>eps)
    {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %lf, x2 = %lf", x1, x2);
    }
    else if(d=eps){
        double x1 = (-b) / (2 * a);
        printf("x = %lf", x1);
    }
    else{
        printf("коренів немає :(");
    }
    
}

int task3_7_b()
{
    double a, b, c;
    const double eps = 1E-9;
    printf("Введіть a, b, c= ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double d = b * b - (4 * a * c);


    if (d > 0)
    {
        double t1 = (-b + sqrt(d)) / (2 * a);
        double t2 = (-b - sqrt(d)) / (2 * a);
        if (t1 < 0)
        {
            if (t2 < 0)
            {
                printf("коренів немає :(");
            }
            else if (t2 = eps)
            {
                double x1 = sqrt(t1);
                printf(" %lf", x1);
            }
            else
            {
                double x3 = sqrt(t2);
                double x4 = sqrt(t2);
                printf(" %lf %lf", x3, x4);
            }


        }
        else if (t2 < 0)
        {
            if (t1 < 0)
            {
                printf("коренів немає :(");
            }
            else if(t1 = eps){
                double x1 = sqrt(t1);
                printf(" %lf", x1);
            }
            else
            {
                double x1 = sqrt(t1);
                double x2 = -sqrt(t1);
                printf(" %lf %lf", x1, x2);
            }
        }
        else{
            double x1 = sqrt(t1);
            double x2 = -sqrt(t1);
            double x3 = sqrt(t2);
            double x4 = sqrt(t2);

            printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf", x1, x2, x3, x4);
        }
        


    }
    else if (d = eps)
    {
        double t1 = (-b) / (2 * a);
        double x1 = sqrt(t1);
        double x2 = -sqrt(t1);
        if(x1!=x2){
            printf("x1 = %lf, x2 = %lf", x1, x2);
        }
        else{
            printf("x = %lf", x1);
        }
        
    }
    else
    {
        printf("коренів немає :(");
    }
}

    int main()
    {
        // task3_1();
        // task3_2();
        // task3_3();
        // task3_4();
        // task3_5();
        // task3_6();
        // task3_7_a();
        task3_7_b();
    }