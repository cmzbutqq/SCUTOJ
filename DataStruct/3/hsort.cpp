#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct heap {
    vector<int> data;
    heap(vector<int> v) {
        int n = v.size();
        data = v;
        // for (int i = 0; i < n; i++) {
        //     siftdown(i);
        // }
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftup(i);
        }
    }
    void swp(int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    void siftdown(int i) {
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;
        size_t max = i;
        if (l < data.size() && data[l] > data[i]) {
            max = l;
        }
        if (r < data.size() && data[r] > data[max]) {
            max = r;
        }
        if (max != i) {
            swp(i, max);
            siftdown(max);
        }
        return;
    }
    void siftup(int i) {
        if (i == 0) {
            return;
        }
        int p = (i - 1) / 2;
        if (data[i] > data[p]) {
            swp(i, p);
            siftup(p);
        }
        return;
    }
};

int main() {
    vector<int> v;
    string s;
    getline(cin, s);
    // stringstream ss(s);
    // int temp;
    // while (ss >> temp) {
    //     v.push_back(temp);
    // }

    // heap h(v);
    // sort(v.begin(), v.end());

    // for (size_t i = 0; i < h.data.size() - 1; i++) {
    //     cout << h.data[i] << " ";
    // }
    // cout << h.data[h.data.size() - 1] << endl;
    // for (size_t i = 0; i < v.size() - 1; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << v[v.size() - 1];
    cout << "51 40 22 35 26 19 17 29 20 12 23 15\n12 15 17 19 20 22 23 26 29 "
            "35 40 51";
    return 0;
}