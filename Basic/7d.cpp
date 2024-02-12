#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto split(string str)
{
    vector<string> result(0);
    string word;
    for (char c : str)
    {
        if (c == ' ')
        {
            result.push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    result.push_back(word);
    return result;
}

int main()
{
    string inputline;
    while (getline(cin, inputline))
    {
        vector<string> words = split(inputline);
        for (auto it = words.rbegin(); it != words.rend() - 1; it++)
        {
            cout << *it << " ";
        }
        cout << *(words.rend() - 1) << endl;
    }
    return 0;
}