#include <iostream>
using namespace std;

int countFactors(int input)
{
    if (input == 1)
        return 1;
    int counter = 2;
    for (int i = 2; i <= input / 2; i++)
    {
        if (input % i == 0)
            counter++;
    }
    return counter;
}

int main()
{
    int x1, x2;

    while (cin >> x1 >> x2)
    {
        int ans = 0, ansCount = 0;
        for (int x = x1; x <= x2; x++)
        {
            if (countFactors(x) >= ansCount)
            {
                ans = x;
                ansCount = countFactors(x);
            }
        }
        cout << ans << ' ' << ansCount << endl;
    }
    return 0;
}