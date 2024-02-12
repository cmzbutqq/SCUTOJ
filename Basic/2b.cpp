#include <iostream>
using namespace std;
int main()
{
    int a;
    while (cin >> a)
    {
        int i = 1, j = 1;
        for (int i = 1; i <= a; ++i, j = 1)
        {
            for (int j = 1; j <= a; ++j)
            {
                if (j == 1 || j == a || i == 1 || i == a)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}