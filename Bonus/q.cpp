#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    string input;
    while (cin >> input)
    { // main loop
        // test area
        for (auto it : input)
        {
            cout << it << '*';
        }
        cout << endl;
        // test area /
    } // main loop /
    return 0;
}
