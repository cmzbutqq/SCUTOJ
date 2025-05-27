/*
题目描述
在2187年，人类发现了一种能寄生在量子态中的外星生物一"幽影体"。它们会随机出现在量子防御矩阵（一个严格凸多边形区域）内，传统武器无法对其造成伤害。
科学部开发了新型"三角定位湮灭炮"，只有当三台定位器（部署在多边形顶点）同时锁定时（即位于三个顶点形成的三角形内部），才能消灭幽影体。由于量子不确定性，幽影体出现的位置是矩阵内的随机位置。
给定严格凸多边形的n个顶点（按逆时针顺序），求幽影体出现在凸多边形内时，能被多少个不同的三元组定位器锁定的期望值。由于结果可能是分数，请输出其对998244353取模的值。
输入格式
·第一行一个整数n(3≤n≤2×10^5)
·接下来n行，每行两个整数x,y表示顶点坐标(|x|,|y|≤10^9)
输出格式
·输出期望值对998244353取模的结果
样例数据
输入
4
0 0
1 0
1 1
0 1
输出
2
备注
1.对于凸多边形，所有三角形的包含概率之和可以用面积关系计算
2.需要计算模意义下的分数，使用费马小定理求逆元
使用C++编程，先分析题目，再编写程序,仔细审题。考虑性能、边界情况与溢出。O(n³)的算法会超时。答案并非只由n决定，点的坐标也会影响答案。不要盲目地使用O(n³)的算法，需要对问题进行深入的分析和优化。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll mod_pow(ll a, ll e = MOD - 2) {
    ll r = 1;
    while (e) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Compute 2 * polygon area S2 = sum_{i}(cross(P_i,P_{i+1}))
    ll S2 = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        S2 = (S2 + (x[i] * y[j] % MOD) - (y[i] * x[j] % MOD) + MOD) % MOD;
    }

    // Precompute suffix sums for term1
    vector<ll> A(n);
    for (int j = 0; j < n; j++) {
        A[j] = (n - 1 - j) % MOD;
    }
    vector<ll> sufX(n + 1), sufY(n + 1), sufAX(n + 1), sufAY(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        sufX[i] = (sufX[i + 1] + x[i]) % MOD;
        sufY[i] = (sufY[i + 1] + y[i]) % MOD;
        sufAX[i] = (sufAX[i + 1] + x[i] * A[i] % MOD) % MOD;
        sufAY[i] = (sufAY[i + 1] + y[i] * A[i] % MOD) % MOD;
    }

    // Prefix sums for term2 and term3
    vector<ll> preX(n), preY(n), preXi(n), preYi(n);
    ll sumX = 0, sumY = 0, sumXi = 0, sumYi = 0;
    for (int i = 0; i < n; i++) {
        preX[i] = sumX;
        preY[i] = sumY;
        preXi[i] = sumXi;
        preYi[i] = sumYi;
        sumX = (sumX + x[i]) % MOD;
        sumY = (sumY + y[i]) % MOD;
        sumXi = (sumXi + x[i] * i) % MOD;
        sumYi = (sumYi + y[i] * i) % MOD;
    }

    // Prefix sums weighted by index for term2
    vector<ll> preWX(n), preWY(n);
    ll accumWX = 0, accumWY = 0;
    for (int i = 0; i < n; i++) {
        preWX[i] = accumWX;
        preWY[i] = accumWY;
        accumWX = (accumWX + x[i] * i) % MOD;
        accumWY = (accumWY + y[i] * i) % MOD;
    }

    ll T = 0;
    // term1: sum_{i<j} cross(i,j)*(n-1-j)
    for (int i = 0; i < n; i++) {
        ll sx = sufAY[i + 1]; // sum y[j]*(n-1-j)
        ll sy = sufAX[i + 1]; // sum x[j]*(n-1-j)
        ll t1 = (x[i] * sx % MOD - y[i] * sy % MOD + MOD) % MOD;
        T = (T + t1) % MOD;
    }

    // term2: sum_{j<k} cross(j,k)*j
    for (int k = 0; k < n; k++) {
        ll sx = preWX[k]; // sum x[j]*j for j<k
        ll sy = preWY[k]; // sum y[j]*j for j<k
        ll t2 = (y[k] * sx % MOD - x[k] * sy % MOD + MOD) % MOD;
        T = (T + t2) % MOD;
    }

    // term3: - sum_{i<k} cross(i,k)*(k-i-1)
    for (int k = 0; k < n; k++) {
        ll Sx = preX[k];
        ll Sy = preY[k];
        ll Sxi = preXi[k];
        ll Syi = preYi[k];
        ll factor = (k - 1 + MOD) % MOD;
        ll part = (y[k] * ((factor * Sx % MOD - Sxi + MOD) % MOD) % MOD -
                   x[k] * ((factor * Sy % MOD - Syi + MOD) % MOD) % MOD + MOD) %
                  MOD;
        T = (T - part + MOD) % MOD;
    }

    // Expectation = T / S2 mod
    ll ans = T * mod_pow(S2) % MOD;
    cout << ans << "\n";
    return 0;
}
