#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task4_19b()
{
    unsigned n;
    double res = 1.0;

    do
    {
        printf("Введіть n : ");
        scanf("%u", &n);

        if (n <= 2)
        {
            printf("n більше 2!!!\n");
        }
    } while (n <= 2);

    for (int i = 2; i <= n; i++)
    {
        res *= (1.0 - (1.0 / (i * i)));
    }

    printf("res = %lf\n", res);
}

int task4_22()
{
    int n;
    printf("Введіть n >= 3: ");
    scanf("%d", &n);

    if (n < 3)
    {
        printf("N повинно бути >= 3.\n");
        return 1;
    }

    int prev, current, next;
    int count = 0;

    printf("Введіть перше число: ");
    scanf("%d", &prev);

    for (int i = 1; i < n - 1; i++)
    {
        printf("Введіть наступне: ");
        scanf("%d", &current);

        printf("Введіть наступне (щоб не розслаблялися): ");
        scanf("%d", &next);

        if (current > prev && current > next)
        {
            count++;
        }

        prev = current;
    }

    // Останнє введення для останнього числа
    printf("Введіть останнє число: ");
    scanf("%d", &current);

    if (current > prev)
    {
        count++;
    }

    printf("Кількість чисел, більших за сусідів: %d\n", count);

}


int main() {
    // task4_19b();
    // task4_22();
}

