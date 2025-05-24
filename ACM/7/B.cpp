/*
题目描述
给定平面上n个点，找出其中的一对点的距离，使得在这n个点的所有点对中，该距离为所有点对中最小的。
输入格式
第一行一个整数n,表示点的个数。
接下来n行，每行两个整数x,y,表示一个点的行坐标和列坐标。
输出格式
仅一行，一个整数，表示最短距离的平方
样例数据
输入
3
1 1
1 2
2 2
输出
备注
保证1≤n≤10^4,0≤x,y≤10^9。
使用C++编程，先分析题目，再编写程序。
*/
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

bool compareX(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool compareY(const Point &a, const Point &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

ll distanceSquared(const Point &a, const Point &b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

ll bruteForce(const vector<Point> &points, int left, int right) {
    ll minDist = LLONG_MAX;
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            ll dist = distanceSquared(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

ll closestUtil(vector<Point> &points, int left, int right) {
    if (right - left + 1 <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = (left + right) / 2;
    Point midPoint = points[mid];

    ll dl = closestUtil(points, left, mid);
    ll dr = closestUtil(points, mid + 1, right);
    ll d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        ll dx = points[i].x - midPoint.x;
        if (dx * dx < d) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    ll minStrip = d;
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1;
             j < strip.size() &&
             (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < minStrip;
             ++j) {
            ll dist = distanceSquared(strip[i], strip[j]);
            if (dist < minStrip) {
                minStrip = dist;
            }
        }
    }

    return min(d, minStrip);
}

ll closestPair(vector<Point> &points) {
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    cout << closestPair(points) << endl;
    return 0;
}