#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

const double e = 2.718281828459;

using namespace std;

double sh(double t)
{
    return (pow(e, t) - pow(e, -t)) / 2.0;
}

double y(double x)
{
    return sh(1 + sh(x)) / (sh(2 * x) + sh(3 * x));
}

int main(void)
{
    double input;
    while (cin >> input)
    { // main loop
      // test area
        cout << fixed << setprecision(4) << y(input) << endl;
        // test area /
    } // main loop /
    return 0;
}
