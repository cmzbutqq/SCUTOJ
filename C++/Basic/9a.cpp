#include <iostream>
#include <memory>
using namespace std;

const int PI = 3;

class Circle
{
protected:
    int radius;

public:
    Circle(int r = 0) : radius(r) {}
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    virtual int area() { return PI * radius * radius; }
};

class Sphere : public Circle
{
public:
    Sphere(int r = 0) : Circle(r) {}
    virtual int area() override { return 4 * PI * radius * radius; }
    virtual int volume() { return 4 * PI * radius * radius * radius / 3; }
};

class Column : public Circle
{
    int height;

public:
    Column(int r = 0, int h = 0) : Circle(r) { height = h; }
    virtual int area() override { return 2 * PI * radius * radius + 2 * PI * radius * height; }
    virtual int volume() { return PI * radius * radius * height; }
};
int main()
{
    int inR, inH;
    while (cin >> inR >> inH)
    {
        auto u_ptr1 = make_unique<Sphere>(inR);
        auto u_ptr2 = make_unique<Column>(inR, inH);
        cout << u_ptr1->volume() << ' ' << u_ptr1->area() << ' ' << u_ptr2->volume() << ' ' << u_ptr2->area() << endl;
    }
    return 0;
}