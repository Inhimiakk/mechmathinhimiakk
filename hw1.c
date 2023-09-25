
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task1_13(){
    float x = log10(100);
    printf("log10(x)= %f", x);
}

int task1_20(){

    float A, C;

    double B;

    printf("A= ");
    scanf("%f", &A);

    printf("B= ");
    scanf("%E", &B);

    printf("C= ");
    scanf("%f", &C);

    double averA = (A + B + C) / 3.;

    double averH = 3. / ((1. / A) + (1. / B) + (1. / C));

    printf("Середнє арифметичне: %e\n", averA);
    printf("Середнє гармонічне: %e\n", averH);

    printf("Середнє арифметичне (фіксована крапка): %.4f\n", averA);
    printf("Середнє гармонічне (фіксована крапка): %.4f\n", averH);
    
}

int main(){
    task1_20();
}
