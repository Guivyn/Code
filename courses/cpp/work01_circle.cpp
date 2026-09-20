#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = acos(-1.0);
class Circle
{
    private:
        double r;
    public:
        void input();
        double area() const;
        void output() const;
};

void Circle::input()
{
    cin >> r;
}

double Circle::area() const
{
    return PI * r * r;
}

void Circle::output() const
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << area() << endl;
}
int main()
{
    Circle c;
    c.input();
    c.output();
}