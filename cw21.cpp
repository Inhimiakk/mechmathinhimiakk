#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <string_view>
#include <numeric>
#include <ctime>
#include <fstream>
#include <set>

int task 21_1(){

}

int task21_2()
{
    size_t n;
    int x;
    std::cin >> n >> x;
    std::list<int> l;

    for (size_t i = 0; i < n; i++)
    {
        int v;
        std::cin >> v;
        l.push_back(v);
    }

    l.sort([x](int a, int b)
           { return (a < x) != (b < x) && a < b; });

    for (auto v : l)
    {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int task21_3()
{
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);

    for (auto &v : nums)
    {
        std::cin >> v;
    }

    std::partial_sort(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>{});
    int sum_largest = std::accumulate(nums.begin(), nums.begin() + k, 0);
    std::cout << sum_largest << std::endl;

    std::partial_sort(nums.begin(), nums.begin() + k, nums.end());

    // first k smallest
    for (size_t i = 0; i < k; i++)
    {
        std::cout << nums[i] << ' ';
    }
}

int task21_4()
{
    size_t n;
    std::cin >> n;
    std::vector<clock_t> clocks(n);
    std::generate(clocks.begin(), clocks.end(), clock);
    size_t new_size = std::unique(clocks.begin(), clocks.end()) - clocks.begin();
    clocks.resize(new_size);
    std::copy(clocks.begin(), clocks.end(), std::ostream_iterator<clock_t>(std::cout));
}

int task21_5()
{
    std::string s;
    std::cin >> s;
    std::transform(s.begin(), s.end(), s.begin(), [](char ch)
                   { return static_cast<char>(static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(ch)))); });
    std::cout << s;
}

int task21_6()
{
    size_t n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (auto &v : nums)
    {
        std::cin >> v;
    }

    int sum = 0;

    std::for_each(nums.begin(), nums.end(), [&sum](int v)
                  { sum += v; });

    std::cout << sum << std::endl;
}

int task21_7()
{
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    do
    {
        std::cout << s << std::endl;
    } while (std::next_permutation(s.begin(), s.end()));
}

int task21_8()
{
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string_view> parts;
    size_t l = 0;
    while (l < s.size())
    {
        while (l < s.size() && std::isspace(s[l]))
            l++;
        if (l == s.size())
            break;
        size_t r = l;
        while (r < s.size() && !std::isspace(s[r]))
            r++;
        parts.push_back(std::string_view(s).substr(l, r - l));
        l = r;
    }
    std::sort(parts.begin(), parts.end());
    std::cout << "-----------------------\n";
    do
    {
        for (auto v : parts)
        {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    } while (std::next_permutation(parts.begin(), parts.end()));
}

//homework

struct Date
{
    int year;
    int month;
    int day;
};

bool compareDates(const Date &date1, const Date &date2)
{
    if (date1.year != date2.year)
    {
        return date1.year > date2.year;
    }
    if (date1.month != date2.month)
    {
        return date1.month > date2.month;
    }
    return date1.day > date2.day;
}

int task21_13()
{
    std::ifstream inputFile("input.txt"); 
    std::ofstream outputFile("output.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "Не вдалося відкрити файли!" << std::endl;
        return 1;
    }

    std::set<Date, decltype(compareDates) *> uniqueDates(compareDates);

    while (!inputFile.eof())
    {
        int year, month, day;
        char delimiter;

        inputFile >> year >> delimiter >> month >> delimiter >> day;

        if (year >= 1951 && year <= 2049)
        {
            uniqueDates.insert({year, month, day});
        }
    }

    for (const auto &date : uniqueDates)
    {
        outputFile << date.year << '/' << date.month << '/' << date.day << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}


int main(){
    task21_1();
    task21_2();
    task21_3();
    task21_4();
    task21_5();
    task21_6();
    task21_7();
    task21_8();
    task21_9();
    task21_13();
}