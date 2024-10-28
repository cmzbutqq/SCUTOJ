#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 2;

double legendre(int n, int x)
{
    switch (n)
    {
    case 0:
        return 1;
    case 1:
        return x;
    default:
        return ((2 * n - 1) * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) / double(n);
    }
}

int main(void)
{
    int input[input_length];
    while (cin >> input[0])
    { // main loop
        // input
        for (int i = 1; i < input_length; i++)
            cin >> input[i];
        // input /
        // test area
        cout << fixed << setprecision(4) << legendre(input[1], input[0]) << endl;
        // test area /
    } // main loop /
    return 0;
}
