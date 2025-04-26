/*
题目描述
在古老的魔法王国中，大法师需要激活一座远古魔法阵。魔法阵由n个共鸣节点组成，每个节点必须嵌入一颗魔法石。魔法石的能量会与之前节点的能量产生共鸣，其规则如下：
每个节点的共鸣值可以选择被抑制(贡献为0)，或释放为前序所有节点能量总和的能量减去自身能量。大法师的目标是找到魔法石的最优排列，使得整个魔法阵的总共鸣值达到最大，从而唤醒阵法的终极力量。
给定 n
个整数(a1,a2，··,an)，将其排列为序列(bi,b2，··,bn)。对于每个位置i,贡献值Ci=\sigma bj -bi(1≤j<i)或者 ci = 0 请计算所有位置贡献之和的最大可能值。 输入格式
·第一行为整数 n(1n≤10^6).
·第二行为n个整数 a1,a2,·..,an(1≤ai≤10^6)
输出格式
输出一个整数，表示最大总贡献值。
样例数据
输入
3
1 2 3
输出
5
备注
·排列为[3,2,1]，每个位置贡献为[0, 1,4]
·注意结果可能较大，可以用 ll
*/
#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 将数组降序排序
    sort(a.begin(), a.end(), greater<ll>());

    ll total_sum = 0;
    for (ll num : a) {
        total_sum += num;
    }

    ll weighted_sum = 0;
    ll prefix_sum = a[0];
    weighted_sum += n * a[0];

    for (ll i = 1; i < n - 1; ++i) {
        prefix_sum += a[i];
        weighted_sum += (n - i - 1) * a[i];
    }

    ll max_contribution = weighted_sum - total_sum;

    cout << max_contribution << endl;

    return 0;
}