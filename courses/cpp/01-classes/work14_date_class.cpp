#include <iostream>
#include <cstring>
using namespace std;

class Date
{
public:
    Date(int d = 0, int m = 0, int y = 0);
    int get_day() const;
    int get_month() const;
    int get_year() const;
    static void set_default(int, int, int);
    static int get_default_day();
    static int get_default_month();
    static int get_default_year();
    Date &add_year(int n);
    Date &add_month(int n);
    Date &add_day(int n);

private:
    int day, month, year;
    static Date default_date;
};

Date Date::default_date(1, 1, 1901);

Date::Date(int d, int m, int y)
{
    if (d == 0 && m == 0 && y == 0)
    {
        day = Date::default_date.day;
        month = Date::default_date.month;
        year = Date::default_date.year;
    }
    else
    {
        day = d;
        month = m;
        year = y;
    }
}

int Date::get_day() const
{
    return day;
}

int Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}

void Date::set_default(int d, int m, int y)
{
    Date::default_date.day = d;
    Date::default_date.month = m;
    Date::default_date.year = y;
}

int Date::get_default_day()
{
    return Date::default_date.day;
}

int Date::get_default_month()
{
    return Date::default_date.month;
}

int Date::get_default_year()
{
    return Date::default_date.year;
}

Date &Date::add_year(int n)
{
    year += n;
    return *this;
}

Date &Date::add_month(int n)
{
    month += n;
    while (month > 12)
    {
        month -= 12;
        year++;
    }
    return *this;
}

Date &Date::add_day(int n)
{
    day += n;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (1)
    {
        int max_day = days_in_month[month - 1];
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                max_day = 29;
            }
        }
        if (day <= max_day)
            break;
        day -= max_day;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}

int main()
{
    char type[110];
    int day, mon, year;
    int addday, addmon, addyear;
    while (cin >> type)
    {
        if (strcmp(type, "Date") == 0)
        {
            cin >> day >> mon >> year;
            Date mydate(day, mon, year);
            cin >> addday >> addmon >> addyear;
            mydate.add_day(addday).add_month(addmon).add_year(addyear);
            cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;
        }
        else if (strcmp(type, "defaultDate") == 0)
        {
            cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
        }
        else if (strcmp(type, "setdefaultDate") == 0)
        {
            cin >> day >> mon >> year;
            Date::set_default(day, mon, year);
            cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
        }
    }
    return 0;
}