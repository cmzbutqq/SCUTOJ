#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void markn(string &str)
{
    auto ifNum = [](char a)
    { return a >= '0' && a <= '9'; };
    for (int i = 0; i < str.size(); i++)
    {
        bool thisN = ifNum(str[i]);
        bool nextN = ifNum(str[i + 1]);
        if (thisN ^ nextN)
        {
            str.insert(i + 1, "*");
            i++;
        }
    }
}

int main()
{
    string str;
    while (cin >> str)
    {
        markn(str);
        cout << str;
    }
    return 0;
}