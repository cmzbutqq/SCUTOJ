#include <iostream>
using namespace std;
int clac_num(int i, int j)
{
    if (i == 1)
    {
        return (j + 1) * j / 2;
    }
    return clac_num(i - 1, j + 1) - 1;
}
int main()
{
    int num;
    while (cin >> num)
    {
        for (int i = 1, j = 1; clac_num(i, j) <= num;)
        {
            for (int j = 1; clac_num(i, j) <= num; j++)
            {
                cout << clac_num(i, j);
                if (clac_num(i, j + 1) <= num)
                {
                    cout << ' ';
                }
            }
            cout << endl;
            i++;
            j = 1;
        }
    }
    return 0;
}