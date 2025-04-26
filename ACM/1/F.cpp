#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> computePrefixMedians(vector<int>& nums) {
    priority_queue<int> maxHeap;//smaller
    priority_queue<int, vector<int>, greater<int>> minHeap;//bigger
    vector<int> medians;

    for (int num : nums) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 计算当前中位数
        if (maxHeap.size() > minHeap.size()) {
            medians.push_back(maxHeap.top());
        } else {
            medians.push_back(min(maxHeap.top(), minHeap.top()));
        }
    }

    return medians;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> medians = computePrefixMedians(a);
    for (int i = 0; i < medians.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << medians[i];
    }
    cout << endl;

    return 0;
}