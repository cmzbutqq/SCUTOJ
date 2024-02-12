#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int k;
    while (cin >> k)
    {
        if (k % 99 || k > 792)
        {
            cout << "None" << endl;
            continue;
        }
        int minus = k / 99;

        for (int hundreds = 1; hundreds <= 9 - minus; hundreds++)
        {
            for (int tens = 0; tens <= 9; tens++)
            {
                cout << hundreds << tens << hundreds + minus /* ones */ << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}