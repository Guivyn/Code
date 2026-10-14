#include<iostream>
#include<cmath>
using namespace std;
template<typename T>
class Vector
{
private:
    T x, y, z;
    public:
    Vector(T a=0,T b=0 ,T c=0)
    {
        x = a;
        y = b;
        z = c;
    }
    Vector operator+(Vector n) const
    {
        return Vector(x + n.x, y + n.y, z + n.z);
    }
    bool operator==(const Vector& n) const
{
    const double eps = 1e-6;
    return (fabs(x - n.x) < eps &&
            fabs(y - n.y) < eps &&
            fabs(z - n.z) < eps);
}
    friend Vector operator*(T scalar, const Vector& n)
    {
    return Vector(scalar * n.x, scalar * n.y, scalar * n.z);
    }   
    friend istream& operator>>(istream& is,Vector &n)
    {
        is >> n.x >> n.y >> n.z;
        return is;
    }
    friend ostream& operator<<(ostream& os,const Vector &n)
    {
        
        os << n.x << " " << n.y << " " << n.z;
        return os;
    }
};
int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    Vector<double> v1(a, b, c), v2(v1), v3, v4;
    double d;
    std::cin >> d;
    v4 = d * v1 + v2;

    std::cout << v4 <<std::endl;

    Vector<double>  v;
    std::cin >> v;

    int flag = (v4 == v);
    std::cout << flag << std::endl; 

    return 0;
}