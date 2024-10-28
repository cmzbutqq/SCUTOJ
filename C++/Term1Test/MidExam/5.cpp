#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool on_palindrome(int input)
{
    vector<int> list = {};
    for (int factor = 10; input != 0;)
    {
        list.push_back(input % factor);
        input -= input % factor;
        input /= 10;
    }
    vector<int> reversed_list;
    for (int i = list.size() - 1; i >= 0; i--)
    {
        reversed_list.push_back(list[i]);
    }
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] != reversed_list[i])
        {
            return false;
        }
    }
    return true;
}

bool onPrime(int input)
{
    if (input <= 1)
    {
        return false;
    }
    for (int i = 2, i_max = sqrt(input); i <= i_max; ++i)
    {
        if (input % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        bool noAns = true;
        vector<int> prime_list = {};
        for (int i = m; i <= n; i++)
        {
            if (onPrime(i))
                prime_list.push_back(i);
        }

        for (auto it = prime_list.begin(); it != prime_list.end(); it++)
        {
            if (on_palindrome(*it))
            {
                cout << *it << endl;
                noAns = false;
            }
        }
        if (noAns)
            cout << "无" << endl;
    }
    return 0;
}