#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string input[2];
    while (cin >> input[0] >> input[1])
    {
        vector<string> v = {};
        for (int k = 0; k < 2; k++)
        {
            for (int start = 0, end = 8; end <= input[k].size(); start += 8, end += 8)
            {
                string batch = "";
                for (int i = start; i < end; i++)
                {
                    batch += input[k][i];
                }
                v.push_back(batch);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}