#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 3;

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
        sort(input, input + input_length);
        for (int i = 0; i < input_length-1; i++)
            cout << input[i] << " ";
        cout<< input[input_length-1] << endl;
        // test area /
    } // main loop /
    return 0;
}

