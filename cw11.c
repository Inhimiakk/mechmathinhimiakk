#include <stdio.h>
#include <stdlib.h>
#include <binfiles.h>
#include <Main.h>

int task11_1(){
    int n;
    printf("n=");
    scanf_s("%d", &n);

    double *mas = (double *)malloc(n * sizeof(*mas));
    if(!mas) {
        printf("memory error");
        return;
    }

    for (int i = 0; i < n; i++){
        printf("a[%d]", i);
        scanf_s("%lf", &mas[i]);
    }

    char fname[256;]
    printf("Filename");
    scanf_s("%s", fname);

    int r = writeIntoFile(fname, mas, n);
    printf("we write %d doubles inti %s", r, fname);

    double *out_arr = (double *)calloc(n, sizeof(*out_arr));
    r = readFromFile(fname, out_arr);

    for (int i = 0; i < r; i++){
        printf("arr[%d]= %lf\n", i, out_arr[i]);
    }

        free(mas);
    free(out_arr);
}

int task11_2()
{
    int n;
    printf("n=");
    scanf_s("%d", &n);

    double *mas = (double *)malloc(n * sizeof(*mas));
    if (!mas)
    {
        printf("memory error");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("a[%d]", i);
        scanf_s("%lf", &mas[i]);
    }

    char fname[256;]
    printf("Filename");
    scanf_s("%s", fname);

    int r = writeIntoFile(fname, mas, n);
    printf("we write %d doubles inti %s", r, fname);

    double a;
    printf("a=");
    scanf("%lf", &a);

    double *out_arr = (double *)calloc(n, sizeof(*out_arr));
    r = readFromFile(fname, out_arr, false);

    for (int i = 0; i < r; i++)
    {
        if (fabs(out_arr[i])<a)
        {
        }
        printf("arr[%d]= %lf\n", i, out_arr[i]);
    }

    free(mas);
    free(out_arr);
}
#include <stdio.h>

int task11_3()
{
    FILE *fileF, *fileG;
    int number;

    fileF = fopen("F.txt", "w");

    if (fileF == NULL)
    {
        printf("Не вдалося відкрити файл F для запису.\n");
        return 1;
    }

    printf("Введіть цілі числа (введіть 0 для завершення вводу):\n");

    while (1)
    {
        scanf("%d", &number);

        if (number == 0)
        {
            break;
        }

        fprintf(fileF, "%d\n", number);
    }

    fclose(fileF);

    fileF = fopen("F.txt", "r");
    fileG = fopen("G.txt", "w");

    if (fileF == NULL || fileG == NULL)
    {
        printf("Не вдалося відкрити файли для читання або запису.\n");
        return 1;
    }

    while (fscanf(fileF, "%d", &number) != EOF)
    {
        if (number != 0 && number % 3 == 0)
        {
            fprintf(fileG, "%d\n", number);
        }
    }

    fclose(fileF);
    fclose(fileG);

    printf("Операція завершена. Результат записано у файл G.txt.\n");

    return 0;
}

typedef struct
{
    float x, y;
} Vertex;

typedef struct
{
    Vertex a, b;
} Rect;

int max_rect_index(const char *filename, float *max_area_out)
{
    FILE *f = fopen(filename, "rb");
    Rect r;
    int i = 0, max_i = 0;
    float max_area = 0.;
    while (!feof(f) && fread(&r, sizeof(r), 1, f) == 1)
    {
        float area = abs((r.a.x - r.b.x) * (r.a.y - r.b.y));
        if (area > max_area)
        {
            max_area = area;
            max_i = i;
        }
        i += 1;
    }
    fclose(f);
    if (max_area_out)
    {
        *max_area_out = max_area;
    }
    return i;
}

void replace_rect_index(const char *filename, int index, Rect r)
{
    FILE *f = fopen(filename, "wb");
    fseek(f, index * sizeof(Rect), SEEK_SET);
    fwrite(&r, sizeof(Rect), 1, f);
    fclose(f);
}

int task11_4(void)
{
    const char *filename = "file.rects";
    // usage example
    replace_rect_index(filename, max_rect_index(filename, NULL), (Rect){{0.f, 0.f}, {1.f, 1.f}});
}

//homework

