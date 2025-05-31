#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
const int MAXM = 30;
const int INF = 1e9;

int n, m;
bitset<MAXM> A[MAXN]; // A[i]: 第 i 盏灯被哪些开关控制
int cost[MAXM];
bitset<MAXM> b; // 目标状态

int where[MAXN]; // where[i]: 第 i 行主元列号，-1 表示无

int min_cost = INF;

// 计算选中开关的费用和
int calc_cost(const bitset<MAXM> &x) {
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        if (x[i])
            sum += cost[i];
    }
    return sum;
}

// 递归枚举所有自由变量组合，寻找最小花费
void dfs(int idx, const vector<bitset<MAXM>> &directions, bitset<MAXM> &cur) {
    if (idx == (int)directions.size()) {
        int val = calc_cost(cur);
        if (val < min_cost)
            min_cost = val;
        return;
    }
    // 不选
    dfs(idx + 1, directions, cur);
    // 选
    cur ^= directions[idx];
    dfs(idx + 1, directions, cur);
    // 恢复
    cur ^= directions[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        b[i] = (s[i] == '1');
    }
    for (int i = 0; i < m; ++i)
        cin >> cost[i];
    for (int i = 0; i < m; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            if (row[j] == '1') {
                A[j][i] = 1;
            }
        }
    }

    memset(where, -1, sizeof(where));

    int rank = 0;
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = -1;
        for (int i = row; i < n; ++i) {
            if (A[i][col]) {
                sel = i;
                break;
            }
        }
        if (sel == -1)
            continue;

        // 交换行
        if (sel != row) {
            swap(A[sel], A[row]);
            // b 是 bitset，每一位是 bool，不能直接swap b[sel], b[row]
            bool tmp = b[sel];
            b[sel] = b[row];
            b[row] = tmp;
        }
        where[row] = col;

        for (int i = 0; i < n; ++i) {
            if (i != row && A[i][col]) {
                A[i] ^= A[row];
                b[i] = b[i] ^ b[row];
            }
        }
        ++row;
        ++rank;
    }

    // 检查无解情况
    for (int i = rank; i < n; ++i) {
        if (b[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // 构造特解 x
    bitset<MAXM> x;
    for (int i = 0; i < rank; ++i) {
        if (where[i] != -1) {
            x[where[i]] = b[i];
        }
    }

    // 构造自由变量方向向量
    vector<bitset<MAXM>> directions;
    for (int i = 0; i < m; ++i) {
        bool free_var = true;
        for (int j = 0; j < rank; ++j) {
            if (where[j] == i) {
                free_var = false;
                break;
            }
        }
        if (free_var) {
            bitset<MAXM> vec;
            vec[i] = 1;
            for (int j = 0; j < rank; ++j) {
                if (A[j][i]) {
                    vec[where[j]] = 1;
                }
            }
            directions.push_back(vec);
        }
    }

    dfs(0, directions, x);

    cout << (min_cost == INF ? -1 : min_cost) << "\n";

    return 0;
}
