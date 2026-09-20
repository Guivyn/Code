#include <iostream>
#include <string>
using namespace std;

class Hotel
{
private:
    static int sum;
    string name;
    int num;

public:
    void add(string n);
    static int getTotal();
    string getName();
    void print();
};
int Hotel::sum = 0;
void Hotel::add(string n)
{
    sum++;
    num = sum;
    name = n;
}

void Hotel::print()
{
    cout << num << " " << name << " " << sum << endl;
}

string Hotel::getName()
{
    return name;
}

int Hotel::getTotal()
{
    return sum;
}

int main()
{
    Hotel h[100];
    h[0].add("Susan");
    h[1].add("Peter");
    h[2].add("John");
    h[3].add("Mary");
    h[4].add("Alice");
    string name;
    cin >> name;

    for (int i = 0; i < Hotel::getTotal(); i++)
    {
        if (h[i].getName() == name)
        {
            h[i].print();
            break;
        }
    }

    return 0;
}