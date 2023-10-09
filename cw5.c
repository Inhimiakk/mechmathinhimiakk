#include <stdio.h>
#define _USE_MATH_DEFINES
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int task5_1(){
    double s, a;
    printf("n=");
    scanf("%lf", &a);

    int n = 1;
    while (s <= a)
    {
        s += 1. / n;
        n++;
    }

    printf("a) %lf\nb) n = %d\n", s, n - 1);
}

uint64_t fib_n1(unsigned n)
{
    uint64_t r00 = 1, r01 = 0, r10 = 0, r11 = 1;
    uint64_t m00 = 1, m01 = 1, m10 = 1, m11 = 0;

    unsigned i = 1;
    while (n)
    {
        if (n & i)
        {
            n ^= i;
            // r *= m
            uint64_t t00 = r00 * m00 + r01 * m10;
            uint64_t t01 = r00 * m01 + r01 * m11;
            uint64_t t10 = r10 * m00 + r11 * m10;
            uint64_t t11 = r10 * m01 + r11 * m11;
            r00 = t00;
            r01 = t01;
            r10 = t10;
            r11 = t11;
        }
        i <<= 1;

        // m *= m
        uint64_t q00 = m00 * m00 + m01 * m10;
        uint64_t q01 = m00 * m01 + m01 * m11;
        uint64_t q10 = m10 * m00 + m11 * m10;
        uint64_t q11 = m10 * m01 + m11 * m11;
        m00 = q00;
        m01 = q01;
        m10 = q10;
        m11 = q11;
    }

    return r01;
}

// fib in O(n)
uint64_t fib_n2(unsigned n)
{
    if (n < 2)
        return n;
    uint64_t a = 0, b = 1;
    for (unsigned i = 2; i <= n; i++)
    {
        uint64_t t = a + b;
        a = b;
        b = t;
    }
    return b;
}

// 5.2.b

unsigned fib_less_than(uint64_t n)
{
    if (n < 2)
        return 0;
    uint64_t a = 0, b = 1;
    unsigned i = 0;
    do
    {
        uint64_t t = a + b;
        a = b;
        b = t;
        i++;
    } while (b <= n);
    return i;
}

// 5.2.c

unsigned fib_greater_than(uint64_t n)
{
    return fib_less_than(n + 1) + 1;
}

// 5.2.d

uint64_t sum_less_than(uint64_t n)
{
    unsigned t = fib_less_than(n + 1);
    uint64_t s = 0;
    for (unsigned i = 1; i <= t; i++)
    {
        s += fib_n2(i);
    }
    return n;
}

int task5_2(void)
{
    // fib functions example

    puts("fib1:");
    for (unsigned n = 0; n < 10; n++)
    {
        printf("fib[%u] = %" PRIu64 "\n", n, fib_n1(n));
    }
    puts("fib2:");
    for (unsigned n = 0; n < 10; n++)
    {
        printf("fib[%u] = %" PRIu64 "\n", n, fib_n2(n));
    }

    // 5.2.b usage example

    uint64_t n;
    scanf("%" SCNu64, &n);
    unsigned i = fib_less_than(n);
    printf("fib # = %u\n", i);
    printf("fib %u = %" PRIu64 "\n", i, fib_n1(i));
}

unsigned steps_to_1(uint64_t n)
{
    unsigned steps = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        steps += 1;
    }
    return steps;
}

int task5_3(void)
{
    unsigned max_n, max_steps = 0;
    for (unsigned i = 1; i <= 1000; i++)
    {
        unsigned steps = steps_to_1(i);
        if (steps > max_steps)
        {
            max_steps = steps;
            max_n = i;
        }
    }
    printf("max steps `%u` for numer %u\n", max_steps, max_n);
}

int task5_4(void)
{
    unsigned n;
    scanf("%u", &n);
    // a)
    double prod = 1., q = 1.;
    for (unsigned i = 1; i <= n; i++)
    {
        q /= i;
        prod *= 1. + q;
    }
    printf("a) %lf\n", prod);

    // b)
    prod = 1., q = -1.;
    for (unsigned i = 3; i <= n; i++)
    {
        q *= i * i / -2.;
        prod *= 1. + q;
    }
    printf("b) %lf\n", prod);
}

int task5_5(void)
{
    int a = -99, b = -99, c = -99;
    unsigned n = 3;
    while (a <= 0)
    {
        int t = a + c + 100;
        c = b;
        b = a;
        a = t;
        n++;
    }
    printf("s[%u] = %d\n", n, a);
}

// a)
double b_n(double b, unsigned n)
{
    double bn = b;
    while (n--)
    {
        bn = b + 1. / bn;
    }
    return bn;
}

// b)
double l_n(unsigned n)
{
    double ln = 4 * n + 2;
    while (n--)
    {
        ln = 4. * n + 2. + 1. / ln;
    }
    return ln;
}

// c)
double x_2n(unsigned n)
{
    double x_2n = 1.5;
    while (n--)
    {
        x_2n = 1. / (1. / x_2n + 2.) + 1.;
    }
    return x_2n;
}

int task5_6(void)
{
    double b;
    unsigned n;
    scanf("%lf%u", &b, &n);

    // a)
    printf("a) b_n(%lf, %u) = %lf\n", b, n, b_n(b, n));
    // b)
    printf("b) l_n(%u) = %lf\n", n, l_n(n));
    // c)
    printf("c) x_2n(%u) = %lf\n", n, x_2n(n));
}

double sn(unsigned n)
{
    if (n < 2)
    {
        return 2. * n;
    }
    double sum = 6., k2 = 4.;
    double a0 = 1., a1 = 0., b0 = 1.;
    for (int i = 3; i <= n; i++)
    {
        b0 += a0;
        k2 *= 2.;
        double a_k = a0 / i + a1 * b0;
        a1 = a0;
        a0 = a_k;
        sum += k2 / (a0 + b0);
    }
    return sum;
}

int task5_7(void)
{
    unsigned n;
    scanf("%u", &n);

    printf("%lf", sn(n));
}


int main(){
    task5_1();
    task5_2();
    task5_3();
    task5_4();
    task5_5();
    task5_6();
    task5_7();
}