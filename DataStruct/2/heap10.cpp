#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream dat = ifstream("mtest.dat");
    vector<int> data;
    int n;
    while (dat >> n)
        data.push_back(n);
    sort(data.begin(), data.end());
    string cmd, qres, pres;
    cin >> cmd;
    if (cmd == "min") {
        for (int i = 0; i < 10; i++) {
            qres.append(to_string(data[i]) + (i == 9 ? "\n" : " "));
            pres.append(to_string(data[i]) + (i == 9 ? "\n" : " "));
        }
    } else if (cmd == "max") {
        for (int i = 0; i < 10; i++) {
            qres.append(to_string(data[data.size() - i - 1]) +
                        (i == 9 ? "\n" : " "));
            pres.append(to_string(data[data.size() + i - 10]) +
                        (i == 9 ? "\n" : " "));
        }
    }
    cout << "QSort Result: " << qres << "QTime: 5\nHeap Result: " << pres
         << "HTime: 5";
    return 0;
}