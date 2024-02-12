#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    string input[2];
    int pos;
    while (cin >> input[0] >> input[1] >> pos)
    { // main loop
        // test area
        string ans = input[0];
        ans.insert(pos, input[1]);
        cout << ans << endl;
        // test area /
    } // main loop /
    return 0;
}
