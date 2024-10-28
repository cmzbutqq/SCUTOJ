#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, t;
    cin >> T;
    string s;
    getline(cin, s);
    while (T--) {
        vector<int> v;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> t)
            v.push_back(t);
        int r = v.size() - 1;
        int rv = v[r];
        int j = 0;
        for (int i = r - 1; i >= 0; i--) {
            if (v[i] < rv)
                j++;
        }
        cout << j << endl;
    }
    return 0;
}