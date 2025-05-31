#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double t) const { return Point(x * t, y * t); }
};

// 计算两点之间的欧几里得距离
double distance(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// 计算能同时经过两点的半径为R的圆的圆心
vector<Point> getCircleCenters(const Point &a, const Point &b, double R) {
    vector<Point> centers;
    double d = distance(a, b);

    // 如果两点距离大于2R，无法用半径R的圆同时覆盖
    if (d > 2 * R + 1e-9) {
        return centers;
    }

    // 如果两点重合或距离为0
    if (d < 1e-9) {
        // 可以以任意一点为圆心，但我们只需要一个代表
        centers.push_back(a);
        return centers;
    }

    // 两点的中点
    Point mid = Point((a.x + b.x) / 2, (a.y + b.y) / 2);

    // 如果两点距离正好等于2R，圆心就是中点
    if (abs(d - 2 * R) < 1e-9) {
        centers.push_back(mid);
        return centers;
    }

    // 计算从中点到圆心的距离
    double h = sqrt(R * R - (d / 2) * (d / 2));

    // 垂直于ab方向的单位向量
    Point ab = b - a;
    Point perp = Point(-ab.y, ab.x);
    double perpLen = sqrt(perp.x * perp.x + perp.y * perp.y);
    perp = perp * (h / perpLen);

    // 两个可能的圆心
    centers.push_back(mid + perp);
    centers.push_back(mid - perp);

    return centers;
}

// 计算指定圆心能覆盖多少个点
int countPointsInCircle(const vector<Point> &points, const Point &center,
                        double R) {
    int count = 0;
    for (const Point &p : points) {
        if (distance(p, center) <= R + 1e-9) {
            count++;
        }
    }
    return count;
}

int solve(int n, double R, vector<Point> &points) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int maxPoints = 1;
    vector<Point> candidates;

    // 枚举所有点对，找到所有可能的圆心
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<Point> centers = getCircleCenters(points[i], points[j], R);
            for (const Point &center : centers) {
                candidates.push_back(center);
            }
        }
    }

    // 也考虑以每个点为圆心的情况（虽然通常不是最优的，但要保证完整性）
    for (int i = 0; i < n; i++) {
        candidates.push_back(points[i]);
    }

    // 对每个候选圆心，计算能覆盖的点数
    for (const Point &center : candidates) {
        int count = countPointsInCircle(points, center, R);
        maxPoints = max(maxPoints, count);
    }

    // 特殊情况：检查是否所有点都在一个半径为R的圆内
    // 这种情况下，圆心可能不在我们枚举的候选点中
    // 但由于我们枚举了所有点对，理论上已经覆盖了所有情况

    return maxPoints;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, R;
    cin >> n >> R;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int result = solve(n, R, points);
    cout << result << endl;

    return 0;
}