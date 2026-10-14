#include <iostream>
#include <cmath>
using namespace std;

class Point2
{
private:
    double x;
    double y;

public:
    Point2(double n, double m)
    {
        x = n;
        y = m;
    }
    double getx()
    {
        return x;
    }
    double gety()
    {
        return y;
    }
};

class Line2
{
private:
    Point2 p1;
    Point2 p2;

public:
    Line2(const Point2 &n,const Point2 &m) : p1(n), p2(m) {};
    double Length()
    {
        double m, n;
        m = p1.getx() - p2.getx();
        n = p1.gety() - p2.gety();
        double len = sqrt(m * m + n * n);
        return len;
    }   
};

int main()
{
    Point2 pt1(1.0, 1.0);
    Point2 pt2(3.0, 4.0);
    Line2 line(pt1, pt2);
    std::cout << line.Length() << std::endl;

    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Line2 nLine(Point2(x1, y1), Point2(x2, y2));
    std::cout << nLine.Length() << std::endl;

    return 0;
}