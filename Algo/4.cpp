#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> F(n), D(n), T(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> F[i];
    for (int i = 0; i < n; ++i)
        cin >> D[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> T[i];

    int maxFruit = 0;
    int totalTime = h * 12; // 单位为5分钟的块数

    for (int end = 0; end < n; ++end) {
        // 计算从1走到end所需的移动时间
        int walkTime = 0;
        for (int i = 0; i < end; ++i) {
            walkTime += T[i];
        }
        int remainTime = totalTime - walkTime;
        if (remainTime <= 0)
            continue;

        // 构造最大堆，每次取能摘最多果子的选项
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i <= end; ++i) {
            pq.emplace(F[i], i); // 当前果子数, 树的编号
        }

        vector<int> curF = F;
        int total = 0;

        for (int t = 0; t < remainTime; ++t) {
            if (pq.empty())
                break;
            auto [f, idx] = pq.top();
            pq.pop();
            total += f;
            curF[idx] = max(0, curF[idx] - D[idx]);
            pq.emplace(curF[idx], idx);
        }

        maxFruit = max(maxFruit, total);
    }

    cout << maxFruit << '\n';
    return 0;
}
