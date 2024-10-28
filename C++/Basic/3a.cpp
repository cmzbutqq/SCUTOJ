#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
float legendre(float x, int n)
{
    switch (n)
    {
    case 0:
        return 1;
    case 1:
        return x;
    default:
        return ((2 * n - 1) * x * legendre(x, n - 1) - (n - 1) * legendre(x, n - 2)) / ((float)n);
    };
}
int main()
{
    float x;
    int n;
    while (cin >> x >> n)
    {
        cout << fixed << setprecision(2) << legendre(x, n) << endl;
    }
    return 0;
}