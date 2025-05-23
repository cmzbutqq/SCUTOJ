#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<pair<int, int>> intervals(t);
    for (int i = 0; i < t; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // 按右端点排序
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a.second < b.second; });

    int count = 0;
    int last_end = -2e9 - 1; // 初始化为比最小 l 还小

    for (auto &[l, r] : intervals) {
        if (l >= last_end) { 
            ++count;
            last_end = r;
        }
    }

    cout << count << '\n';
    return 0;
}
