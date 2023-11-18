#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Task 1

typedef struct
{
    uint16_t year;
    uint16_t month;
    uint16_t day;
} Date;

typedef struct
{
    uint8_t r : 3;
    uint8_t f : 3;
} ChessSquare;

typedef struct
{
    float x, y;
} Point;

typedef struct
{
    Point a, b;
} AARect;

typedef struct
{
    size_t n;
    // array from n+1 element;
    double *coefficients;
} Poly;

void input_date(Date *date)
{
    scanf("%" SCNu16 "%" SCNu16 "%" SCNu16, &date->day, &date->month, &date->year);
}

void print_date(const Date *date)
{
    printf("%" PRIu16 ".%" PRIu16 ".%" PRIu16, date->day, date->month, date->year);
}

bool input_square(ChessSquare *square)
{
    char f, r;
    if (2 != scanf("%c%c", &f, &r))
        return false;
    f = toupper(f);
    if (f < 'A' || f > 'H' || r < '1' || r > '7')
        return false;
    square->f = f - 'A';
    square->r = r - '1';
    return true;
}

void print_square(const ChessSquare *square)
{
    printf("%c%c", (char)(square->f + 'A'), (char)(square->r + '1'));
}

void input_rect(AARect *rect)
{
    scanf("%f%f%f%f", &rect->a.x, &rect->a.y, &rect->b.x, &rect->b.y);
}

void print_rect(const AARect *rect)
{
    printf("(%f, %f) (%f, %f)", rect->a.x, rect->a.y, rect->b.x, rect->b.y);
}

void free_poly(Poly *poly)
{
    if (poly->coefficients)
    {
        free(poly->coefficients);
    }
}

void input_poly(Poly *poly)
{
    free_poly(poly);
    size_t n;
    scanf("%zu", &n);
    poly->n = n;
    poly->coefficients = (double *)malloc(sizeof(double) * (n + 1));
    for (size_t i = 0; i <= n; i++)
        scanf("%lf", poly->coefficients + i);
}

void print_poly(const Poly *poly)
{
    if (!poly || !poly->coefficients)
        return;
    printf("%zu", poly->n);
    for (size_t i = poly->n; i >= 1; i--)
        printf("%lf * x^%zu + ", poly->coefficients[i], i);
    printf("%lf", poly->coefficients[0]);
}

int task10_1(void)
{
    Poly poly = {0};
    input_poly(&poly);
    poly.coefficients[0] = 42;
    print_poly(&poly);
    free_poly(&poly);
}

//Task 2

typedef struct
{
    uint8_t r : 3;
    uint8_t f : 3;
} ChessSquare;



bool can_queen_move(ChessSquare from, ChessSquare to)
{
    return from.r == to.r || from.f == to.f ||
           from.r - from.f == to.r - to.f ||
           from.r + from.f == to.r + to.f;
}

int task10_2(void)
{
    ChessSquare a, b;
    bool is_corect_input = input_square(a) && input_square(b);
    if (!is_corect_input)
    {
        printf("incorrect input\n");
        return 0;
    }
    printf("%s", can_queen_move(a, b) ? "true" : "false");
}

//Task 3

typedef struct
{
    uint16_t year;
    uint16_t month;
    uint16_t day;
};

