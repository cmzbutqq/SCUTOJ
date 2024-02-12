#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 1;

int main(void)
{
    int input;
    while (cin >> input)
    { // main loop
        // test area
        int sum = 0;
        for (int factor = 1; factor < input; factor++)
        {
            if (input % factor == 0)
            {
                sum += factor;
            }
        }
        cout << ((sum == input) ? 1 : 0) << endl;
        // test area /
    } // main loop /
    return 0;
}
