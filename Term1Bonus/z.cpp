#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    string input;
    while (getline(cin, input))
    { // main loop
        // test area
        int counts[26] = {0};
        for (auto c : input)
        {
            if (c <= 'Z' && c >= 'A')
            {
                counts[c - 'A']++;
            }
            if (c <= 'z' && c >= 'a')
            {
                counts[c - 'a']++;
            }
        }

        int max_i = 0, max = 0;
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] > max)
            {
                max_i = i;
                max = counts[i];
            }
        }

        cout << (char)(max_i + 'a') << ' ' << max << endl;

        // test area /
    } // main loop /
    return 0;
}
