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
        


        // test area /
    } // main loop /
    return 0;
}

