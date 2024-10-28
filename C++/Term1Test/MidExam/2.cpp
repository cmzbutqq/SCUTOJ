#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int input;
    while (cin >> input)
    {
        if (!(input >= 10 && input <= 1000000000))
        {
            cout << "-1" << endl;
            continue;
        }
        vector<int> digits = {}; // from 10^0 to 10^n
        vector<int> sums = {};
        for (int i = 10; input > 0;)
        {
            digits.push_back(input % i);
            input -= input % i;
            input /= 10;
        }

        for (int index = 1; index < digits.size(); index++)
        {
            int num1 = 0, num2 = 0;
            for (int i = 0; i < index; i++)
            {
                num1 += digits[i] * pow(10, i);
            }
            for (int i = index; i < digits.size(); i++)
            {
                num2 += digits[i] * pow(10, i - index);
            }
            sums.push_back(num1 + num2);
        }

        int min = sums[0];
        for (auto it = sums.begin(); it != sums.end(); it++)
        {
            min = *it < min ? *it : min;
        }
        cout << min << endl;
    }
    return 0;
}