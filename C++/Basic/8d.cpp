#include <iostream>
using namespace std;

class SquareMatrix
{
    int size;
    int **ptr;

public:
    SquareMatrix()
    {
        size = 0;
        ptr = nullptr;
    }
    SquareMatrix(int n)
    {
        init(n);
        input();
        printM();
    }
    ~SquareMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            delete *(ptr + i);
        }
        delete ptr;
    }
    void init(int n)
    {
        size = n;
        ptr = new int *[size];
        for (int i = 0; i < size; i++)
        {
            *(ptr + i) = new int[size];
        }
    }

    int get(int i, int j)
    {
        int *prow = *(ptr + i);
        int element = *(prow + j);
        return element;
    }

    void set(int i, int j, int value)
    {
        int *prow = *(ptr + i);
        *(prow + j) = value;
        return;
    }

    void input()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int value;
                cin >> value;
                set(i, j, value);
            }
        }
    }

    void printM()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << get(size - 1 - j, i) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int size;
    while (cin >> size)
    {
        SquareMatrix Matrix(size);
    }
}