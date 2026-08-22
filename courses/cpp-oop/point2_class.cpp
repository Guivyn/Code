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
    // 删除 const
    Line2(Point2 &n, Point2 &m) : p1(n), p2(m) {}

    double Length()
    {
        double dx = p1.getx() - p2.getx();
        double dy = p1.gety() - p2.gety();
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Point2 pt1(1.0, 1.0);
    Point2 pt2(3.0, 4.0);
    Line2 line(pt1, pt2);
    cout << line.Length() << endl;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 改成正常变量，不使用临时对象
    Point2 p3(x1, y1);
    Point2 p4(x2, y2);
    Line2 nLine(p3, p4);
    cout << nLine.Length() << endl;

    return 0;
}