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
使用C++编程，先分析题目，再编写程序,仔细审题。考虑性能、边界情况与溢出
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
};

// 计算叉积
long long cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

// 计算多边形面积的2倍（有向面积）
long long polygonArea2(const vector<Point> &poly) {
    long long area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        area += cross(poly[i], poly[(i + 1) % n]);
    }
    return abs(area);
}

// 计算三角形面积的2倍
long long triangleArea2(const Point &a, const Point &b, const Point &c) {
    return abs(cross(b - a, c - a));
}

// 判断三角形是否退化（三点共线）
bool isDegenerate(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a) == 0;
}

// 快速幂计算 a^b mod MOD
long long powMod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 计算模逆元
long long invMod(long long a) { return powMod(a, MOD - 2); }

// 安全的模运算加法
long long addMod(long long a, long long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

// 安全的模运算乘法
long long mulMod(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }

    // 计算多边形面积的2倍
    long long polyArea2 = polygonArea2(poly);

    // 计算所有有效三角形面积之和的2倍
    long long totalTriangleArea2 = 0;

    // 枚举所有可能的三角形
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                Point a = poly[i], b = poly[j], c = poly[k];

                // 跳过退化三角形
                if (isDegenerate(a, b, c)) {
                    continue;
                }

                // 计算三角形面积的2倍
                long long area2 = triangleArea2(a, b, c);
                totalTriangleArea2 = addMod(totalTriangleArea2, area2 % MOD);
            }
        }
    }

    // 计算期望值 = totalTriangleArea2 / polyArea2
    long long polyAreaMod = polyArea2 % MOD;
    long long result = mulMod(totalTriangleArea2, invMod(polyAreaMod));

    cout << result << endl;

    return 0;
}