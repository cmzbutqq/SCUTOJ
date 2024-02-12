#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 3;

float s(int m, int n, int p)
{
    float upper = 0, lower = 0;
    for (int i = 1; i <= m; i++)
        upper += i;
    for (int i = 1; i <= n; i++)
        upper += pow(i, 3);
    for (int i = 1; i <= p; i++)
        lower += pow(i, 5);

    return upper / (float)(lower);
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
        cout << fixed << setprecision(4) << s(input[0], input[1], input[2]) << endl;
        // test area /
    } // main loop /
    return 0;
}
