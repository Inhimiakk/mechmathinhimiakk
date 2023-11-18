#include <iostream>
#include <string>
#include <string_view>
#include <cctype>

constexpr std::string_view target_substr(std::string_view s)
{
    const size_t colon = s.find(':');
    if (colon == std::string_view::npos)
        return s;
    const size_t r = colon + 1;
    return s.substr(r, s.find(',', r) - r);
}

int task13_1()
{
    std::string s;
    std::getline(std::cin, s);
    std::cout << '`' << target_substr(s) << '`' << '\n';
}

void remove_mid(std::string &s)
{
    const size_t first_dot = s.find('.');
    const size_t last_dot = s.rfind('.');
    if (first_dot == std::string::npos)
    {
        size_t i = 0;
        while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i])))
            i++;
        std::memmove(s.data(), s.data() + i, s.size() - i);
        s.resize(s.size() - i);
        return;
    }
    if (first_dot == last_dot)
    {
        std::memmove(s.data(), s.data() + first_dot, s.size() - first_dot);
        s.resize(s.size() - first_dot);
        return;
    }
    std::memmove(s.data() + first_dot, s.data() + last_dot, s.size() - last_dot);
    s.resize(s.size() + first_dot - last_dot);
}

int task13_2()
{
    std::string s;
    std::getline(std::cin, s);
    remove_mid(s);
    std::cout << s << std::endl;
}

std::string trim_words(std::string_view s)
{
    bool is_word = false;
    std::string ret;
    char prev = '\0';
    for (auto ch : s)
    {
        bool is_word_char = std::isalnum(static_cast<unsigned char>(ch));
        if (is_word_char && is_word || !is_word)
        {
            ret += prev;
        }
        prev = ch;
        is_word = is_word_char;
    }
    return ret;
}

int task13_3()
{
    std::string s;
    std::getline(std::cin, s);
    std::cout << '`' << trim_words(s) << '`' << '\n';
}

std::vector<double> extractNumbers(const std::string &inputString, char delimiter, int count)
{
    std::vector<double> result;

    std::istringstream inputStream(inputString);
    std::string token;

    while (std::getline(inputStream, token, delimiter) && result.size() < count)
    {
        try
        {
            size_t pos;
            double value = std::stod(token, &pos);
            if (pos == token.length())
            {
                result.push_back(value);
            }
        }
        catch (const std::invalid_argument &)
        {
            // Ignore invalid tokens (non-numeric)
        }
        catch (const std::out_of_range &)
        {
            // Ignore out-of-range values
        }
    }

    return result;
}

int task13_4()
{
    std::string inputString;
    char delimiter;
    int count;

    std::cout << "Введіть рядок: ";
    std::getline(std::cin, inputString);

    std::cout << "Введіть роздільник: ";
    std::cin >> delimiter;

    std::cout << "Введіть кількість чисел для витягування: ";
    std::cin >> count;

    std::vector<double> result = extractNumbers(inputString, delimiter, count);

    std::cout << "Витягнуті числа: ";
    for (double number : result)
    {
        std::cout << number << " ";
    }

    return 0;
}

//homework

std::string removeCharacterFromWords(const std::string &inputString, char character)
{
    std::istringstream inputStream(inputString);
    std::string word;
    std::string result;

    while (inputStream >> word)
    {
        word.erase(std::remove(word.begin(), word.end(), character), word.end());

        result += word;

        if (!inputStream.eof())
        {
            result += ' ';
        }
    }

    return result;
}

int task13_11()
{
    std::string inputString;
    char character;

    std::cout << "Введіть рядок: ";
    std::getline(std::cin, inputString);

    std::cout << "Введіть символ для видалення: ";
    std::cin >> character;

    std::string result = removeCharacterFromWords(inputString, character);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}

// int main(){
//     task13_1();
//     task13_2();
//     task13_3();
//     task13_4();
//     task13_11();
// }