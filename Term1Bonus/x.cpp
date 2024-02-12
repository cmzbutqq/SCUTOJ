#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool on_prime(int input)
{ // done
    if (input <= 1)
    {
        return false;
    }
    for (int i = 2, m = sqrt(input); i <= m; ++i)
    {
        if (input % i == 0)
        {
            return false;
        }
    }
    return true;
}

const int input_length = 1;

int main(void)
{
    int n, m;
    while (cin >> n >> m)
    { // main loop
        // test area
        bool has_out = false;
        for (int p = 2;; p++)
        {
            int i = pow(2, p) - 1;
            while (i < n)
            {
                p++;
                i = pow(2, p) - 1;
            }
            if (i > m)
                break;
            if (on_prime(i))
            {
                cout << i << (((2 * i + 1) > m) ? "\n" : " ");
                has_out = true;
            }
        }
        if (!has_out)
            cout << "-1\n";
        // test area /
    } // main loop /
    return 0;
}
