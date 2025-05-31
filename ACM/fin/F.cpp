#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> people(N);
    // 每个人用 (b_i, a_i) 这样存，方便后面按 b 降序排序
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        people[i] = {b, a};
    }

    // 按 b_i（用餐时间）从大到小排序；若 b 相等，按 a 或者原来顺序也无妨
    sort(people.begin(), people.end(),
         [](const pair<int, int> &p1, const pair<int, int> &p2) {
             if (p1.first != p2.first)
                 return p1.first > p2.first;
             else
                 return p1.second < p2.second;
         });

    // 将排序后的 a、b 分离到单独数组，方便后面索引
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        b[i] = people[i - 1].first;  // 用餐时间
        a[i] = people[i - 1].second; // 点餐时间
    }

    // 计算前缀和 A[k] = a[1] + a[2] + ... + a[k]
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        A[i] = A[i - 1] + a[i];
    }
    int sumA = A[N]; // 所有人的 a_i 之和

    // dp[s] 表示：在当前已处理人数 k 的情况下，如果窗口1的累积点餐时间恰好是
    // s， 那么到目前为止“两个窗口的最坏完成时间(C +
    // b)”的最小可能值是多少。不可达时为 INF。
    const int INF = 1000000000;
    vector<int> dp(sumA + 1, INF), next_dp(sumA + 1, INF);

    // 初始：k = 0 时，窗口1的累积 = 0，两台都没做活，瓶颈完成时间 = 0
    dp[0] = 0;

    // 依次把第 k 个人（已经按 b 降序）分配到窗口1或窗口2
    for (int k = 1; k <= N; k++) {
        // 先把 next_dp 全部重置为 INF
        fill(next_dp.begin(), next_dp.end(), INF);

        // 遍历“窗口1 之前的累积点餐时间 s_old”
        for (int s_old = 0; s_old <= sumA; s_old++) {
            if (dp[s_old] == INF)
                continue;
            // 如果 dp[s_old] = INF 表示“前 k-1 个人不可能正好让窗口1累积为
            // s_old”，跳过

            // —— 方案 A：把第 k 个人放到窗口 1 ——
            int s1 = s_old + a[k];
            if (s1 <= sumA) {
                // 他在窗口1点餐结束时刻 = s1；加上他自己的 b[k]
                // 就是他的完成时刻
                int finish_if_window1 = s1 + b[k];
                // 两台机器原来的“最大(C+b)” = dp[s_old]
                // 新的瓶颈 = max(dp[s_old], finish_if_window1)
                int newBottleneckA = max(dp[s_old], finish_if_window1);
                next_dp[s1] = min(next_dp[s1], newBottleneckA);
            }

            // —— 方案 B：把第 k 个人放到窗口 2 ——
            // 窗口1 的累积继续保持 s_old
            // 窗口2 上，到第 k 个人前总共点餐 = (A[k-1] - s_old)，
            // 加上 a[k] 后，他自己在窗口2点餐结束时刻 = A[k] - s_old
            int t2 = A[k] - s_old;
            int finish_if_window2 = t2 + b[k];
            int newBottleneckB = max(dp[s_old], finish_if_window2);
            // 放到窗口2，不改变窗口1的累积 => next index 仍然是 s_old
            next_dp[s_old] = min(next_dp[s_old], newBottleneckB);
        }

        // 用 next_dp 覆盖 dp，准备下一轮
        dp.swap(next_dp);
    }

    // 最终答案 = min_{0 <= s <= sumA} dp[s]
    int answer = INF;
    for (int s = 0; s <= sumA; s++) {
        answer = min(answer, dp[s]);
    }

    cout << answer << "\n";
    return 0;
}
