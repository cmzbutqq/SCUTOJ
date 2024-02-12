#include <iostream>
using namespace std;
int main()
{
    int x, y;
    while (cin >> x >> y)
    {
        bool bl = (x >= -2 && x <= 2 && y >= -2 && y <= 2);
        cout << (bl ? "true" : "false") << endl;
    }
    return 0;
}