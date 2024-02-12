#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float s(int m, int n, int p)
{
    float upper = 0, under = 0;
    upper += (m + 1) * m / 2.0;
    for (int i = 1; i <= n; i++)
    {
        upper += pow(i, 3);
    }
    for (int i = 1; i <= p; i++)
    {
        under += pow(i, 5);
    }
    return upper / under;
}
int main()
{
    int m, n, p;
    while (cin >> m >> n >> p)
    {
        cout << fixed << setprecision(4) << s(m, n, p) << endl;
    }
    return 0;
}