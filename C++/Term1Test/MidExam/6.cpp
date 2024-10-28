#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int size = 2 * n + 1;
        for (int line = 0; line < n; line++)
        {
            for (int column = 0; column < size; column++)
            {
                if (column < line || column > size - 1 - line)
                    cout << ' ';
                else if (column <= n)
                    cout << char('A' + column);
                else
                    cout << char('A' + (size - 1 - column));
                if (column == size - 1)
                    cout << endl;
            }
        }
        for (int x = n; x < size; x++)
        {
            int line = size - 1 - x;
            for (int column = 0; column < size; column++)
            {
                if (column < line || column > size - 1 - line)
                    cout << ' ';
                else if (column <= n)
                    cout << char('A' + column);
                else
                    cout << char('A' + (size - 1 - column));
                if (column == size - 1)
                    cout << endl;
            }
        }
    }
    return 0;
}