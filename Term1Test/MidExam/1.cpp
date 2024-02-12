#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum(int min, int max)
{
    return (min + max) * (max - min + 1) / 2;
}

int main()
{
    int n;
    while (cin >> n)
    {
        bool on_exist = false;
        for (int x = 1; x <= n; ++x)
        {
            if (sum(1, x) == sum(x, n))
            {
                cout << x << endl;
                goto end;
            }
            if (sum(1, x) > sum(x, n))
            {
                goto no_outcome;
            }
        }
    no_outcome:
        cout << "-1" << endl;
    end:;
    }
    return 0;
}