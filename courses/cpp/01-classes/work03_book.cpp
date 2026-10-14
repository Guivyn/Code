#include <iostream>
#include <cstring>
using namespace std;
class Book
{
private:
    char *name; //**书名

    char *author; //**作者

    int sale; //**销售量

public:
    Book(); //**无参构造函数

    Book(const char *, const char *, int); //**有参构造函数

    Book(const Book &); //**拷贝构造函数

    void print() const; //**显示数据

    ~Book(); //**析构函数
};

Book::Book()
{
    name = new char[10];
    strcpy(name,"No name");
    author = new char[10];
    strcpy(author,"No author");
    sale=0;
}

void Book::print() const
{
    cout << "Name: " << name << "\tAuthor: " << author << "\tSale: " << sale << endl;
}

Book::Book(const char *n, const char *a, int s)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    author = new char[strlen(a) + 1];
    strcpy(author, a);
    sale = s;
}

Book::Book(const Book&other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    author = new char[strlen(other.author) + 1];
    strcpy(author, other.author);
    sale = other.sale;
}

Book::~Book()
{
    delete[] name;
    delete[] author;
}

int main()
{
    char name[101], author[101];
    int sale;
    cin.getline(name, 101);
    cin.getline(author, 101);
    cin >> sale;
    if (strcmp(name, "-1") == 0 && strcmp(author, "-1") == 0 && sale == -1)
    {
        Book bk;
        bk.print();
    }
    else if (strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && sale == 0)
    {
        Book bk1;
        Book bk2(bk1);
        bk2.print();
    }
    else
    {
        Book bk(name, author, sale);
        bk.print();
    }
}