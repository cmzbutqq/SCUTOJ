#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int length;
    int width;

public:
    void Input(int l, int w)
    {
        length = l;
        width = w;
    }
    int Area() { return length * width; }
} r1;

class Rectangular : public Rectangle
{
    int height;

public:
    void Input(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }
    int Volume() { return length * width * height; }
} r2;

int main()
{
    int l1, w1, l2, w2, h2;
    while (cin >> l1 >> w1 >> l2 >> w2 >> h2)
    {
        r1.Input(l1, w1);
        r2.Input(l2, w2, h2);
        cout << r1.Area() << endl
             << r2.Volume() << endl;
    }
    return 0;
}