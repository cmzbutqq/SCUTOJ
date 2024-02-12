#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int length1, length2;
    while (cin >> length1)
    { // main loop
        // input
        int input1[length1];
        for (int i = 0; i < length1; i++)
            cin >> input1[i];
        cin >> length2;
        int input2[length2];
        for (int i = 0; i < length2; i++)
            cin >> input2[i];
        // input /
        // test area
        int length = length1 + length2;
        int result[length];
        for (int i = 0; i < length1; i++)
            result[i] = input1[i];
        for (int i = 0; i < length2; i++)
        {
            result[i + length1] = input2[i];
        }

        sort(result, result + length);

        cout << length << endl;

        for (int i = 0; i < length - 1; i++)
            cout << result[i] << ' ';
        cout << result[length - 1] << endl;

        // test area /
    } // main loop /
    return 0;
}
