#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *s;

public:
    // 默认构造
    String()
    {
        s = new char[1];
        s[0] = '\0';
    }

    // 从C字符串构造
    String(const char *str)
    {
        if (str)
        {
            s = new char[strlen(str) + 1];
            strcpy(s, str);
        }
        else
        {
            s = new char[1];
            s[0] = '\0';
        }
    }

    // 拷贝构造（深拷贝）
    String(const String &other)
    {
        s = new char[strlen(other.s) + 1];
        strcpy(s, other.s);
    }

    // 析构函数
    ~String()
    {
        delete[] s;
    }

    // 赋值 = char*
    String &operator=(const char *str)
    {
        delete[] s;
        s = new char[strlen(str) + 1];
        strcpy(s, str);
        return *this;
    }

    // 赋值 = String
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] s;
            s = new char[strlen(other.s) + 1];
            strcpy(s, other.s);
        }
        return *this;
    }

    // +
    String operator+(const char *str)
    {
        String temp;
        delete[] temp.s;

        temp.s = new char[strlen(s) + strlen(str) + 1];
        strcpy(temp.s, s);
        strcat(temp.s, str);

        return temp;
    }

    String operator+(const String &other)
    {
        return *this + other.s;
    }

    // +=
    String &operator+=(const char *str)
    {
        char *temp = new char[strlen(s) + strlen(str) + 1];
        strcpy(temp, s);
        strcat(temp, str);

        delete[] s;
        s = temp;

        return *this;
    }

    String &operator+=(const String &other)
    {
        return (*this += other.s);
    }

    // 输入
    friend istream &operator>>(istream &in, String &str)
    {
        char buffer[1000];
        in >> buffer;

        delete[] str.s;
        str.s = new char[strlen(buffer) + 1];
        strcpy(str.s, buffer);

        return in;
    }

    // 输出
    friend ostream &operator<<(ostream &out, const String &str)
    {
        out << str.s;
        return out;
    }

    // ==
    friend bool operator==(const String &a, const char *b)
    {
        return strcmp(a.s, b) == 0;
    }

    friend bool operator==(const String &a, const String &b)
    {
        return strcmp(a.s, b.s) == 0;
    }

    // !=
    friend bool operator!=(const String &a, const char *b)
    {
        return !(a == b);
    }

    friend bool operator!=(const String &a, const String &b)
    {
        return !(a == b);
    }
};

int main()
{
    String s;
    s += "hello";
    cout << s << endl;

    String s1("String1");
    String s2("copy of ");
    s2 += "String1";
    cout << s1 << "\n"
         << s2 << endl;

    String s3;
    cin >> s3;
    cout << s3 << endl;

    String s4("String4"), s5(s4);
    cout << (s5 == s4) << endl;
    cout << (s5 != s4) << endl;

    String s6("End of "), s7("my string.");
    s6 += s7;
    cout << s6 << endl;

    return 0;
}