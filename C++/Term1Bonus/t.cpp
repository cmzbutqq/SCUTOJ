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
        for (auto it : input)
        {
            sort(it.begin(), it.end());
            if (it[0] != it[1])
                cout << it[0];
            for (int i = 1; i < it.size() - 1; i++)
            {
                if (it[i] != it[i - 1] && it[i] != it[i + 1])
                    cout << it[i];
            }
            if (it[it.size() - 1] != it[it.size() - 2])
                cout << it[it.size() - 1];
            cout << endl;
        }
        // test area /
    } // main loop /
    return 0;
}
