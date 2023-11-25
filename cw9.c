#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int task9_1(void)
{
    unsigned n;
    scanf("%u", &n);
    double *arr = (double *)malloc(n * sizeof(double));

    if (!arr)
        return EXIT_FAILURE;

    for (unsigned i = 0; i < n; i++)
    {
        scanf("%lf", arr + i);
    }

    double sqr_sum = 0.;
    for (unsigned i = 0; i < n; i++)
        sqr_sum += arr[i] * arr[i];

    printf("%lf\n", sqr_sum);

    free(arr);
}


unsigned input_array(int **const arr)
{
    int *m = (int *)malloc(sizeof(int) * 100), *m_beg = m, *m_end = m + 100;
    while (m < m_end)
    {
        scanf("%d", m);
        if (*m == 0)
        {
            break;
        }
        m++;
    }
    *arr = m_beg;
    return m - m_beg;
}

int task9_2(void)
{
    int *arr;
    unsigned n = input_array(&arr);

    int squares = 0, cubes = 0;
    for (unsigned i = 0; i < n; i++)
    {
        int num = arr[i];
        bool is_sqruare = false, is_cube = false;
        // naive check
        for (unsigned j = 1; j * j <= num; j++)
        {
            is_sqruare |= j * j == num;
            is_cube |= j * j * j == num;
        }
        squares += is_sqruare;
        cubes += is_cube;
    }
    printf("squares: %d cubes: %d\n", squares, cubes);
    free(arr);
}

typedef struct
{
    double *data;
    size_t size;
} Vec;

static inline Vec vec_allocate(size_t size)
{
    return (Vec){.data = (double *)malloc(sizeof(double) * size), .size = size};
}

static inline void vec_free(Vec vec)
{
    if (vec.data)
        free(vec.data);
}

static inline Vec vec_null()
{
    return (Vec){.data = 0, .size = 0};
}

static inline Vec vec_input(size_t size)
{
    const Vec vec = vec_allocate(size);
    double *v = vec.data;
    while (size--)
        scanf("%lf", v++);
    return vec;
}

static inline bool vec_is_valid(Vec vec)
{
    return vec.data != 0;
}

static inline Vec vec_sub(Vec a, Vec b)
{
    if (a.size != b.size || !vec_is_valid(a) || !vec_is_valid(b))
    {
        return vec_null();
    }
    Vec c = vec_allocate(a.size);
    for (size_t i = 0; i < a.size; i++)
    {
        c.data[i] = a.data[i] - b.data[i];
    }
    return c;
}

int task9_3(void)
{
    size_t n;
    scanf("%zu", &n);

    Vec a = vec_input(n);
    Vec b = vec_input(n);
    Vec c = vec_sub(a, b);

    if (vec_is_valid(c))
    {
        for (size_t i = 0; i < n; i++)
        {
            printf("%lf ", c.data[i]);
        }
    }

    vec_free(a);
    vec_free(b);
    vec_free(c);
}

typedef struct
{
    size_t rows, collumns, elems_capacity;
    double *data;
} Matrix;

Matrix mat_alloc(size_t rows, size_t collumns)
{
    // space for 1 extra row + collumn
    size_t capacity = (rows + 1) * (collumns + 1);

    double *data = (double *)malloc(capacity * sizeof(*data));

    return (Matrix){
        .rows = rows,
        .collumns = collumns,
        .elems_capacity = capacity,
        .data = data};
}

void mat_free(Matrix mat)
{
    if (mat.data)
    {
        free(mat.data);
    }
}

void mat_insert_row(Matrix *mat, size_t at)
{
    if (!mat->data)
        return;
    bool resize = mat->elems_capacity < (mat->rows + 1) * mat->collumns;
    if (resize)
    {
        // TODO exp. resize funct
        double *new_buf = (double *)malloc(sizeof(*mat->data) * (mat->elems_capacity * 2 + mat->collumns));
        memcpy(new_buf, mat->data, sizeof(*mat->data) * at * mat->collumns);
        memset(new_buf + at * mat->collumns, 0, sizeof(*mat->data) * mat->collumns);
        memcpy(
            new_buf + (at + 1) * mat->collumns,
            mat->data + at * mat->collumns,
            sizeof(*mat->data) * (mat->rows - at) * mat->collumns);
        mat->rows += 1;
        free(mat->data);
        mat->data = new_buf;
        return;
    }

    memmove(
        mat->data + (at + 1) * mat->collumns,
        mat->data + at * mat->collumns,
        sizeof(*mat->data) * (mat->rows - at) * mat->collumns);

    memset(mat->data + at * mat->collumns, 0, sizeof(*mat->data) * mat->collumns);
    mat->rows += 1;
}

