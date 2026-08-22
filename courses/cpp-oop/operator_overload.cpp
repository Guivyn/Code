#include<iostream>
using namespace std;
class Sales_data 
{

//依次输入书号、销量和收入

friend istream & operator>>(istream&, Sales_data &);

//依次输出书号、销量、收入和均价

friend ostream & operator<<(ostream &, const Sales_data &);

friend bool operator==(const Sales_data &, const Sales_data &);

friend bool operator!=(const Sales_data &, const Sales_data &);

// for "+", assume that both objects refer to the same book

friend Sales_data operator+(const Sales_data &, const Sales_data &);

public:

Sales_data(): units_sold(0), revenue(0.0) {}

Sales_data(const string & s, unsigned n, double r): bookNo(s), units_sold(n), revenue(r) {}

string get_bookNo() const;

// for "+=", assume that both objects refer to the same book

Sales_data & operator+=(const Sales_data &);

private:

double avg_price() const;  //均价，等于收入除以销量

string bookNo;        //书号

unsigned units_sold; //销量

double revenue;      //收入

};

istream & operator>>(istream& is, Sales_data &n)
{
    is >> n.bookNo >> n.units_sold >> n.revenue ;
    return is;
}
ostream & operator<<(ostream & os, const Sales_data & n)
{
    os << n.bookNo <<" "<< n.units_sold <<" "<< n.revenue <<" "<< n.avg_price();
    return os;
}

bool operator==(const Sales_data &n, const Sales_data &m)
{
    return n.bookNo == m.bookNo;
}
bool operator!=(const Sales_data &n, const Sales_data &m)
{
        return n.bookNo != m.bookNo;
}


string Sales_data::get_bookNo()const
{
    return bookNo;
}

// for "+=", assume that both objects refer to the same book

Sales_data &Sales_data:: operator+=(const Sales_data & a)
{
    revenue += a.revenue;
    units_sold += a.units_sold;
    return *this;
}

Sales_data operator+(const Sales_data &n, const Sales_data &m)
{
    Sales_data temp=n;
    temp += m;  // 直接使用已经定义好的 operator+=
    return temp;
}

double Sales_data:: avg_price() const
{
    double temp;
    if (units_sold == 0)
        return 0.0;
    temp = revenue / units_sold;
    return temp;
}

int main()
{

Sales_data item1,item2;

while(cin>>item1>>item2){

cout<<item1<<"\n"<<item2<<"\n";

if(item1==item2)

cout<<item1.get_bookNo()<<" equals "<<item2.get_bookNo()<<"\n";

if(item1!=item2)

cout<<item1.get_bookNo()<<" doesn't equal "<<item2.get_bookNo()<<"\n";

cout<<(item1+item2)<<"\n";

item1 += item2;

cout<<item1<<"\n";

}

return 0;

}