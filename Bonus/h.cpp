#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 2;

int factorial(int input)
{
    int result = 1;
    for (int i = 2; i <= input; i++)
        result *= i;
    return result;
}

int c(int n, int m)
{
    return factorial(m) / (factorial(n) * factorial(m - n));
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

        cout << c(input[1], input[0]) << endl;

        // test area /
    } // main loop /
    return 0;
}
