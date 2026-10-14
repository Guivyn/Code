#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
private:
    double avg_price() const
    {
        return revenue / units_sold;
    }
    string bookNo;
    unsigned units_sold;
    double revenue;

public:
    Sales_data() : units_sold(0), revenue(0.0) {}
    Sales_data(const string &s, unsigned n, double r) : bookNo(s), units_sold(n), revenue(r) {}
    string get_bookNo() const
    {
        return bookNo;
    }
    Sales_data &operator+=(const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    friend istream &operator>>(istream &is, Sales_data &item)
    {
        is >> item.bookNo >> item.units_sold >> item.revenue;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Sales_data &item)
    {
        os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
        return os;
    }
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs)
    {
        return lhs.bookNo == rhs.bookNo;
    }
    friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
    {
        return !(lhs == rhs);
    }
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
    {
        Sales_data sum;
        sum += lhs;
        sum += rhs;
        return sum;
    }
};

int main()
{
    Sales_data item1, item2;
    while (cin >> item1 >> item2)
    {
        cout << item1 << "\n"
             << item2 << "\n";
        if (item1 == item2)
            cout << item1.get_bookNo() << " equals " << item2.get_bookNo() << "\n";
        if (item1 != item2)
            cout << item1.get_bookNo() << " doesn't equal " << item2.get_bookNo() << "\n";
        cout << (item1 + item2) << "\n";
        item1 += item2;
        cout << item1 << "\n";
    }
    return 0;
}