#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int task7_1(){
    int listint[5] = {4, 56, 78, 905, 6};
    double d;
    int count = 0;
    int N = sizeof(listint) / sizeof(int);
    printf("d = ");
    scanf("%lf", &d);

    for (int i = 0; i < N; i++){
        if(listint[i]< d){
            count++;
        }
    }
    printf("count = %d", count);
}

void task7_2(){
    int mas[] = {5, 112, 4, 3};
    int N = sizeof(mas) / sizeof(mas[0]);
    for (int i = 1; i > 0; i--){
        printf("%d\t", mas[i]);
    }
}

int task7_3(){
    int N = 10;
    double mas[N];
    double sum = 0;
    for (int i = 0; i < 10; i++){
        printf("napishi element v masiv pojalusto a[%d]: ", i);
        scanf("%lf", &mas[i]);
        if(mas[i]>M_E){
            sum += mas[i];
        }
    }
    printf("sum num> m_e = %lf", sum);
}

int task7_4()
{
    int N = 5;
    int mas[N];
    int maxel;

    for (int i = 0; i < 5; i++)
    {
        printf("napishi element v masiv pojalusto a[%d]: ", i);
        scanf("%d", &mas[i]);
    
        if (i == 0)
        {
            maxel = mas[0];
        }
        else if (mas[i] > maxel)
        {
            maxel = mas[i];
        }
    } 
        
    printf("max_el %d", maxel);
}

int task7_5()
{
    unsigned mas[50];
    int parni;
    int neparni;

    for (int i = 0; i < 50; i++)
    {
        printf("napishi element v masiv pojalusto a[%d]: ", i);
        scanf("%u", &mas[i]);

        if (mas[i] == 0)
        {
            break;
        }

        if (mas[i] % 2 == 0 )
        {
            parni ++;
        }
        else {
            neparni ++ ;
        }

        
    }

    printf("parni = %d neparni = %d", parni, neparni);
}

void scan_vec(double *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("vec[%d] = ", i);
        scanf("%lf", array + i);
    }
}

void print_vec(const double *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("vec[%d] = %lf\n", i, array[i]);
    }
}

void vec_sum(const double *a, const double *b, double *c, int n)
{
    while (n--)
    {
        *c++ = *a++ + *b++;
    }
}

double vec_dot(const double *a, const double *b, int n)
{
    double result = 0;
    while (n--)
    {
        result += *a++ * *b++;
    }
    return result;
}

int task7_6(void)
{
    int n;
    scanf("%d", &n);

    double a[20], b[20], c[20];
    printf("vec_a:\n");
    scan_vec(a, n);
    printf("vec_b:\n");
    scan_vec(b, n);

    vec_sum(a, b, c, n);
    double prod = vec_dot(a, b, n);

    printf("dot: %lf\nsum:\n", prod);
    print_vec(c, n);
}




//homework


int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}


int isPerfectSquare(int n)
{
    int root = sqrt(n);
    return (root * root == n);
}

int task7_8a()
{
    int N;
    printf("Ввкдіть розмір маству: ");
    scanf("%d", &N);

    int numbers[N];
    int countPerfectSquarePrimes = 0;

    printf("Введіть %d натуральних чисел:\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);

        if (isPerfectSquare(numbers[i]) && isPrime(numbers[i]))
        {
            countPerfectSquarePrimes++;
        }
    }

    printf("Серед введених чисел знайдено %d повних квадратів простих чисел.\n", countPerfectSquarePrimes);

    return 0;
}

#include <stdio.h>

int task7_15()
{
    long long number;
    printf("Введіть ціле число: ");
    scanf("%lld", &number);

    int digitCount[10] = {0}; 

    while (number != 0)
    {
        int digit = number % 10;
        digitCount[digit]++;
        number /= 10;
    }

    int maxCount = 0;          
    int mostFrequentDigit = 0; 

    for (int i = 0; i < 10; i++)
    {
        if (digitCount[i] >= maxCount)
        {
            maxCount = digitCount[i];
            mostFrequentDigit = i;
        }
    }

    printf("Цифра десяткового запису, яка зустрічається найбільшу кількість разів: %d\n", mostFrequentDigit);

    return 0;
}

int main()
{
    // task7_1();
    // task7_2();
    // task7_3();
    // task7_4();
    // task7_5();
    // task7_6();
    // task7_8a();
    task7_15();
    }
