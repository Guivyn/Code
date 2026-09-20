#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double length;
        double width;
        public:
        Rectangle(double Length=10,double Width=5);
        double Area() const;
        double Perimeter() const;
};

Rectangle::Rectangle(double Length,double Width)
{
    length = Length;
    width = Width;
}

double Rectangle::Area() const
{
    return length * width;
}

double Rectangle::Perimeter() const
{
    return 2 * (length + width);
}

int main()
{
    double l, w, s1, s2, c, m;
    cin >> l >> w;
    Rectangle rect1(l,w);
    Rectangle rect2(l + 3, w + 3);
    s1 = rect1.Area();
    s2 = rect2.Area() - s1;
    m = s2 * 240;
    c = rect2.Perimeter()*50;
    cout << c << endl;
    cout << m << endl;
}