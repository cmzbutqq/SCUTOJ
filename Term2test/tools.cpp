#include <iostream>
#include <iomanip>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <memory> //unique_ptr shared_ptr

using namespace std;

// cout << fixed << setprecision(4) << output << endl;
// cout << setw(4) << output << endl;

const double e = 2.718281828;
const double pi = 3.141592654;

// int year, date;
// int month = 1, day = 0;
// int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//     days_of_month[1] = 29;

// 2D dynamic input
int main()
{
    int epoch_size, batch_size;
    while (cin >> epoch_size)
    { // main loop
        // input
        vector<vector<int>> epoch(epoch_size);
        for (int i = 0; i < epoch_size; i++)
        {
            cin >> batch_size;
            epoch[i].resize(batch_size);
            for (int j = 0; j < batch_size; j++)
                cin >> epoch[i][j];
        }
        // input /
        // test area

        for (auto batch : epoch)
        {

            int size = batch.size();
            for (int i = 0; i < size; i++)
            {
            }
            // for (auto item : batch)
            // {
            // }
            // for (auto it = batch.begin(); it != batch.end(); it++)
            // {
            // }
        }

        // test area /
    } // main loop /
    return 0;
}

// 1D dynamic input
int main()
{
    int batch_size;
    while (cin >> batch_size)
    { // main loop
        // input
        vector<int> batch(batch_size);
        for (int i = 0; i < batch_size; i++)
            cin >> batch[i];
        // input /
        // test area

        for (int i = 0; i < batch_size; i++)
        {
        }
        // for (auto item : batch)
        // {
        // }
        // for (auto it = batch.begin(); it != batch.end(); it++)
        // {
        // }

        // test area /
    } // main loop /
    return 0;
}

// 1D static input
const int batch_size = 3;
int main()
{
    int batch[batch_size];
    while (cin >> batch[0])
    { // main loop
        // input
        for (int i = 1; i < batch_size; i++)
            cin >> batch[i];
        // input /
        // test area

        for (int i = 0; i < batch_size; i++)
        {
        }
        // for (auto item : batch)
        // {
        // }

        // test area /
    } // main loop /
    return 0;
}

// custom input
int main()
{
    int custom;
    while (cin >> custom)
    { // main loop
      // input

        // input /
        // test area

        // test area /
    } // main loop /
    return 0;
}

// funcs

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

int countFactors(int input)
{ // done
    if (input == 1)
        return 1;
    int counter = 2;
    for (int i = 2; i <= input / 2; i++)
    {
        if (input % i == 0)
            counter++;
    }
    return counter;
}

bool on_prime(int input)
{ // done
    if (input <= 1)
    {
        return false;
    }
    for (int i = 2, m = sqrt(input); i <= m; ++i)
    {
        if (input % i == 0)
        {
            return false;
        }
    }
    return true;
}

double legendre(int n, int x)
{ // done
    switch (n)
    {
    case 0:
        return 1;
    case 1:
        return x;
    default:
        return ((2 * n - 1) * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) / double(n);
    }
}

int factorial(int input)
{ // done
    int result = 1;
    for (int i = 2; i <= input; i++)
        result *= i;
    return result;
}


