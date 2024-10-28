#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int length;
    while (cin >> length)
    { // main loop
        // input
        int score[length];
        string name[length];
        for (int i = 0; i < length; i++)
        {
            cin >> name[i] >> score[i];
        }
        // input /
        // test area
        int index = 0, maxScore = score[0];
        for (int i = 0; i < length; i++)
        {
            if (score[i] > maxScore)
            {
                maxScore = score[i];
                index = i;
            }
        }
        cout << name[index] << endl;
        // test area /
    } // main loop /
    return 0;
}
