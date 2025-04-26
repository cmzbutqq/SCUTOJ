/*
A. 分钱
题目描述
你有n 枚货币，每个货币可能会有不同的价值，第i个货币的价值为vi
现在要把所有给定的货币分成两部分，要求这两份货币数目之差不超过
1，问这样分成的两份货币的价值之差最小是多少？
输入格式
本题单个测试点内有多组测试数据。

输入的第一行是一个正整数 T，表示该测试点内数据组数。

每组测试数据占两行。

第一行是一个整数 n，表示货币的个数。

第二行有 n 个整数，第 i 个整数表示第 i 个货币的价值vi

输出格式
对于每组数据输出一行一个整数表示答案。


样例数据
输入

2
3
3 3 6
4
1 2 3 6
输出

0
2

备注
1≤vi≤2^30
1≤T≤20,1≤n≤30

本题大家可以使用模拟退火来做。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double START_TEMP = 1e4;  // 起始温度
const double END_TEMP = 1e-4;   // 结束温度
const double DELTA = 0.995;     // 每次降温乘的系数

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 随机生成一个 [l, r] 的整数
int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        // 初始划分（前n/2个放一边，其他放另一边）
        vector<int> state(n, 0);
        for (int i = 0; i < n / 2; ++i) state[i] = 1;

        ll best_diff = LLONG_MAX;

        auto calc = [&](const vector<int>& st) {
            ll sum1 = 0, sum2 = 0;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; ++i) {
                if (st[i]) {
                    sum1 += v[i];
                    cnt1++;
                } else {
                    sum2 += v[i];
                    cnt2++;
                }
            }
            if (abs(cnt1 - cnt2) > 1) return LLONG_MAX;
            return abs(sum1 - sum2);
        };

        best_diff = calc(state);

        double temp = START_TEMP;

        while (temp > END_TEMP) {
            // 随机交换两个不同的元素
            int x = randint(0, n - 1);
            int y = randint(0, n - 1);
            while (x == y) y = randint(0, n - 1);
            swap(state[x], state[y]);

            ll new_diff = calc(state);

            ll delta = new_diff - best_diff;

            if (delta < 0 || exp(-delta / temp) > (double)rand() / RAND_MAX) {
                if (new_diff < best_diff) best_diff = new_diff;
                // 接受
            } else {
                swap(state[x], state[y]); // 撤销交换
            }

            temp *= DELTA;
        }

        cout << best_diff << '\n';
    }
}
