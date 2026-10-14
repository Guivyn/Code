#include <iostream>
#include <string>
using namespace std;

class TestConstClass
{
private:
    string str;

public:
    void set(string n);
    string get() const;
};

string TestConstClass::get() const
{
    return str;
}

void TestConstClass::set(string n)
{
    str = n;
}
void print(const TestConstClass &tcs)
{
    cout << tcs.get() << '\n';
}

int main()
{
    string tmp;

    TestConstClass tcs;

    while (cin >> tmp)
    {

        tcs.set(tmp);

        print(tcs);
    }

    return 0;
}
