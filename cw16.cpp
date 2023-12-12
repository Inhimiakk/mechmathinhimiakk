#include <iostream>
#include <vector>
#include <type_traits>
#include <cmath>

class Person
{
public:
    Person() = default;
    Person(const Person &) = default;
    Person(Person &&) = default;
    Person &operator=(const Person &) = default;
    Person &operator=(Person &&) = default;
    ~Person() = default;

    int input()
    {
        std::cin >> *this;
        return 1;
    }
    void show() const
    {
        std::cout << *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &p);
    friend std::istream &operator>>(std::istream &in, Person &p);

    unsigned byear() const
    {
        return m_byear;
    }
    const std::string &name() const
    {
        return m_name;
    }

private:
    std::string m_name;
    unsigned m_byear{};
};

std::ostream &operator<<(std::ostream &out, const Person &p)
{
    return out << "`" << p.m_name << "`: `" << p.m_byear << "`";
}

std::istream &operator>>(std::istream &in, Person &p)
{
    return in >> p.m_name >> p.m_byear;
}

class Friend : public Person
{
public:
    Friend() = default;
    Friend(const Friend &) = default;
    Friend(Friend &&) = default;
    Friend &operator=(const Friend &) = default;
    Friend &operator=(Friend &&) = default;
    ~Friend() = default;

    unsigned number() const
    {
        return m_number;
    }
    void set_number(unsigned new_number)
    {
        m_number = new_number;
    }

    int input()
    {
        std::cin >> *static_cast<Person *>(this) >> m_number;
        return 1;
    }
    void show() const
    {
        std::cout << *static_cast<const Person *>(this) << ", `" << m_number << "`";
    }

private:
    unsigned m_number{};
};

int task16_1()
{
    std::vector<Friend> friend_list;

    while (true)
    {
        std::cout <<
            R"(choose operation:
0 - exit
usage: 0
1 - add new friend
usage: 1 [name] [byear] [number]
2 - find number by name
usage: 2 [name]
3 - change number by name
usage: 2 [name] [new_number]
)";
        unsigned op;
        std::cin >> op;
        if (op == 0)
            break;
        switch (op)
        {
        case 1:
        {
            Friend f;
            f.input();
            friend_list.emplace_back(std::move(f));
        }
        break;
        case 2:
        {
            std::string name;
            std::cin >> name;
            for (const auto &f : friend_list)
            {
                if (name == f.name())
                {
                    std::cout << f.number() << std::endl;
                }
            }
        }
        break;
        case 3:
        {
            std::string name;
            unsigned new_number;
            std::cin >> name >> new_number;
            for (auto &f : friend_list)
            {
                if (name == f.name())
                {
                    f.set_number(new_number);
                }
            }
        }
        break;
        default:
            std::cout << "invalid operation: `" << op << "`\n";
            break;
        }
    }
}


struct Point
{
    using dimensions = std::integral_constant<unsigned, 2>;

    double x, y;
};

struct Point3D : Point
{
    using dimensions = std::integral_constant<unsigned, 3>;

    double z;
};

template <typename P>
struct Segment
{
    P a, b;

    double length() const
    {
        if constexpr (P::dimensions::value == 2)
        {
            return std::hypot(a.x - b.x, a.y - b.y);
        }
        else if constexpr (P::dimensions::value == 3)
        {
            return std::hypot(a.x - b.x, a.y - b.y, a.z - b.z);
        }
        else
        {
            return 0.;
        }
    }
};

template <typename P>
std::ostream &operator<<(std::ostream &out, const Segment<P> &s)
{
    if constexpr (P::dimensions::value == 2)
    {
        out << "(" << s.a.x << ", " << s.a.y << ")";
        out << "(" << s.b.x << ", " << s.b.y << ")";
    }
    else if constexpr (P::dimensions::value == 3)
    {
        out << "(" << s.a.x << ", " << s.a.y << ", " << s.a.z << ")";
        out << "(" << s.b.x << ", " << s.b.y << ", " << s.b.z << ")";
    }
    return out;
}

template <typename P>
std::istream &operator>>(std::istream &in, Segment<P> &s)
{
    if constexpr (P::dimensions::value == 2)
    {
        in >> s.a.x >> s.a.y;
        in >> s.b.x >> s.b.y;
    }
    else if constexpr (P::dimensions::value == 3)
    {
        in >> s.a.x >> s.a.y >> s.a.z;
        in >> s.b.x >> s.b.y >> s.b.z;
    }
    return in;
}

