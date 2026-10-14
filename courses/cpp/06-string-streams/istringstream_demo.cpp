#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    istringstream iss("12 34"); //定义输入流对象iss
    int a, b;
    iss >> a >> b; //从字符串输入流iss对象中读取两个数
    cout << a << " " << b << endl;
    ostringstream oss; //创建输出流对象oss
    oss << a << " " << b; //将数据输出到对象oss中
    cout << oss.str() << endl; //取出输出到oss中的值并显示。
}