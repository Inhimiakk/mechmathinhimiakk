#include <iostream>
#include <numeric>
#include <compare>
#include <exception>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>

class WrongRatio : public std::invalid_argument
{
public:
    WrongRatio() : std::invalid_argument("wrong ratio: denominator can't be zero") {}
};

class InvalidRatioStr : public std::runtime_error
{
public:
    InvalidRatioStr() : std::runtime_error("invalid ratio string") {}
};

class Rational
{
public:
    Rational() = default;
    Rational(const Rational &) = default;
    Rational(Rational &&) = default;

    Rational(int nominator, unsigned denominator) : m_nominator(nominator), m_denominator(denominator)
    {
        if (m_denominator == 0)
            throw WrongRatio();
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
        if (denominator == 0)
            throw WrongRatio();
        this->m_denominator = denominator;
    }

    friend Rational operator-(const Rational &) noexcept;
    friend Rational operator+(const Rational &, const Rational &) noexcept;
    friend Rational operator-(const Rational &, const Rational &) noexcept;
    friend Rational operator*(const Rational &, const Rational &) noexcept;
    friend Rational operator/(const Rational &, const Rational &) noexcept;

    friend std::strong_ordering operator<=>(const Rational &, const Rational &) noexcept;

    friend std::ostream &operator<<(std::ostream &, const Rational &) noexcept;
    friend std::istream &operator>>(std::istream &, Rational &);

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

Rational operator-(const Rational &a) noexcept
{
    return Rational(-a.m_nominator, a.m_denominator);
}

Rational operator+(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * static_cast<int>(b.m_denominator) + b.m_nominator * static_cast<int>(a.m_denominator);
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator-(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * static_cast<int>(b.m_denominator) - b.m_nominator * static_cast<int>(a.m_denominator);
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator*(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * b.m_nominator;
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator/(const Rational &a, const Rational &b) noexcept
{
    int nom = a.m_nominator * b.m_denominator;
    unsigned denom = a.m_denominator * b.m_nominator;
    return Rational(nom, denom);
}

std::strong_ordering operator<=>(const Rational &a, const Rational &b) noexcept
{
    return a.m_nominator * static_cast<int>(b.m_denominator) <=> b.m_nominator * static_cast<int>(a.m_denominator);
}

std::ostream &operator<<(std::ostream &out, const Rational &r) noexcept
{
    return out << r.m_nominator << "/" << r.m_denominator;
}

std::istream &operator>>(std::istream &in, Rational &r)
{
    int nom = 0;
    unsigned denom = 1;
    char sep;
    in >> nom >> sep >> denom;
    if (sep != '/' || in.bad())
    {
        throw InvalidRatioStr();
    }
    r = Rational(nom, denom);
    return in;
}

int task17_1()
{
    try
    {
        Rational r;
        std::cin >> r;
        std::cout << r;
    }
    catch (WrongRatio &r)
    {
        std::cout << r.what() << std::endl;
    }
    catch (InvalidRatioStr &r)
    {
        std::cout << r.what() << std::endl;
    }
}

class Human
{
public:
    Human() = default;

protected:
    std::string m_name;
    unsigned m_age;
    bool m_gender;
};

class Student : virtual public Human
{
public:
    Student() = default;

protected:
    std::string university;
    unsigned course;
};

class Lecturer : virtual public Human
{
public:
    Lecturer() = default;
};

class Postgraduate : public Student, Lecturer
{
public:
    Postgraduate() = default;
};

int task17_2()
{
}

class LinearEquation
{
protected:
    double a, b;

public:
    LinearEquation() : a(0), b(0) {}

    void inputCoefficients()
    {
        std::cout << "Enter coefficients for the linear equation (a b): ";
        std::cin >> a >> b;
    }

    void displayEquation() const
    {
        std::cout << "Linear equation: " << a << "x + " << b << " = 0\n";
    }

    virtual void findRealRoots() const
    {
        if (a == 0)
        {
            std::cout << "The equation is not linear.\n";
        }
        else
        {
            double root = -b / a;
            std::cout << "Real root: x = " << root << '\n';
        }
    }
};

class QuadraticEquation : public LinearEquation
{
private:
    double c;

public:
    QuadraticEquation() : c(0) {}

    void inputCoefficients()
    {
        LinearEquation::inputCoefficients();
        std::cout << "Enter the additional coefficient for the quadratic equation (c): ";
        std::cin >> c;
    }

    void displayEquation() const
    {
        std::cout << "Quadratic equation: " << a << "x^2 + " << b << "x + " << c << " = 0\n";
    }

    void findRealRoots() const override
    {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0)
        {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Real roots: x1 = " << root1 << ", x2 = " << root2 << '\n';
        }
        else if (discriminant == 0)
        {
            double root = -b / (2 * a);
            std::cout << "Real and identical roots: x = " << root << '\n';
        }
        else
        {
            std::cout << "No real roots.\n";
        }
    }
};

class BiquadraticEquation : public QuadraticEquation
{
public:
    BiquadraticEquation() {}

    void inputCoefficients()
    {
        QuadraticEquation::inputCoefficients();
    }

    void displayEquation() const
    {
        std::cout << "Biquadratic equation: " << a << "x^4 + " << b << "x^2 + " << c << " = 0\n";
    }

    void findRealRoots() const override
    {
        double a_quad = 1, b_quad = 0, c_quad = c;
        QuadraticEquation quadraticEquation;
        quadraticEquation.findRealRoots();
    }
};

int task17_7()
{
    std::vector<LinearEquation *> equations;

    std::ifstream inputFile("equations.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file.\n";
        return 1;
    }

    int numEquations;
    inputFile >> numEquations;

    for (int i = 0; i < numEquations; ++i)
    {
        int equationType;
        inputFile >> equationType;

        LinearEquation *equation = nullptr;

        if (equationType == 1)
        {
            equation = new LinearEquation();
        }
        else if (equationType == 2)
        {
            equation = new QuadraticEquation();
        }
        else if (equationType == 3)
        {
            equation = new BiquadraticEquation();
        }

        if (equation)
        {
            equation->inputCoefficients();
            equations.push_back(equation);
        }
    }

    inputFile.close();

    int infiniteSolutionsCount = 0;
    int noRealRootsCount = 0;
    double minRootMagnitude = std::numeric_limits<double>::infinity();
    double sumOfSquares = 0.0;

    for (const auto &equation : equations)
    {
        equation->displayEquation();
        equation->findRealRoots();

        if (dynamic_cast<BiquadraticEquation *>(equation) != nullptr)
        {
            infiniteSolutionsCount++;
        }

        if (equation->a == 0)
        {
            noRealRootsCount++;
        }

        double rootMagnitude = std::numeric_limits<double>::infinity();
        equation->findRealRoots();
        if (dynamic_cast<QuadraticEquation *>(equation) != nullptr)
        {
            QuadraticEquation *quadraticEquation = dynamic_cast<QuadraticEquation *>(equation);
            double discriminant = quadraticEquation->b * quadraticEquation->b - 4 * quadraticEquation->a * quadraticEquation->c;
            if (discriminant >= 0)
            {
                double root1 = (-quadraticEquation->b + sqrt(discriminant)) / (2 * quadraticEquation->a);
                double root2 = (-quadraticEquation->b - sqrt(discriminant)) / (2 * quadraticEquation->a);
                rootMagnitude = std::min(std::fabs(root1), std::fabs(root2));
            }
        }

        minRootMagnitude = std::min(minRootMagnitude, rootMagnitude);

        if (dynamic_cast<QuadraticEquation *>(equation) != nullptr)
        {
            QuadraticEquation *quadraticEquation = dynamic_cast<QuadraticEquation *>(equation);
            quadraticEquation->findRealRoots();
            sumOfSquares += pow((-quadraticEquation->b + sqrt(quadraticEquation->b * quadraticEquation->b - 4 * quadraticEquation->a * quadraticEquation->c)) / (2 * quadraticEquation->a), 2);
            sumOfSquares += pow((-quadraticEquation->b - sqrt(quadraticEquation->b * quadraticEquation->b - 4 * quadraticEquation->a * quadraticEquation->c)) / (2 * quadraticEquation->a), 2);
        }
    }

    std::cout << "Number of equations with infinite solutions: " << infiniteSolutionsCount << '\n';
    std::cout << "Number of equations with no real roots: " << noRealRootsCount << '\n';
    std::cout << "Minimum root magnitude: " << minRootMagnitude << '\n';
    std::cout << "Sum of squares of real roots: " << sumOfSquares << '\n';

    for (const auto &equation : equations)
    {
        delete equation;
    }

    return 0;
}

int main(){
    task17_2();
    task17_7();
}
