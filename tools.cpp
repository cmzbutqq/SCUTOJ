// IO
#include <iostream>
#include <iomanip>
// STL
#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
// misc
#include <cmath>
#include <memory> //unique_ptr shared_ptr
// macros
#define FILTER(exp) \
    if (!(exp))     \
        continue;
#define SKIP(exp) \
    if (exp)      \
        continue;
#define END(exp) \
    if (exp)     \
        break;
#define REP(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++) //[a,b)

using namespace std;
namespace format
{
    void print_each(auto const &x, char const &placeholder = ' ')
    {
        for (auto it = x.begin(); it != x.end(); it++)
        {
            if (it == x.begin())
                cout << *it;
            else
                cout << placeholder << *it;
        }
        cout << endl;
    }
    void for_each(auto const &func, auto const &x)
    {
        for (auto it = x.begin(); it != x.end(); it++)
            func(x);
    }
    void print_float(double num, uint8_t precision = 4)
    {
        cout << fixed << setprecision(precision) << num << endl;
    }
    void print_width(double output, uint8_t width = 4)
    {
        cout << setw(width) << output << endl;
    }
}

namespace view
{
    std::vector<int> Range(
        const int &bottom, const int &top, const unsigned &step = 1,
        bool filter(int) = [](int index)
        { return true; })
    { //[bottom,top)
        if (bottom >= top)
            throw("bottom>top");
        std::vector<int> v = {};
        for (int i = bottom; i < top; i += step)
        {
            FILTER(filter(i));
            v.push_back(i);
        }
        return v;
    }
}

namespace math
{
    const double e = 2.718281828;
    const double pi = 3.141592654;

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
}

// int year, date;
// int month = 1, day = 0;
// int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//     days_of_month[1] = 29;
