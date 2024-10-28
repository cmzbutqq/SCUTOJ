#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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
            // sort
            sort(list.begin(), list.end());
            // get min diff
            int min_diff = list[1] - list[0];
            int length = list.size();
            for (int i = 0; i < length - 1; i++)
            {
                min_diff = min(min_diff, list[i + 1] - list[i]);
            }
            // get indexes of elements to print
            vector<int> index = {};
            for (int i = 0; i < length - 1; i++)
            {
                if (min_diff == list[i + 1] - list[i])
                    index.push_back(i);
            }
            // print
            for (auto it = index.begin(); it != index.end(); it++)
            {
                cout << list[*it] << ' ' << list[*it + 1];
                if (it != index.end() - 1)
                    cout << ' ';
                else
                    cout << endl;
            }
        }
        // test area /
    } // main loop /
    return 0;
}
