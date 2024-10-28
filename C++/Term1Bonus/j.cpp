#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 1;

bool on_palindrome(int input)
{ // done
    string input_string = to_string(input);
    int digits = input_string.length();
    for (int i = 0; i <= digits / 2; i++)
    {
        if (input_string[i] != input_string[digits - i - 1])
            return false;
    }
    return true;
}

int main(void)
{
    int input[input_length];
    while (cin >> input[0])
    { // main loop
        // input
        for (int i = 1; i < input_length; i++)
            cin >> input[i];
        // input /
        // test area

        cout << on_palindrome(input[0]) << endl;

        // test area /
    } // main loop /
    return 0;
}
