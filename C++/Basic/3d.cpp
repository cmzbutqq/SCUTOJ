#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
bool on_palindrome(int input)
{
    vector<int> numlist = {};
    for (int factor = 10; input != 0;)
    {
        numlist.push_back(input % factor);
        input -= input % factor;
        input /= 10;
    }
    vector<int> reversed_numlist;
    for (int i = numlist.size() - 1; i >= 0; i--)
    {
        reversed_numlist.push_back(numlist[i]);
    }
    for (int i = 0; i < numlist.size(); i++)
    {
        if (numlist[i] != reversed_numlist[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num;
    while (cin >> num)
    {
        string result = on_palindrome(num) ? "YES" : "NO";
        cout << result << endl;
    }
    return 0;
}