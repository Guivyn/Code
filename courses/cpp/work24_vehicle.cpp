#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string name;
    string color;

public:
    Vehicle(string n, string m)
    {
        name = n;
        color = m;
    }
    virtual void display() = 0;
};

class Car : public Vehicle
{
private:
    int passenger;

public:
    Car(string n, string m, int p) : Vehicle(n, m)
    {
        passenger = p;
    }

    void display()
    {
        cout << "Car name:" << name << " Car color:" << color
            << " Car passenger:" << passenger << endl;
    }
};

class Truck : public Vehicle
{
private:
    double capacity; 

public:
    Truck(string n, string m, double c) : Vehicle(n, m)
    {
        capacity = c;
    }

    void display()
    {
        cout << "Truck name:" << name << " Truck color:" << color
            << " Truck capacity:" << capacity << endl;
    }
};

int main()
{
    Vehicle *p;
    char type;
    char name[110], color[110];
    int pas;
    double cap;

    while (cin >> type)
    {
        cin >> name >> color;
        if (type == 'C')
        {
            cin >> pas;
            Car car(name, color, pas);
            p = &car;
            p->display();
        }
        else if (type == 'T')
        {
            cin >> cap;
            Truck truck(name, color, cap);
            p = &truck;
            p->display();
        }
    }

    return 0;
}