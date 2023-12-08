#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

int task14_1()
{
    freopen("data/lab14_task1.txt", "r", stdin);
    double value;
    std::cin >> value;
    while (true)
    {
        char op;
        std::cin >> op;
        if (op == '=')
        {
            break;
        }
        else
        {
            if (op == '+')
            {
                double d;
                std::cin >> d;
                value += d;
            }
            if (op == '-')
            {
                double d;
                std::cin >> d;
                value -= d;
            }
        }
    }
    std::cout << value << '\n';
}

int task14_2()
{
    freopen("data/lab14_task2.txt", "r", stdin);
    freopen("data/lab14_task2_out.txt", "w", stdout);

    bool change_letter = false;
    std::string w;
    while (std::cin >> w)
    {
        if (change_letter && !w.empty())
        {
            w[0] = static_cast<unsigned char>(
                std::toupper(static_cast<unsigned char>(w[0])));
        }
        change_letter = w == "die" || w == "der" || w == "das";
        std::cout << w << ' ';
    }
}

int task14_3()
{
    freopen("data/lab14_task3.txt", "r", stdin);
    freopen("data/lab14_task3_out.txt", "w", stdout);

    std::string w;
    while (std::cin >> w)
    {
        std::string_view word = w;
        for (size_t sep_beg = 0; sep_beg < word.size();)
        {
            size_t sep_size =
                std::min(
                    std::min(
                        word.size(),
                        word.find(',', sep_beg)),
                    std::min(
                        word.find('!', sep_beg),
                        word.find('.', sep_beg))) -
                sep_beg;

            for (size_t i = 0; i < sep_size / 2; i++)
            {
                std::swap(w[sep_beg + i], w[sep_beg + sep_size - 1 - i]);
            }
            sep_size += 1;
            std::cout << w.substr(sep_beg, sep_size);
            sep_beg += sep_size;
        }
        std::cout << " ";
    }
}

int task14_4()
{
    freopen("data/lab14_task4.txt", "r", stdin);

    std::string s;
    std::vector<std::string> tag_stack;
    while (std::cin >> s)
    {
        if (s.starts_with('<'))
        {
            if (!s.ends_with('>'))
            {
                std::cout << "incorrect: missing `>`\n";
                return 1;
            }
            if (s.starts_with("</"))
            {
                if (tag_stack.empty())
                {
                    std::cout << "incorrect: no open tag\n";
                    return 1;
                }
                if (tag_stack.back() != std::string_view(s).substr(2, s.size() - 3))
                {
                    std::cout << "incorrect: tags doesn't match\n";
                    return 1;
                }
                tag_stack.pop_back();
            }
            else
            {
                tag_stack.push_back(s.substr(1, s.size() - 2));
            }
        }
    }
    std::cout << "correct\n";
}

void create_example_file()
{
    constexpr std::string_view data = R"(
yudin, 2, comp math 1, 30, 29, 20, 29
mus, 2, comp math 1, 20, 10, 30, 5,
nedilya, 2, comp math 1, 30, 30, 30, 30
)";

    std::ofstream("data/lab14_task5_out1.txt") << data;
}

int task14_5()
{
    create_example_file();

    std::ifstream data_in("data/lab14_task5_out1.txt");
    std::string buf;
    std::string student;
    double av = 30.;
    while (!data_in.eof())
    {
        std::getline(data_in, buf);
        size_t surname_end = buf.find(',');
        size_t group_end = buf.find(',', surname_end + 1);
        size_t subgroup_end = buf.find(',', group_end + 1);
        double average_mark = 0.;
        int marks = 0;
        for (size_t mark_beg = subgroup_end; mark_beg < buf.size();)
        {
            average_mark += std::strtod(buf.data() + mark_beg, nullptr);
            marks += 1;
            mark_beg = buf.find(',', mark_beg + 1);
        }
        if (average_mark / marks < av)
        {
            student = buf.substr(0, surname_end - 1);
            av = average_mark / marks;
        }
    }
    std::cout << student;
}

//homework

std::string centerAlign(const std::string &line, int width)
{
    int padding = (width - line.length()) / 2;
    std::string centeredLine = std::string(padding, ' ') + line;
    return centeredLine;
}

void processFile(const std::string &inputFileName, const std::string &outputFileName)
{
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the input file.\n";
        return;
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(inputFile, line))
    {
        lines.push_back(line);
    }

    inputFile.close();

    for (std::string &line : lines)
    {
        line = centerAlign(line, 50);
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening the output file.\n";
        return;
    }

    for (const std::string &line : lines)
    {
        outputFile << line << '\n';
    }

    outputFile.close();
}

int task14_11()
{
    std::string inputFileName = "C:\\Users\\Inhimiakk\\Documents\\input.txt";
    std::string outputFileName = "C:\\Users\\Inhimiakk\\Documents\\output.txt";

    processFile(inputFileName, outputFileName);

    std::cout << "Text has been centered and written to the output file.\n";

    return 0;
}

int main(){
    task14_1();
    task14_2();
    task14_3();
    task14_4();
    task14_5();
    task14_11();
}
