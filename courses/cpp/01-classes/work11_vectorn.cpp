#include <iostream>
#include <cmath>
using namespace std;

class VectorN
{
private:
    int dim;
    double *values;

public:
    double Mag();
    VectorN(int, double*);
};
double VectorN::Mag()
{
    double sum = 0;
    for (int i = 0; i < dim; i++)
    {
        sum += values[i] * values[i];
    }
    return sqrt(sum);
}
VectorN::VectorN(int n,double* m)
{
    dim=n;
    values = new double[dim];
    for (int i = 0; i < n; i++)
    {
        values[i]=m[i];
    }
}

int main()
{
    int num;
    cin >> num;
    double *dtemp = new double[num];
    for (int i = 0; i < num; i++)
        cin >> dtemp[i];
    VectorN vn2(num, dtemp);
    delete[] dtemp;
    cout << vn2.Mag() << endl;
    return 0;
}