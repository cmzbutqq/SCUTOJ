#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 1;

int main(void)
{
    int year, date;
    while (cin >> year >> date)
    { // main loop
        // test area
        int month = 1, day = 0;
        int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            days_of_month[1] = 29;

        for (auto it : days_of_month)
        {
            if (date <= it)
            {
                day = date;
                break;
            }
            else
            {
                month++;
                date -= it;
            }
        }

        cout << year << "/" << month << "/" << day << endl;

        // test area /
    } // main loop /
    return 0;
}
