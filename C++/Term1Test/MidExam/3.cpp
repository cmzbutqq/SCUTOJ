#include <iostream>
using namespace std;
const int velocity = 10;

int main()
{
    double l_trainlength, d_tunnellength, time;
    while (cin >> l_trainlength >> d_tunnellength >> time)
    {
        double trainHead = velocity * time, trainTail = velocity * time - l_trainlength;
        if (trainTail >= d_tunnellength)
        {
            cout << 0 << endl;
            continue;
        }
        cout << min(trainHead, d_tunnellength) - max(trainTail, 0.0) << endl;
    }
    return 0;
}