bool is_leap_year(uint16_t y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

uint16_t days_in_month(uint16_t m, bool is_leap)
{
    const uint8_t d[12] = {0};
    return d[m] + (uint16_t)(is_leap && m == 1);
}

int task10_3() { *(char *)0 = 0; }

//Task 4

typedef struct
{
    int numerator;
    unsigned denumerator;
} Rational;

inline Rational rat_from_int(int num)
{
    return (Rational){num, 1};
}

inline void rat_display(Rational rat)
{
    printf("%d/%u", rat.numerator, rat.denumerator);
}

inline Rational rat_simplify(Rational rat)
{
    // TODO
    return rat;
}

inline Rational rat_add(Rational a, Rational b)
{
    b.numerator *= a.denumerator;
    a.numerator *= b.denumerator;
    a.denumerator *= b.denumerator;
    a.numerator += b.numerator;
    return rat_simplify(a);
}

inline Rational rat_sub(Rational a, Rational b)
{
    b.numerator *= a.denumerator;
    a.numerator *= b.denumerator;
    a.denumerator *= b.denumerator;
    a.numerator -= b.numerator;
    return rat_simplify(a);
}

inline Rational rat_mul(Rational a, Rational b)
{
    a.numerator *= b.numerator;
    a.denumerator *= b.denumerator;
    return rat_simplify(a);
}

inline Rational rat_div(Rational a, Rational b)
{
    a.denumerator *= b.numerator;
    a.numerator *= b.denumerator;
    return rat_simplify(a);
}

inline int rat_cmp(Rational a, Rational b)
{
    if (a.numerator == b.numerator && a.denumerator == b.denumerator)
        return 0;
    // TODO
    return -1;
}

int task10_4(void)
{
    return 0;
}

//Task 5

typedef struct
{
    char name[50];
    double height;
} Mountain;

void inputMountains(Mountain *mountains, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Введіть назву гори %d: ", i + 1);
        scanf("%s", mountains[i].name);

        printf("Введіть висоту гори %d: ", i + 1);
        scanf("%lf", &mountains[i].height);
    }
}

void outputMountains(Mountain *mountains, int n)
{
    printf("Інформація про гори:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Гора %d: Назва: %s, Висота: %.2f метрів\n", i + 1, mountains[i].name, mountains[i].height);
    }
}

Mountain findTallestMountain(Mountain *mountains, int n)
{
    Mountain tallest = mountains[0];

    for (int i = 1; i < n; i++)
    {
        if (mountains[i].height > tallest.height)
        {
            tallest = mountains[i];
        }
    }

    return tallest;
}

void printHeightByName(Mountain *mountains, int n, const char *name)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(mountains[i].name, name) == 0)
        {
            printf("Висота вершини %s: %.2f метрів\n", name, mountains[i].height);
            return;
        }
    }

    printf("Вершину з назвою %s не знайдено\n", name);
}

int task10_5()
{
    int n;

    printf("Введіть кількість гір: ");
    scanf("%d", &n);

    Mountain *mountains = (Mountain *)malloc(n * sizeof(Mountain));

    if (mountains == NULL)
    {
        printf("Помилка виділення пам'яті\n");
        return 1; // Повертаємо код помилки
    }

    inputMountains(mountains, n);

    outputMountains(mountains, n);

    Mountain tallest = findTallestMountain(mountains, n);
    printf("Найвища вершина: %s, висота: %.2f метрів\n", tallest.name, tallest.height);

    char searchName[50];
    printf("Введіть назву вершини для пошуку висоти: ");
    scanf("%s", searchName);
    printHeightByName(mountains, n, searchName);

    free(mountains);

    return 0;
}

//homework
//Task 6г

typedef struct
{
    char city[50];
    char street[50];
    int houseNumber;
    int apartmentNumber;
} Address;

void inputAddress(Address *address)
{
    printf("Введіть місто: ");
    scanf("%s", address->city);

    printf("Введіть вулицю: ");
    scanf("%s", address->street);

    printf("Введіть номер будинку: ");
    scanf("%d", &address->houseNumber);

    printf("Введіть номер квартири: ");
    scanf("%d", &address->apartmentNumber);
}

void outputAddress(Address address)
{
    printf("Адреса: %s, %s, буд. %d, кв. %d\n", address.city, address.street, address.houseNumber, address.apartmentNumber);
}

int task10_6g(void)
{
    Address myAddress;

    printf("Введіть вашу адресу:\n");
    inputAddress(&myAddress);

    printf("\nВаша адреса:\n");
    outputAddress(myAddress);

    return 0;
}

