#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string input;
    while (cin >> input)
    {
        for (int start = 0, end = 16; end <= input.size(); start += 16, end += 16)
        {

            cout << setbase(16) << setfill('0') << setw(8) << end << "  ";

            for (int i = start; i < end; i++)
            {
                cout << setbase(16) << int(input[i]) << ' ';
            }
            cout << ' ';
            for (auto it = input.begin() + start; it != input.begin() + end; it++)
            {
                cout << *it;
            }
            cout << endl;
        }
    }
    return 0;
}