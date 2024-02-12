#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void process(string str)
{
    string pure = "";
    for (char c : str)
    {
        if (c == '-' || c == ' ' || c == '(' || c == ')' || c == '+')
            continue;
        else if (c >= 'A' && c <= 'Z')
            pure += char(c + 'a' - 'A');
        else
            pure += c;
    }
    int plen = pure.length();

    bool on_email = false, on_plus = false;
    int atpos;
    for (int i = 0; i < plen; i++)
    {
        if (pure[i] == '@')
        {
            on_email = true;
            atpos = i;
            break;
        }
    }
    if (!on_email)
    {
        if (plen > 10)
            on_plus = true;
    }

    if (on_email)
    { // email
        cout << pure[0] << "*****";
        for (int i = atpos - 1; i < plen; i++)
            cout << pure[i];
        cout << endl;
    }
    else
    { // phone
        if (on_plus)
            cout << '+';

        string reversed_dashed = "";
        for (int i = 0; i < plen; i++)
        {
            reversed_dashed += pure[plen - 1 - i];
            if (i % 3 == 0 && i != plen - 1 && i >= 3)
                reversed_dashed += '-';
        }

        int dlen = reversed_dashed.length();
        for (int i = 0; i < dlen; i++)
        {
            if (reversed_dashed[dlen - 1 - i] == '-')
                cout << '-';
            else if (dlen - 1 - i <= 3)
                cout << reversed_dashed[dlen - 1 - i];
            else
                cout << '*';
        }
        cout << endl;
    }
}

int main(void)
{
    int length;
    while (cin >> length)
    { // main loop
        // input
        string temp;
        getline(cin, temp);

        string input[length];
        for (int i = 0; i < length; i++)
            getline(cin, input[i]);
        // input /
        // test area
        for (int i = 0; i < length; i++)
        {
            process(input[i]);
        }
        // test area /
    } // main loop /
    return 0;
}
