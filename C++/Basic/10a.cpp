#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T average(T *p)
{
    return (*p + *(p + 1) + *(p + 2)) / 3;
}

int main()
{
    int *pi = new int[3];
    double *pd = new double[3];
    while (cin >>
           *pi >> *(pi + 1) >> *(pi + 2) >>
           *pd >> *(pd + 1) >> *(pd + 2))
        cout << average(pi) << endl
             << setprecision(3) << average(pd) << endl;
    delete pi;
    delete pd;
    return 0;
}