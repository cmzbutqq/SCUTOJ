#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int input;
    while (cin >> input)
    { // main loop
        // test area
        if (input % 3 == 2 && input % 5 == 3 && input % 7 == 2)
            cout << "1" << endl;
        else
            cout << "0" << endl;
        // test area /
    } // main loop /
    return 0;
}