//Task13(a-в)
#include <stdio.h>
#include <string.h>

typedef struct
{
    char lastName[50];
    char firstName[50];
    char gender; // 'M' або 'F'
    int birthDay;
    int birthMonth;
    int birthYear;
    char position[50];
} EmployeeProfile;

void inputEmployeeProfile(EmployeeProfile *employee)
{
    printf("Введіть прізвище: ");
    scanf("%s", employee->lastName);

    printf("Введіть ім'я: ");
    scanf("%s", employee->firstName);

    printf("Введіть стать (M або F): ");
    scanf(" %c", &employee->gender);

    printf("Введіть день народження: ");
    scanf("%d", &employee->birthDay);

    printf("Введіть місяць народження: ");
    scanf("%d", &employee->birthMonth);

    printf("Введіть рік народження: ");
    scanf("%d", &employee->birthYear);
}

void outputEmployeeProfile(EmployeeProfile employee)
{
    printf("Прізвище: %s\n", employee.lastName);
    printf("Ім'я: %s\n", employee.firstName);
    printf("Стать: %c\n", employee.gender);
    printf("Дата народження: %d.%d.%d\n", employee.birthDay, employee.birthMonth, employee.birthYear);
    printf("\n");
}

void findMostCommonPosition(EmployeeProfile *profiles, int n)
{
    int maxCount = 0;
    char mostCommonPosition[50] = "";

    for (int i = 0; i < n; i++)
    {
        int currentCount = 1; 

        if (profiles[i].position[0] == '\0')
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(profiles[i].position, profiles[j].position) == 0)
            {
                currentCount++;
                profiles[j].position[0] = '\0';
            }
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            strcpy(mostCommonPosition, profiles[i].position);
        }
    }

    if (maxCount > 0)
    {
        printf("Посада, яку обіймає найбільша кількість співробітників: %s\n", mostCommonPosition);
    }
    else
    {
        printf("Немає інформації про посади співробітників.\n");
    }
}

void findEmployeesWithSameName(EmployeeProfile *profiles, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (profiles[i].firstName[0] == '\0')
        {
            continue;
        }

        printf("Співробітники з ім'ям %s:\n", profiles[i].firstName);

        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(profiles[i].firstName, profiles[j].firstName) == 0)
            {
                outputEmployeeProfile(profiles[j]);
                profiles[j].firstName[0] = '\0';
            }
        }

        printf("\n");
    }
}

void findEmployeesByLastNameLetter(EmployeeProfile *profiles, int n, char letter)
{
    printf("Співробітники, прізвище яких починається із літери %c:\n", letter);
    for (int i = 0; i < n; i++)
    {
        if (profiles[i].lastName[0] == letter)
        {
            outputEmployeeProfile(profiles[i]);
        }
    }
    printf("\n");
}
int task10_13ac()
{
    int n;

    printf("Введіть кількість співробітників: ");
    scanf("%d", &n);

    EmployeeProfile *employeeProfiles = malloc(n * sizeof(EmployeeProfile));

    for (int i = 0; i < n; i++)
    {
        printf("\nВведення даних для співробітника %d:\n", i + 1);
        inputEmployeeProfile(&employeeProfiles[i]);
    }

    printf("\nАнкети співробітників:\n");
    for (int i = 0; i < n; i++)
    {
        outputEmployeeProfile(employeeProfiles[i]);
    }

    findMostCommonPosition(employeeProfiles, n);
    findEmployeesWithSameName(employeeProfiles, n);

    char searchLetter;
    printf("\nВведіть літеру для пошуку за прізвищем: ");
    scanf(" %c", &searchLetter);
    findEmployeesByLastNameLetter(employeeProfiles, n, searchLetter);

    free(employeeProfiles);

    return 0;
}

// int main(){
//     task10_1();
//     task10_2();
//     task10_3();
//     task10_4();
//     task10_5();
//     task10_6g();
//     task10_13ac();
//     return 0;
// }
