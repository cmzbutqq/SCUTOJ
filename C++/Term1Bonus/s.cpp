#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 1;

int main(void)
{
    int length;
    while (cin >> length)
    { // main loop
        // input
        string cards[length];
        for (int i = 0; i < length; i++)
            cin >> cards[i];
        // input /
        // test area
        vector<string> cards_now;
        for (auto it : cards)
        {
            cards_now.push_back(it);
        }

        for (int i = 0; i < length; i++)
        {
            cards_now.push_back(cards_now[0]);
            cards_now.erase(cards_now.begin());

            cout << cards_now[0] << ((i == length - 1) ? "" : " ");
            cards_now.erase(cards_now.begin());
        }
        cout << endl;

        // test area /
    } // main loop /
    return 0;
}
