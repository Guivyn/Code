#include <iostream>
using namespace std;
class Complex
{
private:
    double x;
    double y;

public:
    Complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Complex &operator+=(const Complex &c)
    {
        x += c.x;
        y += c.y;
        return *this;
    }
    Complex &operator-=(const Complex &c)
    {
        x -= c.x;
        y -= c.y;
        return *this;
    }
    Complex &operator*=(const Complex &c)
    {
        double newX = x * c.x - y * c.y;
        double newY = x * c.y + y * c.x;
        x = newX;
        y = newY;
        return *this;
    }
    Complex &operator/=(const Complex &c)
    {
        double denom = c.x * c.x + c.y * c.y;
        double newX = (x * c.x + y * c.y) / denom;
        double newY = (y * c.x - x * c.y) / denom;
        x = newX;
        y = newY;
        return *this;
    }
    friend Complex operator+(const Complex &c1, const Complex &c2)
    {
        return Complex(c1.x + c2.x, c1.y + c2.y);
    }
    friend Complex operator-(const Complex &c1, const Complex &c2)
    {
        return Complex(c1.x - c2.x, c1.y - c2.y);
    }
    friend Complex operator*(const Complex &c1, const Complex &c2)
    {
        return Complex(c1.x * c2.x - c1.y * c2.y, c1.x * c2.y + c1.y * c2.x);
    }
    friend Complex operator/(const Complex &c1, const Complex &c2)
    {
        double denom = c2.x * c2.x + c2.y * c2.y;
        return Complex((c1.x * c2.x + c1.y * c2.y) / denom, (c1.y * c2.x - c1.x * c2.y) / denom);
    }
    friend bool operator==(const Complex &c1, const Complex &c2)
    {
        return c1.x == c2.x && c1.y == c2.y;
    }
    friend bool operator!=(const Complex &c1, const Complex &c2)
    {
        return !(c1 == c2);
    }
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << "(" << c.x << ", " << c.y << ")";
        return out;
    }
    friend istream &operator>>(istream &in, Complex &c)
    {
        in >> c.x >> c.y;
        return in;
    }
};
int main()
{
    Complex c1, c2;
    cin >> c1 >> c2;
    cout << "c1 = " << c1 << "\n"
         << "c2 = " << c2 << endl;
    cout << "c1+c2 = " << c1 + c2 << endl;
    cout << "c1-c2 = " << c1 - c2 << endl;
    cout << "c1*c2 = " << c1 * c2 << endl;
    cout << "c1/c2 = " << c1 / c2 << endl;
    cout << (c1 += c2) << endl;
    cout << (c1 -= c2) << endl;
    cout << (c1 *= c2) << endl;
    cout << (c1 /= c2) << endl;
    cout << (c1 == c2) << " " << (c1 != c2) << endl;
    return 0;
}