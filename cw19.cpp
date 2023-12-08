#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <sstream>
#include <stdexcept>

int task19_1()
{
    unsigned n;
    std::cin >> n;
    unsigned i = 0, i_min = 0;
    double t0 = 0., t_min = 1e9;
    for (unsigned i = 0; i < n; i++)
    {
        double t;
        std::cin >> t;
        t0 += t;
        if (t_min > t0)
        {
            t_min = 0;
            i_min = i;
        }
        std::cout << t0 << ' ';
        t0 -= 1.;
    }
    std::cout << std::endl
              << i_min + 1;
}

int task19_2()
{
    unsigned n, d;
    std::cin >> n >> d;
    // std::vector<double> v(d);
    for (unsigned i = 0; i < n; i++)
    {
        double l = 0, q;
        // for (auto& q : v) {
        //     std::cin >> q;
        //     l += q * q;
        // }
        for (unsigned j = 0; j < d; j++)
        {
            std::cin >> q;
            l += q * q;
        }
        double norm = std::sqrt(l);
        std::cout << norm << std::endl;
        // normalize
        // for (auto q : v) {
        //    std::cout << q / len << ' ';
        //}
        // std::cout << std::endl;
    }
}

template <typename T>
class Poly
{
public:
    Poly() noexcept = default;
    Poly(Poly &&) noexcept = default;
    Poly(const Poly &) = default;
    Poly &operator=(Poly &&) noexcept = default;
    Poly &operator=(const Poly &) = default;
    ~Poly() = default;

    // TODO input, constructor
private:
    std::list<std::pair<int, T>> powers;
};

int task19_3()
{
}

int task19_4()
{
    unsigned n, m;
    std::vector<std::vector<double>> mat;

    for (size_t i = 0; i < n; i++)
    {
        std::vector<double> row(m);
        for (auto &v : row)
        {
            std::cin >> v;
        }
        row.emplace_back(std::move(row));
    }

    std::sort(mat.begin(), mat.end(), [](const auto &a, const auto &b)
              { return std::max_element(a.begin(), a.end()) > std::max_element(b.begin(), b.end()); });

    for (const auto &row : mat)
    {
        for (const auto &v : row)
        {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}

//homework

template <typename T>
class Rational
{
private:
    T numerator;
    T denominator;

public:
    Rational(T num, T denom) : numerator(num), denominator(denom)
    {
        normalize();
    }

    void normalize()
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Error: Division by zero!");
        }

        T gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    T gcd(T a, T b) const
    {
        while (b != 0)
        {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Rational operator+(const Rational &other) const
    {
        return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Rational operator-(const Rational &other) const
    {
        return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Rational operator*(const Rational &other) const
    {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational &other) const
    {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Rational &other) const
    {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool operator!=(const Rational &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Rational &other) const
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    bool operator>(const Rational &other) const
    {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    bool operator<=(const Rational &other) const
    {
        return !(*this > other);
    }

    bool operator>=(const Rational &other) const
    {
        return !(*this < other);
    }

    std::string toString() const
    {
        std::ostringstream oss;
        oss << numerator << '/' << denominator;
        return oss.str();
    }
};

template <>
class Rational<std::string>
{
private:
    std::string numerator;
    std::string denominator;

public:
    Rational(const std::string &num, const std::string &denom) : numerator(num), denominator(denom)
    {
    }

    std::string toString() const
    {
        return numerator + '/' + denominator;
    }

    Rational<std::string> operator+(const Rational<std::string> &other) const
    {
        return Rational<std::string>(numerator + other.numerator, denominator + other.denominator);
    }
};

int task19_14()
{
    try
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(3, 4);

        Rational<int> sum = r1 + r2;
        std::cout << "Sum: " << sum.toString() << std::endl;

        Rational<std::string> strR1("1", "2");
        Rational<std::string> strR2("3", "4");

        std::string strSum = (strR1 + strR2).toString();
        std::cout << "String Sum: " << strSum << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


int main(){
    task19_1();
    task19_2();
    task19_3();
    task19_4();
    task19_14();
}