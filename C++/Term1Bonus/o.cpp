#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int input_length = 1;
const float eps = 1e-3;

struct pos
{
    float x;
    float y;
    pos() {}
    static float dist_squared(pos a, pos b)
    {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
};

bool check_equal(float a, float b)
{
    if ((a - b < eps) && (a - b > -eps))
        return true;
    else
        return false;
}

bool check_delta(pos a, pos b, pos c)
{
    if (check_equal(pos::dist_squared(a, b), pos::dist_squared(a, c)) && check_equal(pos::dist_squared(a, c), pos::dist_squared(b, c)))
        return true;
    else
        return false;
}

int main(void)
{
    pos a, b, c;
    while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)
    { // main loop
        // test area
        cout << check_delta(a, b, c) << endl;
        // test area /
    } // main loop /
    return 0;
}
