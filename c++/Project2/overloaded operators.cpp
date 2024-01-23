/*
class Fraction {
private:
    int numerator{0};
    int denominator{ 1 };
public:
    Fraction(int numerator = 0, int denominator = 1) :
        numerator{ numerator }, denominator{ denominator }
    {
        reduce();
    }
    void print() {

        std::cout << numerator << "/" << denominator << "\n";
    }
    void reduce() {
        int gcd{ std::gcd(numerator,denominator) };
        if (gcd)
        {
            numerator /= gcd;
            denominator /= gcd;
        }
    }

    friend Fraction operator*(int value, const Fraction& c1);
    friend Fraction operator*(const Fraction& c1, int value);
    friend Fraction operator*(const Fraction& c1, const Fraction& c2);
    friend std::istream& operator>> (std::istream& in, Fraction& frac);
    friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);
    friend bool operator== (const Fraction& c1, const Fraction& c2);
    friend bool operator!= (const Fraction& c1, const Fraction& c2);
    friend bool operator< (const Fraction& c1, const Fraction& c2);
    friend bool operator> (const Fraction& c1, const Fraction& c2);
    friend bool operator<= (const Fraction& c1, const Fraction& c2);
    friend bool operator>= (const Fraction& c1, const Fraction& c2);
    Fraction& operator= (const Fraction& fraction);


};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fraction& Fraction::operator= (const Fraction& fraction)
{
    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}
Fraction operator*(int value, const Fraction& c1)
{
    return { c1.numerator * value, c1.denominator };
}
Fraction operator*(const Fraction& c1, const Fraction& c2)
{
    return { c1.numerator * c2.numerator, c1.denominator * c2.denominator };
}
Fraction operator*(const Fraction& c1, int value)
{
    return { c1.numerator * value, c1.denominator };
}
std::istream& operator>> (std::istream& in, Fraction& frac)
{

    in >> frac.numerator;
    in >> frac.denominator;

    return in;
}
std::ostream& operator<< (std::ostream& out, const Fraction& frac)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << frac.numerator << "/" << frac.denominator;

    return out;
}
bool operator== (const Fraction& c1, const Fraction& c2)
{
    return (c1.numerator == c2.numerator) && (c1.denominator == c2.denominator);
}
bool operator!= (const Fraction& c1, const Fraction& c2)
{
    return !(operator==(c1, c2));
}
bool operator< (const Fraction& c1, const Fraction& c2)
{
    return (c1.numerator * c2.denominator < c2.numerator* c1.denominator);
}
bool operator> (const Fraction& c1, const Fraction& c2)
{
    return operator<(c2, c1);
}
bool operator<= (const Fraction& c1, const Fraction& c2)
{
    return !(operator>(c1, c2));
}
bool operator>= (const Fraction& c1, const Fraction& c2)
{
    return !(operator<(c1, c2));
}






class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(const std::string& make, const std::string& model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
    friend std::ostream& operator<< (std::ostream& out, const Car& frac);
    friend bool operator<(const Car& c1, const Car& c2)
    {
        if (c1.m_make == c2.m_make) // If the car is the same make...
            return c1.m_model < c2.m_model; // then compare the model
        else
            return c1.m_make < c2.m_make; // otherwise compare the makes
    }
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
        c1.m_model != c2.m_model);
}
std::ostream& operator<< (std::ostream& out, const Car& frac)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << frac.m_make << "/" << frac.m_model;

    return out;
}


*/