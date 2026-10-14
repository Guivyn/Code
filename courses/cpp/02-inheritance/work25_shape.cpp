#include <iostream>
#include <cmath>
using namespace std;

// 抽象基类 Shape
class Shape
{
public:
    Shape() {}
    virtual double area() = 0;
    virtual void input() = 0;
    virtual double volume() = 0;
    virtual ~Shape() {}
};

// 圆柱体
class Cylinder : public Shape
{
private:
    double radius;
    double height;

public:
    Cylinder() : radius(0), height(0) {}

    void input()
    {
        cin >> radius >> height;
    }

    double area()
    {
        return 2 * 3.14159 * radius * radius + 2 * 3.14159 * radius * height;
    }

    double volume()
    {
        return 3.14159 * radius * radius * height;
    }
};

// 长方体
class Cuboid : public Shape
{
private:
    double length;
    double width;
    double height;

public:
    Cuboid() : length(0), width(0), height(0) {}

    void input()
    {
        cin >> length >> width >> height;
    }

    double area()
    {
        return 2 * (length * width + length * height + width * height);
    }

    double volume()
    {
        return length * width * height;
    }
};

// 球体
class Ball : public Shape
{
private:
    double radius;

public:
    Ball() : radius(0) {}

    void input()
    {
        cin >> radius;
    }

    double area()
    {
        return 4 * 3.14159 * radius * radius;
    }

    double volume()
    {
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
    }
};

void work(Shape *s)
{
    s->input();
    cout << s->area() << " " << s->volume() << endl;
    delete s;
}

int main()
{
    char c;
    while (cin >> c)
    {
        switch (c)
        {
        case 'y':
            work(new Cylinder());
            break;
        case 'c':
            work(new Cuboid());
            break;
        case 'q':
            work(new Ball());
            break;
        default:
            break;
        }
    }
    return 0;
}