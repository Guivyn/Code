#include<iostream>
using namespace std;

class Complex
{
    private:
        double a;
        double b;
        public:
        Complex(double aa=0,double bb=0)
        {
            a = aa;
            b = bb;
        }
            Complex operator+(Complex &)
            {
                Complex temp;
                temp.a=this->a + a;
                temp.b=this->b + b;
                return temp;
            }
            void show()
            {
                cout<<a<<"+"<<b<<"i"<<endl;
            }
};

int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(2, 3);
    Complex c3=c1+c2;
    c3.show();
}