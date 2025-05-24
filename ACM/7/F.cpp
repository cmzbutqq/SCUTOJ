/*
题目描述
给出一个n个在二维平面上的点，你需要找到一个最小的凸壳，使得该凸壳包含了所有的个点。注意，你不仅需要找到该凸壳所有的顶点，若n个点中有点也在凸壳的边上，你也需要将其输出。
输入格式
第一行一个整数n.
接下来n行，第i行两个整数xi,yi表示第i个点的坐标。
输出格式
第一行输出一个整数，表示凸壳的点数。
接下来的每一行，输出两个整数，表示一个在凸壳上的点。
坐标应按逆时针的顺序给出，由拥有最小的y坐标的点打头，若存在多个y坐标最小的点，则从其中x坐标最小的点开始。
样例数据
输入
7
1 3
2 1
2 2
1 2
3 3
4 2
0 0
输出
5
0 0
2 1
4 2
3 3
1 3
备注
3≤n≤10^5
0≤|xil,lyil≤10^4
数据可能存在多个坐标相同的点。
使用C++编程，先分析题目，再编写程序,仔细审题。考虑性能、边界情况与溢出
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
};

// 叉积
long long cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    // 去重
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    int m = points.size();
    if (m <= 2) {
        cout << m << "\n";
        for (auto &p : points)
            cout << p.x << " " << p.y << "\n";
        return 0;
    }

    vector<Point> hull;

    // Lower hull
    for (int i = 0; i < m; ++i) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    // Upper hull
    size_t lower_size = hull.size();
    for (int i = m - 2; i >= 0; --i) {
        while (hull.size() > lower_size &&
               cross(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    // 去掉最后一个点（起点重复）
    hull.pop_back();

    // 输出：起点为y最小，若相同取x最小，逆时针
    // 找起点索引
    int start_idx = 0;
    for (int i = 1; i < hull.size(); ++i) {
        if (hull[i].y < hull[start_idx].y ||
            (hull[i].y == hull[start_idx].y && hull[i].x < hull[start_idx].x)) {
            start_idx = i;
        }
    }

    // 旋转使其为起点
    rotate(hull.begin(), hull.begin() + start_idx, hull.end());

    cout << hull.size() << "\n";
    for (auto &p : hull)
        cout << p.x << " " << p.y << "\n";

    return 0;
}
