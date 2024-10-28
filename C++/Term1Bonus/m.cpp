#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 4;

struct complex
{
    float real;
    float imag;
    complex(float r, float i) : real(r), imag(i) {}
    complex operator+(complex b) { return complex(real + b.real, imag + b.imag); }
    complex operator-(complex b) { return complex(real - b.real, imag - b.imag); }

    void out()
    {
        cout << fixed << setprecision(4) << real << " " << imag << endl;
    }
};

int main(void)
{
    float input[input_length];
    char op;
    while (cin >> input[0])
    { // main loop
        // input
        for (int i = 1; i < input_length; i++)
            cin >> input[i];
        cin >> op;
        // input /
        // test area
        complex c1(input[0], input[1]), c2(input[2], input[3]);

        switch (op)
        {
        case '+':
            (c1 + c2).out();
            break;
        case '-':
            (c1 - c2).out();
            break;
        default:
            cout << "wtf" << endl;
        }
        // test area /
    } // main loop /
    return 0;
}
