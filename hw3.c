#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task3_16(){
    double x1, y1, r1, x2, y2, r2;
    printf("Введіть координати та радіус 1-го кола (х, у, r)= ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Введіть координати та радіус 2-го кола (х, у, r)= ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    double res = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    if (res < r1 + r2)
    {
        printf("ТАААААК");
    }
    else if (res = r1 + r2){
        printf("Дотикаються в одній точці");
    }
    else{
            printf("net blin :(");
    }
}

int eReLu(){
    double x, a;
    printf("x, a= ");
    scanf("%lf %lf", &x, &a);

    double f;

    if(x >= 0){
        f = 0;
    }
    else{
        f = a * (exp(x) - 1);
    }

    printf("f = %lf", f);
}

double derivative_eReLu()
{
    double x, a;
    printf("x, a= ");
    scanf("%lf %lf", &x, &a);

    double der;

    if (x >= 0)
    {
        der = 0.0;
    }
    else
    {
        der= a * exp(x);
    }

    printf("der(f) = %lf", der);
}

int task3_23g(){
    eReLu();
    derivative_eReLu();
}

int main(){
    // task3_16();
    task3_23g();
}