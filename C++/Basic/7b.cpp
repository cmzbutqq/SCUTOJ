#include <iostream>
#include <memory>
using namespace std;

class Integer
{
    int value;

public:
    Integer(int v) : value(v) {}
    Integer() : value(0) {}
    int out() { return value; }

    Integer operator+(Integer &int2)
    {
        return Integer(this->value + int2.value);
    }

    Integer operator-(Integer &int2)
    {
        return Integer(this->value - int2.value);
    }

    Integer operator*(Integer &int2)
    {
        return Integer(this->value * int2.value);
    }

    Integer operator/(Integer &int2)
    {
        return Integer(this->value / int2.value);
    }
};

int main()
{
    char inChar;
    int in1, in2;
    while (cin >> inChar >> in1 >> in2)
    {
        auto p1 = make_unique<Integer>(in1);
        auto p2 = make_unique<Integer>(in2);
        switch (inChar)
        {
        case '+':
            cout << (*p1 + *p2).out() << endl;
            break;
        case '-':
            cout << (*p1 - *p2).out() << endl;
            break;
        case '*':
            cout << (*p1 * *p2).out() << endl;
            break;
        case '/':
            cout << (*p1 / *p2).out() << endl;
            break;
        default:
            cout << "error" << endl;
        }
    }
    return 0;
}
