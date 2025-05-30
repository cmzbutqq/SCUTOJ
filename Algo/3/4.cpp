#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 205; // 2 * 100 + padding
long long dp[MAXN][MAXN];
int head[MAXN], tail[MAXN];

struct Egg {
    int head, tail;
} egg[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // 将蛋的头标记扩展成长度为 2n，模拟环
    for (int i = 0; i < 2 * n; ++i)
        head[i] = a[i % n];
    for (int i = 0; i < 2 * n; ++i)
        tail[i] = head[i + 1];

    long long ans = 0;

    // 枚举每个起点
    for (int s = 0; s < n; ++s) {
        // 初始化 dp 和 egg
        for (int i = 0; i < 2 * n; ++i)
            for (int j = 0; j < 2 * n; ++j)
                dp[i][j] = 0;

        for (int i = s; i < s + n; ++i)
            egg[i][i] = {head[i], tail[i]};

        // 区间DP
        for (int len = 2; len <= n; ++len) {
            for (int i = s; i + len - 1 < s + n; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {
                    long long energy = dp[i][k] + dp[k + 1][j] +
                                       1LL * egg[i][k].head * egg[i][k].tail *
                                           egg[k + 1][j].tail;

                    if (energy > dp[i][j]) {
                        dp[i][j] = energy;
                        egg[i][j] = {egg[i][k].head, egg[k + 1][j].tail};
                    }
                }
            }
        }

        ans = max(ans, dp[s][s + n - 1]);
    }

    cout << ans << endl;
    return 0;
}
