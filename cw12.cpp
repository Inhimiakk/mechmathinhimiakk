#include <iostream>
#include <cmath>  //pow
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int task1(){

    cout << "Hello, World!\n";
    double x, y, z;

    cout << "x= ";
    cin >> x; //input
    cout << "y= ";
    cin >> y;

    z = pow(x, y); //z  = x**y

    cout << "z= " << z << ", " << scientific << z << endl
         << "\n";
}

int task12_1()
{
    double x, y;
    std::cin >> x >> y;
    double ans = std::pow(x, y);
    std::cout << "x ^ y = " << ans << '\n'
              << "x ^ y = " << std::scientific << ans << '\n';
}

int task12_2(){
    int n = 0;
    char buf[11];
    //char **error;
    unsigned long long tmp, sums = 0;
    while(cin.getline(buf,10)){
        cout << buf;
        n++;
        tmp = strtoull(buf, nullptr, 10);
        sums += tmp;
    }
    std::cout << sum << '\n';
}

int task12_3()
{
    constexpr size_t MAX_NUM_WIDTH = 8;

    size_t n;
    std::cin >> n;

    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1); // one extra for '\n'

    std::cout << '\n';

    std::cout.fill(' ');

    for (size_t i = 1; i <= n; i++)
    {
        std::cout.width(MAX_NUM_WIDTH);
        std::cout << i;
    }
    std::cout << '\n';

    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);

    std::cout << '\n';

    std::cout.fill(' ');

    std::cout << std::setprecision(MAX_NUM_WIDTH - 2);

    for (size_t i = 1; i <= n; i++)
    {
        std::cout.width(MAX_NUM_WIDTH);
        std::cout << std::sqrt(i);
    }
    std::cout << '\n';

    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);

    std::cout << '\n';
}

int task12_4()
{
    size_t n;
    std::cin >> n;

    std::vector<int> m(n);
    std::vector<double> x(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> m[i];
    }

    constexpr const char *input_file = "data/lab12_task4_inputs.txt";
    constexpr const char *output_file = "data/lab12_task4_outputs.txt";

    {
        std::ifstream f(input_file);
        if (!f.is_open() || f.bad())
        {
            std::cout << "can't open `" << input_file << "`\n";
            return EXIT_FAILURE;
        }

        for (size_t i = 0; i < n; i++)
        {
            f >> x[i];
        }
    }

    {
        std::ofstream f(output_file);
        if (!f.is_open() || f.bad())
        {
            std::cout << "can't open `" << output_file << "`\n";
            return EXIT_FAILURE;
        }

        for (size_t i = 0; i < n; i++)
        {
            f << std::pow(x[i], m[i]) << ' ';
        }
    }
}

int task12_5()
{
    constexpr const char *input_file = "data/lab12_task5_inputs.txt";
    std::ifstream f(input_file);

    if (!f.is_open() || f.bad())
    {
        std::cout << "can't open `" << input_file << "`\n";
        return EXIT_FAILURE;
    }

    std::vector<int> nums;
    int n;
    while (f >> n)
    {
        nums.push_back(n);
    }

    std::cout << std::setprecision(4);
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << std::sqrt(nums[nums.size() - 1 - i]) << '\n';
    }
}

//homework

int task12_9()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Unable to open input file.\n";
        return 1;
    }

    std::vector<int> numbers;
    int num;
    while (inputFile >> num)
    {
        numbers.push_back(num);
    }

    inputFile.close();

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Unable to open output file.\n";
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); ++i)
    {
        if (i + 1 < numbers.size() && numbers[i] > numbers[i + 1])
        {
            numbers[i] = numbers[i] * numbers[i];
        }
        outputFile << numbers[i] << " ";
    }

    outputFile.close();

    std::cout << "Operation completed successfully.\n";

    return 0;
}

struct Point
{
    int x1, x2;
};

struct Segment
{
    Point p1, p2;
    double length;
};

double calculateDistance(const Point &p1, const Point &p2)
{
    return std::sqrt(std::pow(p2.x1 - p1.x1, 2) + std::pow(p2.x2 - p1.x2, 2));
}

bool compareSegments(const Segment &s1, const Segment &s2)
{
    return s1.length < s2.length;
}

int task12_18()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Unable to open input file.\n";
        return 1;
    }

    std::vector<Point> points;
    char dummy;
    while (inputFile >> dummy >> points.back().x1 >> dummy >> points.back().x2 >> dummy)
    {
        points.emplace_back();
    }

    inputFile.close();

    std::vector<Segment> segments;

    for (size_t i = 0; i < points.size(); ++i)
    {
        for (size_t j = i + 1; j < points.size(); ++j)
        {
            Segment segment{points[i], points[j], calculateDistance(points[i], points[j])};
            segments.push_back(segment);
        }
    }

    std::sort(segments.begin(), segments.end(), compareSegments);

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Unable to open output file.\n";
        return 1;
    }

    for (const auto &segment : segments)
    {
        outputFile << "(( " << segment.p1.x1 << " , " << segment.p1.x2 << " ), ( "
                   << segment.p2.x1 << " , " << segment.p2.x2 << " )) - Length: "
                   << segment.length << std::endl;
    }

    outputFile.close();

    std::cout << "Operation completed successfully.\n";

    return 0;
}

// int main(){
//     task1();
//     task12_1();
//     task12_2();
//     task12_3();
//     task12_4();
//     task12_5();
//     task12_9();
//     task12_18();
// }