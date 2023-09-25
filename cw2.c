#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task2_1(){
    float x;
    printf("Введіть дійcне число х= ");
    scanf("%f", &x);
    float y = cos(x);
    printf("%f", y);
}

int task2_2(){
    float a, b;
    printf("Введіть дійcне число a, b ");
    scanf("%f %f", &a, &b);
    float c = sqrt(a * a + b * b);
    printf("%f", c);
}

int task2_3(){
    float a, b, c;
    printf("Введіть дійcне число");
    scanf("%f %f %f", &a, &b, &c);
    float per = (a + b + c) / 2;
    float res = sqrt(per * (per - a) * (per - b) * (per - c));
    printf("%f", res);
}

//d

int task2_4(){
    float x;
    printf("Введіть дійcне число");
    scanf("%f", &x);
    float q = 2 * x;
    float S5 = ((q * q * q * q * q) - 1) / (q - 1);

    printf("%f", S5);
}

double Rosenblock2d(double x, double y){
    double res = 100 * ((x * x) - (y * y)) + (x - 1) * (x - 1);
    return res;

}

int lengthtriangle(){
    double a1, a2, b1, b2, c1, c2;
    printf("A(x, y) = ");
    scanf("%lf %lf", &a1, &a2);
    printf("B(x, y) = ");
    scanf("%lf %lf", &b1, &b2);
    printf("C(x, y) = ");
    scanf("%lf %lf", &c1, &c2);

    double l1 = sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));
    double l2 = sqrt((b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2));
    double l3 = sqrt((c1 - a1) * (c1 - a1) + (c2 - a2) * (c2 - a2));

    double per = (l1 + l2 + l3) / 2;
    float res = sqrt(per * (per - l1) * (per - l2) * (per - l3));

    printf("%f", res);
}


int main(){
    task2_1();
    printf("\n");

    task2_2();
    printf("\n");

    task2_3();
    printf("\n");

    task2_4();
    printf("\n");

    printf("Rosenblock2d (45.77, 678.) = %lf\n", Rosenblock2d(45.77, 678.));
    printf("Rosenblock2d (568.75, 68.69) = %lf\n", Rosenblock2d(568.75, 68.69));
    printf("Rosenblock2d (345.98, 96.78) = %lf\n", Rosenblock2d(345.98, 96.78));

    lengthtriangle();

}