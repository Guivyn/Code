#include <iostream>
#include <string>
using namespace std;
class Singer
{
private:
    string name;
    char sex;
    int age;
    double num;
public:
    string getName()
    {
        return name;
    }
    friend bool operator==(Singer s1,Singer s2)
    {
        return s1.num == s2.num;
    }
    friend bool operator>(Singer s1, Singer s2)
    {
        return s1.num > s2.num;
    }
    friend bool operator<(Singer s1, Singer s2)
    {
        return s1.num < s2.num;
    }
    friend ostream &operator<<(ostream& os,Singer& s)
    {
        os << s.name << " " << s.sex << " " << s.age << " " << s.num;
        return os;
    }
    friend istream &operator>>(istream &is,Singer& s)
    {
        is >> s.name >> s.sex >> s.age >> s.num;
        return is;
    }
};

int main()
{
    Singer s1, s2;
    cin >> s1 >> s2;
    cout << s1 << "\n"<< s2 << endl;
    if (s1 > s2)
        cout << s1.getName() << "'s score is higher than " << s2.getName() << "'s.\n";
    else if (s1 == s2)
        cout << s1.getName() << "'s score is equal to " << s2.getName() << "'s.\n";
    else
        cout << s1.getName() << "'s score is lower than " << s2.getName() << "'s.\n";
    return 0;
}
