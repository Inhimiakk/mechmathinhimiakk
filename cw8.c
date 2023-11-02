#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int task8_1(void)
{
    int mat[3][3] = {{
                         1,
                         2,
                         3,
                     },
                     {4, 5, 6},
                     {7, 8, 9}};
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i][j] == m)
                mat[i][j] = n;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);
        putchar('\n');
    }
}

int task8_2(void)
{
    double mat[3][3] = {{
                            1.0,
                            2,
                            3,
                        },
                        {4, 5, 6},
                        {7, 8, 9}};

    {
        double a;
        int i, j;
        scanf("%d%d%lf", &i, &j, &a);

        if (0 <= i && i < 3 && 0 <= j && j < 3)
            mat[i][j] = a;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%lf ", mat[i][j]);
        putchar('\n');
    }
}

void read_mat(double *mat, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%lf", &mat[i * m + j]);
        }
}

int task8_3(void)
{
    double mat[20 * 20];
    int n, m;
    scanf("%u%u", &n, &m);
    read_mat(mat, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%lf ", mat[i * m + j]);
        putchar('\n');
    }
}

int task8_4(void)
{
    double mat[25 * 25];
    int n, m;
    scanf("%u%u", &n, &m);
    read_mat(mat, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%lf ", mat[i * m + j]);
        putchar('\n');
    }
}

void transpose_mat(double *mat, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            double temp = mat[i * n + j];
            mat[i * n + j] = mat[j * n + i];
            mat[j * n + i] = temp;
        }
}

int task8_5(void)
{
    double mat[9] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9};

    transpose_mat(mat, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%lf ", mat[i * 3 + j]);
        putchar('\n');
    }
}

#define N 100
#define M 100

int task8_6(void)
{
    double a[N][M];

    unsigned n, m;
    scanf("%u%u", &n, &m);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m; j++)
            scanf("%lf", &a[i][j]);

    int k;
    scanf("%d", &k);
    unsigned k2 = k > 0 ? (unsigned)k : 0 - (unsigned)k;
    double sum = 0.;
    for (unsigned i = 0; i < n; i++)
    {
        // i - j = k
        unsigned j = i - k2;
        if (j < m)
        {
            sum += a[i][j];
        }
    }
    printf("%lf\n", sum);
}


double calc_det(double *mat, unsigned n, unsigned i, unsigned *p, unsigned used)
{
    if (i == n)
    {
        unsigned inv_count = 0;
        for (unsigned j = 0; j < n; j++)
            for (unsigned k = j + 1; k < n; k++)
            {
                if (p[k] > p[j])
                    inv_count++;
            }

        double det = 1.;
        for (unsigned j = 0; j < n; j++)
            det *= mat[j * n + p[j]];

        return inv_count & 1 ? det : -det;
    }
    double sum = 0.;
    for (unsigned j = 0; j < n; j++)
    {
        if (~used >> j & 1)
        {
            p[i] = j;
            sum += calc_det(mat, n, i + 1, p, used | 1 << j);
        }
    }
    return sum;
}

int task8_7(void)
{
    double mat[N * N];
    unsigned perm[N];

    unsigned n;
    scanf("%u", &n);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < n; j++)
        {
            // printf("m[%u][%u] = ", i, j);
            scanf("%lf", &mat[i * n + j]);
        }

    double det = calc_det(mat, n, 0, perm, 0);
    printf("det = %lf\n", det);
}


void fillSpiralCounterClockwise(int n, int arr[][n])
{
    if (n <= 0)
    {
        printf("Помилка: Невірний розмір масиву.\n");
        return;
    }

    int num = 1;
    int row = n / 2;
    int col = n / 2;
    int step = 1;

    if (row < 0 || col < 0 || row >= n || col >= n)
    {
        printf("Помилка: Початкова комірка за межами масиву.\n");
        return;
    }

    arr[row][col] = num;

    while (num < n * n)
    {
        for (int i = 0; i < step; i++)
        {
            col++;
            num++;
            if (col < n)
            {
                arr[row][col] = num;
            }
            else
            {
                printf("Помилка: Вихід за межі масиву (row: %d, col: %d)\n", row, col);
                return;
            }
        }
        for (int i = 0; i < step; i++)
        {
            row--;
            num++;
            if (row >= 0)
            {
                arr[row][col] = num;
            }
            else
            {
                printf("Помилка: Вихід за межі масиву (row: %d, col: %d)\n", row, col);
                return;
            }
        }
        step++;

        for (int i = 0; i < step; i++)
        {
            col--;
            num++;
            if (col >= 0)
            {
                arr[row][col] = num;
            }
            else
            {
                printf("Помилка: Вихід за межі масиву (row: %d, col: %d)\n", row, col);
                return;
            }
        }
        for (int i = 0; i < step; i++)
        {
            row++;
            num++;
            if (row < n)
            {
                arr[row][col] = num;
            }
            else
            {
                printf("Помилка: Вихід за межі масиву (row: %d, col: %d)\n", row, col);
                return;
            }
        }
        step++;
    }
}

int task8_11()
{
    int n;
    printf("Введіть розмір квадратного масиву n: ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("Розмір масиву повинен бути непарним.\n");
        return 1;
    }

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    fillSpiralCounterClockwise(n, arr);

    printf("Заповнений масив:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main(void){
    // task8_1();
    // task8_2();
    // task8_3();
    // task8_4();
    // task8_5();
    // task8_6();
    // task8_7();
    task8_11();
}