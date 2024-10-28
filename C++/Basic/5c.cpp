#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Points
{
    int x;
    int y;
};
void ifSquare(Points pointset[4]);

int main()
{
    int input_x;
    int input_y;
    Points pointset[4];
    int counter = 0;
    while (cin >> input_x >> input_y)
    {
        pointset[counter].x = input_x;
        pointset[counter].y = input_y;
        counter++;
        if (counter >= 4)
        {
            ifSquare(pointset);
            counter %= 4;
        }
    }
    return 0;
}
void ifSquare(Points pointset[4])
{
    int index = 0;
    string result = "no";
    int len[6];
    for (int start = 0; start < 3; start++)
    {
        for (int end = start + 1; end < 4; end++)
        {
            len[index] = pow(pointset[end].x - pointset[start].x, 2) + pow(pointset[end].y - pointset[start].y, 2);
            index++;
        }
    }
    sort(len, len + 6);
    if (len[5] == len[4] && len[3] == len[2] && len[2] == len[1] && len[1] == len[0] && len[5] == 2 * len[0])
    {
        result = "yes";
    }
    cout << result << endl;
    return;
}