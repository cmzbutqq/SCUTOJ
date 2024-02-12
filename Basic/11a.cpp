#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double p_i=3.14159265;
double degree=p_i/180;

int main()
{
    int input;
    while (cin >> input)
    {
        for (int i = 1; i <= input; i++)
        {
            cout<<left<<setw(3)<<i<<fixed<<setprecision(5)<<
            setw(10)<<sin(i*degree)<<
            setw(10)<<cos(i*degree)<<
            setw(10)<<tan(i*degree)<<endl;
        }
    }
    return 0;
}