int task16_2()
{
    Segment<Point> s1;
    Segment<Point3D> s2;

    std::cin >> s1;
    std::cin >> s2;

    std::cout << "`" << s1 << "`, `" << s2 << "`\n";
    std::cout << s1.length() << ", " << s2.length() << "\n";
}

//homework

class Equation
{
public:
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual std::vector<double> solve() const = 0;
    virtual ~Equation() = default;
};

class LinearEquation : public Equation
{
public:
    void input() override
    {
        std::cout << "Enter coefficients for the linear equation (ax + b = 0):\n";
        std::cout << "a: ";
        std::cin >> a;
        std::cout << "b: ";
        std::cin >> b;
    }

    void output() const override
    {
        std::cout << "Linear Equation: " << a << "x + " << b << " = 0\n";
    }

    std::vector<double> solve() const override
    {
        if (a == 0)
        {
            return {};
        }
        return {-b / a};
    }

private:
    double a, b;
};

class QuadraticEquation : public LinearEquation
{
public:
    void input() override
    {
        LinearEquation::input();
        std::cout << "Enter the coefficient for the quadratic term (ax^2 + bx + c = 0):\n";
        std::cout << "c: ";
        std::cin >> c;
    }

    void output() const override
    {
        LinearEquation::output();
        std::cout << "Quadratic Term: " << c << "x^2\n";
    }

    std::vector<double> solve() const override
    {
        if (a == 0)
        {
            return LinearEquation::solve();
        }

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            return {}; // No real solutions for a<0
        }

        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);

        return {root1, root2};
    }

private:
    double c;
};

class BiquadraticEquation : public QuadraticEquation
{
public:
    void input() override
    {
        QuadraticEquation::input();
        std::cout << "Enter the coefficient for the biquadratic term (ax^4 + bx^2 + c = 0):\n";
        std::cout << "d: ";
        std::cin >> d;
    }

    void output() const override
    {
        QuadraticEquation::output();
        std::cout << "Biquadratic Term: " << d << "x^4\n";
    }

    std::vector<double> solve() const override
    {
        if (a == 0)
        {
            return QuadraticEquation::solve();
        }

        QuadraticEquation tempQuadraticEquation;
        tempQuadraticEquation.setCoefficients(1, 0, -d);

        auto quadraticSolutions = tempQuadraticEquation.solve();
        std::vector<double> biquadraticSolutions;

        for (double solution : quadraticSolutions)
        {
            if (solution >= 0)
            {
                double root1 = std::sqrt(solution);
                double root2 = -root1;
                biquadraticSolutions.push_back(root1);
                biquadraticSolutions.push_back(root2);
            }
        }

        return biquadraticSolutions;
    }

private:
    double d;
};

int task16_10()
{
    std::ifstream inputFile("equations.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    int equationCount;
    inputFile >> equationCount;

    std::vector<std::unique_ptr<Equation>> equations;

    for (int i = 0; i < equationCount; ++i)
    {
        int equationType;
        inputFile >> equationType;

        std::unique_ptr<Equation> equation;
        switch (equationType)
        {
        case 1:
            equation = std::make_unique<LinearEquation>();
            break;
        case 2:
            equation = std::make_unique<QuadraticEquation>();
            break;
        case 3:
            equation = std::make_unique<BiquadraticEquation>();
            break;
        default:
            std::cerr << "Unknown equation type.\n";
            return 1;
        }

        equation->input();
        equations.push_back(std::move(equation));
    }

    for (const auto &equation : equations)
    {
        auto solutions = equation->solve();
        if (solutions.empty())
        {
            std::cout << "Equation with infinite solutions:\n";
            equation->output();
        }
    }

    int equationsWithoutRealSolutions = 0;
    for (const auto &equation : equations)
    {
        auto solutions = equation->solve();
        if (solutions.empty())
        {
            ++equationsWithoutRealSolutions;
        }
    }

    std::cout << "Equations without real solutions: " << equationsWithoutRealSolutions << '\n';

    double smallestSolution = std::numeric_limits<double>::infinity();
    for (const auto &equation : equations)
    {
        auto solutions = equation->solve();
        for (double solution : solutions)
        {
            if (std::abs(solution) < std::abs(smallestSolution))
            {
                smallestSolution = solution;
            }
        }
    }

    std::cout << "Smallest solution by modulus: " << smallestSolution << '\n';

    double sumOfSquares = 0.0;
    for (const auto &equation : equations)
    {
        auto solutions = equation->solve();
        for (double solution : solutions)
        {
            sumOfSquares += solution * solution;
        }
    }

    std::cout << "Sum of squares of real solutions: " << sumOfSquares << '\n';

    return 0;
}


int main(){
    task16_1();
    task16_2();
    task16_10();
}