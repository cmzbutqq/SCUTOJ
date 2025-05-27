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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point &p) const { return x == p.x && y == p.y; }
};

// 计算叉积 (p1-p0) × (p2-p0)
int cross(const Point &p0, const Point &p1, const Point &p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

// 计算两点间距离的平方
long long dist2(const Point &a, const Point &b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

// 判断点c是否在线段ab上
bool onSegment(const Point &a, const Point &b, const Point &c) {
    // 首先确保三点共线
    if (cross(a, b, c) != 0)
        return false;
    // 然后检查c的坐标是否在a和b之间
    return c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) &&
           c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // 去除重复点
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    points.erase(unique(points.begin(), points.end()), points.end());
    n = points.size();

    // 找到y坐标最小的点，如果有多个，选择x坐标最小的
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[start].y ||
            (points[i].y == points[start].y && points[i].x < points[start].x)) {
            start = i;
        }
    }

    // 将起始点放到第一位
    swap(points[0], points[start]);

    // 按照极角排序其余点
    sort(points.begin() + 1, points.end(), [&](const Point &a, const Point &b) {
        int c = cross(points[0], a, b);
        if (c != 0)
            return c > 0;                                 // 逆时针排序
        return dist2(points[0], a) < dist2(points[0], b); // 距离近的优先
    });

    // Graham扫描算法构建凸包
    vector<Point> hull;
    hull.push_back(points[0]);

    for (int i = 1; i < n; i++) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // 检查是否有点在凸包的边上
    vector<Point> result = hull;

    for (int i = 0; i < n; i++) {
        bool onHull = false;
        for (size_t j = 0; j < hull.size(); j++) {
            if (points[i] == hull[j]) {
                onHull = true;
                break;
            }
        }

        if (!onHull) {
            for (size_t j = 0; j < hull.size(); j++) {
                size_t next = (j + 1) % hull.size();
                if (onSegment(hull[j], hull[next], points[i])) {
                    result.push_back(points[i]);
                    break;
                }
            }
        }
    }

    // 重新排序结果，确保按照题目要求的顺序输出
    // 找到y坐标最小的点
    start = 0;
    for (size_t i = 1; i < result.size(); i++) {
        if (result[i].y < result[start].y ||
            (result[i].y == result[start].y && result[i].x < result[start].x)) {
            start = i;
        }
    }

    // 计算每个点相对于起始点的极角
    vector<pair<double, Point>> anglePoints;
    for (size_t i = 0; i < result.size(); i++) {
        if (i == start)
            continue;
        double angle =
            atan2(result[i].y - result[start].y, result[i].x - result[start].x);
        anglePoints.push_back({angle, result[i]});
    }

    // 按极角排序
    sort(anglePoints.begin(), anglePoints.end());

    // 输出结果
    cout << result.size() << endl;
    cout << result[start].x << " " << result[start].y << endl;
    for (const auto &ap : anglePoints) {
        cout << ap.second.x << " " << ap.second.y << endl;
    }

    return 0;
}