int task11_9a()
{
    FILE *fileF, *fileG, *fileH;
    int number;
    int positiveCount = 0;
    int negativeCount = 0;

    fileF = fopen("F.txt", "r");

    if (fileF == NULL)
    {
        printf("Не вдалося відкрити файл F для читання.\n");
        return 1;
    }

    while (fscanf(fileF, "%d", &number) != EOF)
    {
        if (number > 0)
        {
            positiveCount++;
        }
        else if (number < 0)
        {
            negativeCount++;
        }
    }

    if (positiveCount != negativeCount)
    {
        printf("Кількість додатних і від'ємних чисел в файлі F не рівна.\n");
        printf("Операція завершена без змін.\n");
        fclose(fileF);
        return 1;
    }

    fileF = fopen("F.txt", "r");
    fileG = fopen("G.txt", "w");
    fileH = fopen("H.txt", "w");

    if (fileF == NULL || fileG == NULL || fileH == NULL)
    {
        printf("Не вдалося відкрити файли для читання або запису.\n");
        return 1;
    }

    int currentNumber, previousNumber;

    if (fscanf(fileF, "%d", &previousNumber) != EOF)
    {
        fprintf(fileG, "%d\n", previousNumber);
    }

    while (fscanf(fileF, "%d", &currentNumber) != EOF)
    {
        if (currentNumber * previousNumber < 0)
        {

            fprintf(fileG, "%d\n", currentNumber);
        }
        else
        {

            fprintf(fileH, "%d\n", currentNumber);
        }
        previousNumber = currentNumber;
    }


    fclose(fileF);
    fclose(fileG);
    fclose(fileH);

    printf("Результат записано у файли G.txt та H.txt.\n");

    return 0;
}

typedef struct
{
    int passengerNumber;
    int numberOfItems;
    float totalWeight;
} Baggage;

typedef struct
{
    char lastName[50];
} Passenger;

void readPassengersFile(Passenger *passengers, int *numberOfPassengers, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Не вдалося відкрити файл %s для читання.\n", filename);
        exit(1);
    }

    *numberOfPassengers = 0;

    while (fscanf(file, "%s", passengers[*numberOfPassengers].lastName) != EOF)
    {
        (*numberOfPassengers)++;
    }

    fclose(file);
}

void readBaggageFile(Baggage *baggage, int numberOfPassengers, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Не вдалося відкрити файл %s для читання.\n", filename);
        exit(1);
    }

    for (int i = 0; i < numberOfPassengers; i++)
    {
        fscanf(file, "%d %d %f", &baggage[i].passengerNumber, &baggage[i].numberOfItems, &baggage[i].totalWeight);
    }

    fclose(file);
}

void passengersWithMoreThanTwoItems(Baggage *baggage, int numberOfPassengers)
{
    printf("Пасажири, які мають понад двоє речей:\n");

    for (int i = 0; i < numberOfPassengers; i++)
    {
        if (baggage[i].numberOfItems > 2)
        {
            printf("%d. %s\n", baggage[i].passengerNumber, "passengerLastName");
        }
    }

    printf("\n");
}

void passengersWithMoreItemsThanAverage(Baggage *baggage, int numberOfPassengers)
{
    int totalItems = 0;

    for (int i = 0; i < numberOfPassengers; i++)
    {
        totalItems += baggage[i].numberOfItems;
    }

    float averageItems = (float)totalItems / numberOfPassengers;

    printf("Пасажири, кількість речей у яких більша за середню кількість:\n");

    for (int i = 0; i < numberOfPassengers; i++)
    {
        if (baggage[i].numberOfItems > averageItems)
        {
            printf("%d. %s\n", baggage[i].passengerNumber, "passengerLastName");
        }
    }

    printf("\n");
}

int task11_11b()
{
    const char *passengersFilename = "passengers.txt";
    const char *baggageFilename = "baggage.txt";

    int numberOfPassengers;
    Passenger *passengers;

    readPassengersFile(passengers, &numberOfPassengers, passengersFilename);

    Baggage *baggage = (Baggage *)malloc(numberOfPassengers * sizeof(Baggage));

    readBaggageFile(baggage, numberOfPassengers, baggageFilename);

    passengersWithMoreThanTwoItems(baggage, numberOfPassengers);
    passengersWithMoreItemsThanAverage(baggage, numberOfPassengers);

    free(passengers);
    free(baggage);

    return 0;
}


// int main(){
//     task11_1();
//     task11_2();
//     task11_3();
//     task11_4();
//     task11_9a();
//     task11_11b();
// }