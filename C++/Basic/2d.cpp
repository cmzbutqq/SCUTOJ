#include <iostream>
using namespace std;
int main()
{
    int num;
    while (cin >> num)
    {
        for (int i = 2; i <= 135;)
        {
            if (num % i)
            {
                ++i;
            }
            else
            {
                cout << ' ' << i;
                num /= i;
            }
            if (num == 1)
            {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}