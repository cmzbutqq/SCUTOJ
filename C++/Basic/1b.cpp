#include <iostream>
using namespace std;
int main()
{
    int x1, x2, x3;
    while (cin >> x1 >> x2 >> x3)
    {
        int min;
        min = x1 < x2 ? x1 : x2;
        min = min < x3 ? min : x3;
        cout << min << endl;
    }
    return 0;
}