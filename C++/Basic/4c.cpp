#include <iostream>
#include <vector>
using namespace std;
int array[10];

void printArray()
{
    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[9] << endl;
    return;
}
void insertArray(int toInsert)
{
    for (int i = 0; i < 10; i++)
    {
        if (array[i] > toInsert)
        {
            int temp = array[i], next_temp;
            array[i] = toInsert;
            for (int j = i + 1; j < 10; j++)
            {
                next_temp = array[j];
                array[j] = temp;
                temp = next_temp;
            }
            break;
        }
    }

    return;
}

int main()
{

    cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4] >> array[5] >> array[6] >> array[7] >> array[8] >> array[9];
    int intToInsert;
    while (cin >> intToInsert)
    {
        insertArray(intToInsert);
        printArray();
    }
    return 0;
}