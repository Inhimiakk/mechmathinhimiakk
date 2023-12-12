#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

void task20_1()
{
    std::map<std::string, unsigned> wordCount;
    std::string word;

    while (std::cin >> word)
    {
        wordCount[word]++;
    }

    for (const auto &pair : wordCount)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

void task20_2()
{
    size_t n;
    std::cin >> n;

    std::set<int> numbers;
    for (size_t i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        numbers.insert(value);
    }

    while (numbers.size() > 1)
    {
        std::set<int> newNumbers;
        auto it = numbers.begin();
        int previous = *it++;
        while (it != numbers.end())
        {
            int current = *it++;
            newNumbers.insert(current + previous);
            previous = current;
        }
        numbers = std::move(newNumbers);
    }

    std::cout << *numbers.begin() << std::endl;
}

struct Point
{
    int x, y;

    Point(int _x, int _y) : x(_x), y(_y) {}

    double length() const
    {
        return std::sqrt(x * x + y * y);
    }
};

bool compareSegments(const std::pair<Point, Point> &a, const std::pair<Point, Point> &b)
{
    return a.first.length() < b.first.length();
}

int task20_3()
{
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    std::vector<std::pair<Point, Point>> segments;

    char ch;
    while (inputFile >> ch && ch == '(')
    {
        int x1, y1, x2, y2;
        inputFile >> x1 >> ch >> y1 >> ch;
        inputFile >> ch;                   
        inputFile >> x2 >> ch >> y2 >> ch;
        inputFile >> ch;                   

        segments.push_back({Point(x1, y1), Point(x2, y2)});
    }

    std::sort(segments.begin(), segments.end(), compareSegments);

    for (const auto &segment : segments)
    {
        outputFile << "(" << segment.first.x << ", " << segment.first.y
                   << ") (" << segment.second.x << ", " << segment.second.y << ")\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

int main()
{
    task20_1();
    task20_2();
    task20_3();

    return 0;
}
