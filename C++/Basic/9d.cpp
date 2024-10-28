#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = i;

        int counter = 0, size = v.size();
        for (;;)
        {
            size = v.size();
            if (size == 1)
                break;
            counter += m - 1;
            counter %= size;
            v.erase(v.begin() + counter);
        }
        cout << v[0] << endl;
    }
    return 0;
}