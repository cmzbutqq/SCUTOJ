#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool on_prime(int input)
{
    if (input <= 1)
    {
        return false;
    }
    for (int i = 2, m = sqrt(input); i <= m; ++i)
    {
        if (input % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> list = {}, ans = {};
        for (int i = n; i >= 4; i -= 2)
            list.push_back(i);

        bool noAns = true;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (on_prime(*it))
            {
                ans.push_back(*it);
                noAns = false;
            }
        }

        for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        {
            cout << *it;
            if (it != ans.rend() - 1)
                cout << " ";
            else
                cout << endl;
        }

        if (noAns)
            cout << "None" << endl;
    }
    return 0;
}