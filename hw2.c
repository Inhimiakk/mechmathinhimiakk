#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task2_12(){
    float r;
    float h;
    printf("Введіть дійcне число r та h ");
    scanf("%f %f", &r, &h);
    float S = (M_PI*r*r*h)/3;
    printf("%f", S);
}

//e

int softPlus()
{
    double x;
    printf("x = ");
    scanf("%lf", &x);
    double identity = log(1 + exp(x));
    double identity_derivative = exp(x) / (exp(x) + 1);
    printf("identity = log(1 + exp(x)) = %lf, identity_derivative = exp(x) / (exp(x) + 1) = %lf", identity, identity_derivative);
}

int main(){
    task2_12();
    printf("\n");

    softPlus();
}