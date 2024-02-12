#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct chain
{
    char value;
    chain *next;
    chain() : value(' '), next(nullptr) {}
};

int main(void)
{
    string input;
    while (cin >> input)
    { // main loop
        // test area
        chain list[input.length()];

        list[0].value = input[0];
        list[0].next = nullptr;

        for (int i = 1; i < input.length(); i++)
        {
            list[i].value = input[i];
            list[i].next = &list[i - 1];
        }

        chain *p = &list[input.length() - 1];
        while (p != nullptr)
        {
            cout << (p->value);
            p = p->next;
        }
        // test area /
    } // main loop /
    return 0;
}