int task9_4(void)
{
    size_t n, m;
    scanf("%zu%zu", &n, &m);

    Matrix mat = mat_alloc(n, m);
    for (unsigned i = 0; i < mat.rows; i++)
        for (unsigned j = 0; j < mat.collumns; j++)
        {
            scanf("%lf", mat.data + i * mat.collumns + j);
        }

    mat_insert_row(&mat, n / 2);

    for (unsigned i = 0; i < mat.rows; i++)
    {
        for (unsigned j = 0; j < mat.collumns; j++)
        {
            printf("%lf ", *(mat.data + i * mat.collumns + j));
        }
        putchar('\n');
    }

    mat_free(mat);
}

int **allocateMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int determinant2x2(int a, int b, int c, int d)
{
    return a * d - b * c;
}

int determinant3x3(int **matrix)
{
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int rank(int **matrix, int rows, int cols)
{
    int rank = 0;

    for (int row = 0; row < rows; ++row)
    {
        int nonZeroFound = 0;

        for (int col = 0; col < cols; ++col)
        {
            if (matrix[row][col] != 0)
            {
                nonZeroFound = 1;
                break;
            }
        }

        if (nonZeroFound)
        {
            ++rank;

            for (int i = row + 1; i < rows; ++i)
            {
                int factor = matrix[i][row] / matrix[row][row];

                for (int j = 0; j < cols; ++j)
                {
                    matrix[i][j] -= factor * matrix[row][j];
                }
            }
        }
    }

    return rank;
}

int task9_5()
{
    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    int **matrix = allocateMatrix(rows, cols);

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (rows == cols)
    {
        if (rows == 2)
        {
            int det2x2 = determinant2x2(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
            printf("Детермінант 2x2 матриці: %d\n", det2x2);
        }
        else if (rows == 3)
        {
            int det3x3 = determinant3x3(matrix);
            printf("Детермінант 3x3 матриці: %d\n", det3x3);
        }
    }
    else
    {
        printf("Матриця не є квадратною, не можна обчислити детермінант.\n");
    }

    int r = rank(matrix, rows, cols);
    printf("Ранг матриці: %d\n", r);

    freeMatrix(matrix, rows);

    return 0;
}

double **allocateDoubleMatrix(int rows, int cols)
{
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

void printMatrix(double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double getRandomNumber()
{
    return (double)rand() / RAND_MAX; // Генерація від 0 до 1
}

void fillMatrix(double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = getRandomNumber();
        }
    }
}
void deleteColumn(double **matrix, int rows, int cols, int k)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = k; j < cols - 1; ++j)
        {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
}

void freeMatrixx(int rows, double **matrix)
{
    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int task9_9k()
{
    srand((unsigned int)time(NULL)); // Ініціалізація генератора випадкових чисел

    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    double **matrix = allocateDoubleMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);

    printf("Початкова матриця:\n");
    printMatrix(matrix, rows, cols);

    int k;
    printf("Введіть номер стовпця для видалення: ");
    scanf("%d", &k);

    if (k >= 0 && k < cols)
    {
        deleteColumn(matrix, rows, cols, k);

        cols--;

        printf("Матриця після видалення стовпця %d:\n", k);
        printMatrix(matrix, rows, cols);
    }
    else
    {
        printf("Номер стовпця для видалення некоректний.\n");
    }

    freeMatrixx(rows, matrix);

    return 0;
}

// int main()
// {
//     task9_1();
//     task9_2();
//     task9_3();
//     task9_4();
//     task9_5();
//     task9_9k();

//     return 0;
// }