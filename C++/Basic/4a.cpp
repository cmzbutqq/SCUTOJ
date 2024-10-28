#include <iostream>
using namespace std;
int main()
{
    int size;
    while (cin >> size)
    {
        int matrix[size][size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j >= i)
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = i - j + 1;
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j];
                if (j < size - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                sum += matrix[i][j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}