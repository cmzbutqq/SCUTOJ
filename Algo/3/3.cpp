#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isInWolfVision(int x, int y, int cx, int cy) {
    // Check if (x, y) is the wolf's position
    if (x == cx && y == cy) {
        return true;
    }
    // Check if (x, y) is in the wolf's one-step knight move positions
    int dx = abs(x - cx);
    int dy = abs(y - cy);
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

int main() {
    int n, m, cx, cy;
    cin >> n >> m >> cx >> cy;

    // Initialize DP table
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (isInWolfVision(i, j, cx, cy)) {
                dp[i][j] = 0;
            } else {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}