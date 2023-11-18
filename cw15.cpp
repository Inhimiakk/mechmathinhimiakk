#include <iostream>
#include <numeric>
#include <compare>
#include <fstream>
#include <cstdint>
#include <cmath>

class Rational
{
public:
    Rational() = default;
    Rational(const Rational &) = default;
    Rational(Rational &&) = default;

    Rational(int nominator, unsigned denominator) noexcept : m_nominator(nominator), m_denominator(denominator)
    {
        if (m_denominator == 0)
        {
            m_denominator = 1;
        }
        this->reduce();
    }

    Rational &operator=(const Rational &) = default;
    Rational &operator=(Rational &&) = default;

    ~Rational() = default;

    void set_nominator(int nominator)
    {
        this->m_nominator = nominator;
    }

    void set_denominator(unsigned denominator)
    {
        if (denominator != 0)
        {
            this->m_denominator = denominator;
        }
    }

    friend Rational operator+(const Rational &, const Rational &) noexcept;
    friend Rational operator-(const Rational &, const Rational &) noexcept;
    friend Rational operator*(const Rational &, const Rational &) noexcept;
    friend Rational operator/(const Rational &, const Rational &) noexcept;

    friend std::strong_ordering operator<=>(const Rational &, const Rational &) noexcept;

    friend std::ostream &operator<<(std::ostream &, const Rational &) noexcept;
    friend std::istream &operator>>(std::istream &, Rational &) noexcept;

protected:
    void reduce() noexcept
    {
        unsigned nom = std::abs(m_nominator);
        unsigned common = std::gcd(nom, m_denominator);
        m_nominator /= common;
        m_denominator /= common;
    }

    int m_nominator{0};
    unsigned m_denominator{1};
};

