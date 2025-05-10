
// 题目描述
// 给定一个由 n 个随机正整数组成的序列a。你的任务是计算以下和：
// ,sum_{i=1}^{n} ,sum_{j=1}^{n}(a_i,, mod ,, a_j)
// 输入格式
// 第一行一个整数 n (1≤n≤200000)
// 第二行给出 n 个以空格分隔的正整数，保证每个整数都是在 
// [1,10 ^12 ] 范围内随机生成
// 输出格式
// 输出一个整数，表示和取模 998244353 后的结果


// 样例数据
// 输入

// 2
// 3 5
// 输出

// 5

// 备注
// 1、 如果不会的话，可以对调和级数稍加思考哦：
// 1+1/2+1/3+1/4+...+1/n=ln(n+1)+r (r 为常量，约为 0.5772156649。ln 是底为自然常数 e 的对数函数)。
// 2、数据是随机生成的,可以认为其在取值区间内均匀分布

#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>
const int MOD = 998244353;
using ll=long long;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    ll asum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        asum += a[i];
    }

    ll res1_val;
    if (n == 0) {
        res1_val = 0;
    }
    else {
        ll n_mod = n % MOD;
        ll modsum = asum % MOD;
        res1_val = (n_mod * modsum) % MOD;
    }


    sort(a.begin(), a.end());

    ll actual_a_max = 0;
    if (n > 0) {
        actual_a_max = a[n - 1];
    }
    ll s2_val = 0;
    for (ll aj : a) {
        ll countsum = 0;
        for (ll km = aj; km <= actual_a_max; km += aj) {
            auto it = lower_bound(a.begin(), a.end(), km);
            ll count = distance(it, a.end());

            countsum = (countsum + count) % MOD;
        }
        ll current = aj % MOD;
        ll term = (current * countsum) % MOD;
        s2_val = (s2_val + term) % MOD;
    }
    ll final_ans = (res1_val - s2_val + MOD) % MOD;
    cout << final_ans << endl;
    return 0;
}