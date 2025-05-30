#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int maxReach = 0;
    for (int i = 0; i < N; ++i) {
        if (i > maxReach)
            break; // 如果当前位置已经无法到达，停止
        maxReach = max(maxReach, i + nums[i]);
    }

    cout << min(maxReach,N-1) << endl;
    return 0;
}
