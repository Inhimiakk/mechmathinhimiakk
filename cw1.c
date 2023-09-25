
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task1_1()
{
    int a = 2 + 31;
    int b = 45 * 54 - 11;
    double c = 15 / 4; // при діленні цілочисельних операндів виводиться цілочисельний результат (заокруглення)
    double d = 15.0 / 4;
    double e = 67 % 5;
    double f = (2 * 45.1 + 3.2) / 2;
    printf("2 + 31 = %d\n45 * 54 - 11 = %d\n15 / 4 = %f\n15.0 / 4 = %f\nостача від ділення: 67 на 5 = %f\n(2 * 45.1 + 3.2) / 2 = %f", a, b, c, d, e, f);
}

int task1_2(){
    float a1 = 1e-4f;
    double a2 = 1e-4;
    long double a3 = 1e-4L;

    float b1 = 24.33e5f;
    double b2 = 24.33e5;
    long double b3 = 24.33e5L;

    float c1 = M_PI;
    double c2 = M_PI;
    long double c3 = M_PI;

    float d1 = M_E;
    double d2 = M_E;
    long double d3 = M_E;

    float e1 = sqrt(5);
    double e2 = sqrt(5);
    long double e3 = sqrt(5);

    float f1 = log(100);
    double f2 = log(100);
    long double f3 = log(100);

    printf("%.2f , %.2lf , %.2Lf\n"
           "%.2f , %.2lf , %.2Lf\n"
           "%.2f , %.2lf , %.2Lf\n"
           "%.2f , %.2lf , %.2Lf\n"
           "%.2f , %.2lf , %.2Lf\n"
           "%.2f , %.2lf , %.2Lf\n",
           a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, e1, e2, e3, f1, f2, f3);
}

int task1_3(){
    int a;
    scanf("%d", &a);
    printf("- %d - %d- %d\n %d | %d | %d\n- %d - %d - %d", a, a, a, a, a, a, a, a, a);
}

int task1_4(){
    const long double m1 = 13e3;
    const long double m2 = 7e3;
    const long double r = 17.;
    const long double y = 6.673e-11L;

    long double f = y * ((m1 * m2)/(r * r));
    printf("F = %Le", y);
}

int task1_5(){
    double x, x1, x2, x3, x4, x5, x6;
    scanf("%lf", &x);
    x1 = x;

    x1 = x1 * x1;
    x1 = x1 * x1;

    x2 = x;
    double y2 = x;

    x2 = x2 * x2;
    y2 = x2 * x2;
    x2 = y2 * x2;

    x3 = x;
    double y3 = x3;

    x3 = x3 * x3;
    x3 = x3 * x3;
    x3 = x3 * x3;
    x3 = x3 * y3;

    x4 = x;
    double y4 = x4;

    x4 = x4 * x4;
    x4 = x4 * x4* y4;
    x4 = x4 * x4 * x4;

    x5 = x;
    double y5 = x5;
    double z5 = x5;

    x5 = x5 * x5;
    y5 = x5 * x5;
    x5 = y2 * x5;
    x5 = x5 * z5;
    x5 = x5 * x5;
    x5 = x5 * x5;

    x6 = x;
    x6 = x6 * x6;
    x6 = x6 * x6;
    x6 = x6 * x6;
    x6 = x6 * x6;
    x6 = x6 * x6;
    x6 = x6 * x6;
    printf(" %lf %lf %lf %lf %lf %lf", x1, x2, x3, x4, x5, x6);
}

int task1_6(){
    float C;
    printf("Введіть мяу ");
    scanf("%f", &C);
    float F = (9 * C) / 5 + 32;
    printf("F = %g", F);
}

int task1_7(){
    float x;
    printf("Введіть мяу ");
    scanf("%f", &x);
    int y = (int)x;
    float z = x - y;
    int x1 = y + 1;
    printf("x = %lf, x ціле %d, x дробове %lf, найменше ціле > x %d, найбільше ціле менше х %d", x, y, z, x1, y);
}

int task1_8()
{
    float x;
    float y;
    printf("Введіть мяу x ");
    scanf("%f", &x);
    printf("Введіть мяу y ");
    scanf("%f", &y);
    float z1 = x - y;
    float z2 = x * y;
    printf("x = %.2f, y %.2f, різниця %.2f, добуток %.2f", x, y, z1, z2);
}

int task1_9(){
    float a, b;
    scanf("%f %f", &a, &b);
    float averA = (a + b) / 2.;
    float averH = 2. / (1. / a + 1. / b);

    printf("averA = %f\naverH = %f\n", averA, averH);

    printf("\naverA = %e\naverH = %e\n", averA, averH);
}

int main(){
    // task1_1();
    // printf("\n");

    // task1_2();
    // printf("\n");

    // task1_3();
    // printf("\n");

    // task1_4();
    // printf("\n");

    // task1_5();
    // printf("\n");

    // task1_6();
    // printf("\n");

    // task1_8();
    // printf("\n");

    task1_9();
    printf("\n");
}
