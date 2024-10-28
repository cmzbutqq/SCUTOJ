#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, num;
    while (cin >> num)
    {
        a = num / 10000;
        b = num % 10000 / 1000;
        c = num % 1000 / 100;
        d = num % 100 / 10;
        e = num % 10;
        cout << "  " << e << "  " << d << "  " << c << "  " << b << "  " << a << endl;
    }
    return 0;
}