Rational operator+(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * b.m_denominator + b.m_nominator * a.m_denominator;
    int denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator-(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * b.m_denominator - b.m_nominator * a.m_denominator;
    int denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator*(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * b.m_nominator;
    int denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator/(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * b.m_denominator;
    int denom = a.m_denominator * b.m_nominator;
    return Rational(nom, denom);
}

std::strong_ordering operator<=>(const Rational &a, const Rational &b) noexcept
{
    return a.m_nominator * b.m_denominator <=> b.m_nominator * a.m_denominator;
}

std::ostream &operator<<(std::ostream &out, const Rational &r) noexcept
{
    return out << r.m_nominator << "/" << r.m_denominator;
}

std::istream &operator>>(std::istream &in, Rational &r) noexcept
{
    int nom = 0;
    unsigned denom = 1;
    in >> nom >> denom;
    r = Rational(nom, denom);
    return in;
}

int task15_1()
{
    Rational sum = {};
    Rational eps = Rational(1, 1000);
    Rational neg_eps = Rational(-1, 1000);
    Rational summon = {};
    unsigned i = 0;
    do
    {
        i += 1;
        summon = Rational(int(i % 2) * 2 - 1, i * i);
        sum = sum + summon;
    } while (summon > eps || summon < neg_eps);
    std::cout << sum;
}

class Point
{
public:
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}

    double x{}, y{};

    static Point read_point()
    {
        Point p;
        std::cin >> p.x >> p.y;
        readed_count += 1;
        return p;
    }

    static void show_count()
    {
        std::cout << readed_count << '\n';
    }

protected:
    static uint32_t readed_count;
};

uint32_t Point::readed_count;

double dist(const Point &a, const Point &b)
{
    return std::hypot(a.x - b.x, a.y - b.y);
}

int task15_2()
{
    double p = 0;
    Point prev = Point::read_point(), first = prev;
    while (true)
    {
        std::cout << "enter point? (y|n)\n";
        char ans;
        std::cin >> ans;
        if (ans != 'y' && ans != 'Y')
            break;
        Point cur = Point::read_point();
        p += dist(prev, cur);
        prev = cur;
    }
    p += dist(prev, first);
    std::cout << "p: " << p << '\n';
    Point::show_count();
}

class Polynomial
{
private:
    int N;                
    double *coefficients; 

public:
    Polynomial() : N(0), coefficients(nullptr) {}

    Polynomial(int size) : N(size), coefficients(new double[size]) {}

    Polynomial(const Polynomial &other) : N(other.N), coefficients(new double[other.N])
    {
        for (int i = 0; i < N; ++i)
        {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial()
    {
        delete[] coefficients;
    }

    void fillCoefficientsViaConstructor()
    {
        std::cout << "Введіть коефіцієнти поліному:\n";
        for (int i = 0; i < N; ++i)
        {
            std::cout << "Коефіцієнт " << i << ": ";
            std::cin >> coefficients[i];
        }
    }

    void fillCoefficients()
    {
        std::cout << "Введіть коефіцієнти поліному:\n";
        for (int i = 0; i < N; ++i)
        {
            std::cout << "Коефіцієнт " << i << ": ";
            std::cin >> coefficients[i];
        }
    }

    double getCoefficient(int index) const
    {
        if (index >= 0 && index < N)
        {
            return coefficients[index];
        }
        else
        {
            std::cerr << "Невірний індекс коефіцієнта.\n";
            return 0.0;
        }
    }

    void printPolynomial() const
    {
        std::cout << "Поліном: ";
        for (int i = 0; i < N; ++i)
        {
            std::cout << coefficients[i] << "*x^" << i;
            if (i < N - 1)
            {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }

    friend std::istream &operator>>(std::istream &in, Polynomial &poly);

    friend std::ostream &operator<<(std::ostream &out, const Polynomial &poly);
};

std::istream &operator>>(std::istream &in, Polynomial &poly)
{
    poly.fillCoefficients();
    return in;
}

std::ostream &operator<<(std::ostream &out, const Polynomial &poly)
{
    out.write(reinterpret_cast<const char *>(&poly.N), sizeof(poly.N));
    out.write(reinterpret_cast<const char *>(poly.coefficients), sizeof(double) * poly.N);
    return out;
}

int task15_3()
{
    int size;
    std::cout << "Введіть розмір поліному: ";
    std::cin >> size;

    Polynomial poly1(size);
    std::cout << "Введіть коефіцієнти поліному через конструктор:\n";
    std::cin >> poly1;

    Polynomial poly2(poly1); 
    poly2.printPolynomial();

    std::ofstream outFile("polynomial.bin", std::ios::binary);
    outFile << poly1;
    outFile.close();

    std::ifstream inFile("polynomial.bin", std::ios::binary);
    Polynomial poly3;
    inFile >> poly3;
    inFile.close();

    poly3.printPolynomial();

    return 0;
}

class Triangle
{
private:
    double base; 
    double side1; 
    double side2; 

public:
    Triangle(double base, double side1, double side2) : base(base), side1(side1), side2(side2) {}

    double getBase() const
    {
        return base;
    }

    double getSide1() const
    {
        return side1;
    }

    double getSide2() const
    {
        return side2;
    }

    double getPerimeter() const
    {
        return base + side1 + side2;
    }

    double getArea() const
    {
        double s = getPerimeter() / 2;
        return sqrt(s * (s - base) * (s - side1) * (s - side2));
    }

    double getUpperAngle() const
    {
        return atan2(getArea() * 2, base * side1 + base * side2 + side1 * side2) * (180 / M_PI);
    }

    double getBaseAngle() const
    {
        return 180 - getUpperAngle();
    }

    double getSide1Angle() const
    {
        return atan2(side1 * sin(getBaseAngle()), base + side1 * cos(getBaseAngle())) * (180 / M_PI);
    }

    double getSide2Angle() const
    {
        return atan2(side2 * sin(getBaseAngle()), base + side2 * cos(getBaseAngle())) * (180 / M_PI);
    }
};

int task15_7()
{
    Triangle triangle(5.0, 4.0, 3.0);

    std::cout << "Довжина основи: " << triangle.getBase() << std::endl;
    std::cout << "Довжина бічної сторони 1: " << triangle.getSide1() << std::endl;
    std::cout << "Довжина бічної сторони 2: " << triangle.getSide2() << std::endl;

    std::cout << "Периметр трикутника: " << triangle.getPerimeter() << std::endl;
    std::cout << "Площа трикутника: " << triangle.getArea() << std::endl;

    std::cout << "Верхній кут трикутника: " << triangle.getUpperAngle() << " град." << std::endl;
    std::cout << "Кут при основі трикутника: " << triangle.getBaseAngle() << " град." << std::endl;
    std::cout << "Кут при бічній стороні 1: " << triangle.getSide1Angle() << " град." << std::endl;
    std::cout << "Кут при бічній стороні 2: " << triangle.getSide2Angle() << " град." << std::endl;

    return 0;
}

// int mail(){
//     task15_1();
//     task15_2();
//     task15_3();
//     task15_7();
// }