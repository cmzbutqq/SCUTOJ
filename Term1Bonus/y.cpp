#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    string s1, s2;
    while (cin >> s1 >> s2)
    { // main loop
        // test area
        bool no_out = true;
        for (auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end(); ++it1, ++it2)
        {
            if (*it1 == *it2)
            {
                cout << *it1;
                no_out = false;
            }
            else
                break;
        }
        if (no_out)
            cout << -1;
        cout << endl;
        // test area /
    } // main loop /
    return 0;
}
