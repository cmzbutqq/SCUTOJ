#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max(int x1, int x2)
{
    return x1 > x2 ? x1 : x2;
}

int main(void)
{
    int sample_count, input_count;
    while (cin >> sample_count)
    { // main loop
        // input
        vector<vector<int>> input(sample_count);
        for (int i = 0; i < sample_count; i++)
        {
            cin >> input_count;
            input[i].resize(input_count);
            for (int j = 0; j < input_count; j++)
                cin >> input[i][j];
        }
        // input /
        // test area
        for (auto list : input)
        {
            // gen
            int maxes[list.size()];
            maxes[list.size() - 1] = -1;
            for (int i = list.size() - 2; i >= 0; --i)
                maxes[i] = max(maxes[i + 1], list[i + 1]);

            // print
            for (int i = 0; i < list.size(); i++)
                cout << maxes[i] << ((i == list.size() - 1) ? "\n" : " ");
        }
        // test area /
    } // main loop /
    return 0;
}
