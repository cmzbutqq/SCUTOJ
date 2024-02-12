#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int input_length;
    while (cin >> input_length)
    { // main loop
        // input
        vector<int> input(input_length), index(input_length), value(input_length);
        for (int i = 0; i < input_length; i++)
            cin >> input[i];
        // input /
        // test area
        int hash[1000];
        for (int i = 0; i < 1000; i++)
            hash[i] = -1;
        for (int i = 0; i < input_length; i++)
            hash[input[i]] = i;

        int counter = 0;

        for (int i = 999; i >= 0; i--)
        {
            if (hash[i] != -1)
            {
                index[counter] = hash[i];
                value[counter] = i;
                counter++;
            }
        }

        cout << input_length << endl;

        for (int i = 0; i < input_length - 1; i++)
            cout << value[i] << " ";
        cout << value[input_length - 1] << endl;

        for (int i = 0; i < input_length - 1; i++)
            cout << index[i] << " ";
        cout << index[input_length - 1] << endl;
        // test area /
    } // main loop /
    return 0;
}
