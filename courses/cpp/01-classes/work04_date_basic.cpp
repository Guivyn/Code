#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int Date_year;
    int Date_month;
    int Date_day;

public:
    Date(int year = 2000, int month = 1, int day = 1);
    void show() const;
};

Date::Date(int year, int month, int day)
{
    Date_year = year;
    Date_month = month;
    Date_day = day;
}

void Date::show() const
{
    cout << Date_year << "-" << Date_month << "-" << Date_day;
}

class Roster
{
private:
    string name;
    Date birthday;

public:
    Roster();
    Roster(string name, int year, int month, int day);
    Roster(string name, Date date);
    void show() const;
};

Roster::Roster()
{
    name = "NULL";
    birthday = Date(0, 0, 0);
}

Roster::Roster(string n, int year, int month, int day)
{
    name = n;
    birthday = Date(year, month, day);
}

Roster::Roster(string n, Date date)
{
    name = n;
    birthday = date;
}

void Roster::show() const
{
    cout << "Name: " << name << ", Birthday: ";
    birthday.show();
    cout << endl;
}

int main()
{
    int choice;
    while (cin >> choice)
    {
        if (choice == -1)
        {
            break;
        }
        else if (choice == 0)
        {
            Roster c;
            c.show();
        }
        else if (choice == 1)
        {
            string name;
            int year, month, day;
            cin >> name >> year >> month >> day;
            Roster c(name, year, month, day);
            c.show();
        }
        else if (choice == 2)
        {
            string name;
            int year, month, day;
            cin >> name >> year >> month >> day;
            Date date(year, month, day);
            Roster c(name, date);
            c.show();
        }
    }
    return 0;
}