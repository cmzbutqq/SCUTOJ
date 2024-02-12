#include <iostream>
using namespace std;
int to2(int input)
{
    for (int factor = 128; factor >= 1; factor /= 2)
    {
        cout << input / factor;
        input %= factor;
    }
    return 0;
}
int to16(int input)
{
    for (int factor = 16; factor >= 1; factor /= 16)
    {
        int toPrint = input / factor;
        switch (toPrint)
        {
        case 10:
            cout << 'a';
            break;
        case 11:
            cout << 'b';
            break;
        case 12:
            cout << 'c';
            break;
        case 13:
            cout << 'd';
            break;
        case 14:
            cout << 'e';
            break;
        case 15:
            cout << 'f';
            break;
        default:
            cout << toPrint;
        }
        input %= factor;
    }
    return 0;
}
int main()
{
    int num;
    while (cin >> num)
    {
        cout << ' ';
        to2(num);
        cout << ' ';
        to16(num);
        cout << endl;
    }
    return 0;
}