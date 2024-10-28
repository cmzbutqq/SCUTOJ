#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    bool long_flag = false, onRecord = true;
restart:
    while (getline(cin, input))
    { // line
        bool short_flag = false;
        for (auto it = input.begin(); it != input.end(); it++)
        { // char
            if (*it == '/' && *(it + 1) == '/')
                short_flag = true;

            if (*it == '/' && *(it + 1) == '*')
                long_flag = true;

            if (long_flag && *(it - 2) == '*' && *(it - 1) == '/')
                long_flag = false;
            if (long_flag && *(it - 1) == '*' && *it == '/' && it + 1 == input.end())
            {
                long_flag = false;
                goto restart;
            }

            onRecord = !(long_flag || short_flag);
            if (onRecord)
            {
                cout << *it;
            }
        }
        if (!long_flag)
        {
            cout << endl;
        }
    }

    return 0;
}