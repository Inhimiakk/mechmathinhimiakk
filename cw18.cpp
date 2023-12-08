#include <iostream>
#include <type_traits>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

namespace my_max
{
    template <typename T>
    const T &max(const T &a, const std::type_identity_t<T> &b)
    {
        return a > b ? a : b;
    }
}

int task18_1()
{
    std::cout << my_max::max(2, 42) << std::endl;
    return 0;
}

template <typename T>
class Stack
{
    struct Node;

    using node_ptr = std::unique_ptr<Node>;

    struct Node
    {
        T el;
        node_ptr prev;
    };

public:
    Stack() noexcept = default;

    bool is_empty() const noexcept
    {
        return m_root == nullptr;
    }

    void push(const T &el)
    {
        m_root = std::make_unique<Node>(Node{
            .el = el,
            .prev = std::move(m_root)});
    }

    void push(T &&el)
    {
        m_root = std::make_unique<Node>(Node{
            .el = std::move(el),
            .prev = std::move(m_root)});
    }

    void pop()
    {
        m_root = std::move(m_root.get()->prev);
    }

    const T &top() const
    {
        return m_root.get()->el;
    }

private:
    node_ptr m_root = nullptr;
};

int task18_2()
{
    Stack<char> s;
    std::string buf;
    std::cin >> buf;
    for (char ch : buf)
    {
        s.push(ch);
    }

    while (!s.is_empty())
    {
        std::cout << s.top();
        s.pop();
    }

    return 0;
}

class TextFileHandler
{
private:
    std::string fileName;
    int numLines;
    int numNumbers;

public:
    TextFileHandler(const std::string &fileName) : fileName(fileName), numLines(0), numNumbers(0) {}

    void inputNumbersToConsole()
    {
        std::ofstream outputFile(fileName, std::ios::app);

        if (!outputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for writing.");
        }

        std::cout << "Enter numbers (type 'done' to finish):\n";

        std::string line;
        while (true)
        {
            std::getline(std::cin, line);

            if (line == "done")
            {
                break;
            }

            outputFile << line << '\n';
            numLines++;
        }

        outputFile.close();
    }

    void createFileFromMatrix(const std::vector<std::vector<double>> &matrix)
    {
        std::ofstream outputFile(fileName);

        if (!outputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for writing.");
        }

        for (const auto &row : matrix)
        {
            for (double number : row)
            {
                outputFile << number << ' ';
                numNumbers++;
            }
            outputFile << '\n';
            numLines++;
        }

        outputFile.close();
    }

    double displayFileContentAndReturnNumber(int lineNumber, int numberPosition)
    {
        std::ifstream inputFile(fileName);

        if (!inputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for reading.");
        }

        std::string line;
        int currentLine = 0;

        while (std::getline(inputFile, line))
        {
            currentLine++;
            if (currentLine == lineNumber)
            {
                std::istringstream iss(line);
                double number;
                int currentPosition = 0;

                while (iss >> number)
                {
                    currentPosition++;
                    if (currentPosition == numberPosition)
                    {
                        std::cout << "File content:\n"
                                  << line << '\n';
                        return number;
                    }
                }

                throw std::out_of_range("Invalid number position in the line.");
            }
        }

        throw std::out_of_range("Invalid line number.");
    }

    void appendNumbersToFile(const std::vector<double> &numbers)
    {
        std::ofstream outputFile(fileName, std::ios::app);

        if (!outputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for writing.");
        }

        for (double number : numbers)
        {
            outputFile << number << ' ';
            numNumbers++;
        }

        outputFile << '\n';
        numLines++;

        outputFile.close();
    }

    void deleteNumber(int lineNumber, int numberPosition)
    {
        std::ifstream inputFile(fileName);

        if (!inputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for reading.");
        }

        std::vector<std::string> lines;
        std::string line;
        int currentLine = 0;

        while (std::getline(inputFile, line))
        {
            currentLine++;

            if (currentLine == lineNumber)
            {
                std::istringstream iss(line);
                std::ostringstream modifiedLine;
                double number;
                int currentPosition = 0;

                while (iss >> number)
                {
                    currentPosition++;

                    if (currentPosition != numberPosition)
                    {
                        modifiedLine << number << ' ';
                    }
                }

                lines.push_back(modifiedLine.str());
            }
            else
            {
                lines.push_back(line);
            }
        }

        inputFile.close();

        std::ofstream outputFile(fileName);

        if (!outputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for writing.");
        }

        for (const auto &modifiedLine : lines)
        {
            outputFile << modifiedLine << '\n';
        }

        outputFile.close();

        numLines--;
        numNumbers--;
    }

    std::string getFileName() const
    {
        return fileName;
    }

    int getNumNumbers() const
    {
        return numNumbers;
    }

    int getNumLines() const
    {
        return numLines;
    }
};

int task18_6()
{
    try
    {
        TextFileHandler fileHandler("numbers.txt");

        fileHandler.inputNumbersToConsole();

        std::vector<std::vector<double>> matrix = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
        fileHandler.createFileFromMatrix(matrix);

        double retrievedNumber = fileHandler.displayFileContentAndReturnNumber(2, 3);
        std::cout << "Retrieved number: " << retrievedNumber << '\n';

        std::vector<double> numbersToAdd = {7.7, 8.8, 9.9};
        fileHandler.appendNumbersToFile(numbersToAdd);

        fileHandler.deleteNumber(2, 2);

        std::cout << "File name: " << fileHandler.getFileName() << '\n';
        std::cout << "Number of lines: " << fileHandler.getNumLines() << '\n';
        std::cout << "Number of numbers: " << fileHandler.getNumNumbers() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

int main()
{
    task18_1();
    task18_2();
    task18_6();

    return 0;
}
