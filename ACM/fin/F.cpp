#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    int sumA = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        sumA += a[i];
    }

    // dp[i][t]: 处理前i个队员，队伍1点餐时间累计为t时的最小最大完成时间
    // 初始化为较大值
    const int INF = INT_MAX / 2;
    vector<vector<int>> dp(N + 1, vector<int>(sumA + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        int ai = a[i - 1];
        int bi = b[i - 1];
        for (int t = 0; t <= sumA; t++) {
            if (dp[i - 1][t] == INF)
                continue;

            // 放队伍1
            if (t + ai <= sumA) {
                int finish1 = t + ai + bi; // 队伍1中第i个队员完成时间
                int val1 = max(dp[i - 1][t], finish1);
                if (val1 < dp[i][t + ai]) {
                    dp[i][t + ai] = val1;
                }
            }

            // 放队伍2
            // 队伍2的点餐时间是当前已处理总点餐时间减去队伍1点餐时间t
            int t2 = sumA - (t);
            int finish2 = t2 + bi;
            int val2 = max(dp[i - 1][t], finish2);
            if (val2 < dp[i][t]) {
                dp[i][t] = val2;
            }
        }
    }

    // 找最小的最大完成时间
    int ans = INF;
    for (int t = 0; t <= sumA; t++) {
        if (dp[N][t] < ans)
            ans = dp[N][t];
    }

    cout << ans << "\n";
    return 0;
}
