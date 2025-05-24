/*
题目描述
在遥远的未来，人类已经殖民了多个星系。然而，“星际叛军”在一些偏远星球上建立了秘密基地，威胁着银河联邦的安全。作为联邦最精锐的星际飞行员，你接到了一项关键任务：
“驾驶隐形轰炸机，一次性摧毁尽可能多的叛军基地。”
由于敌方部署了量子干扰场，你的战机只能在进入目标区域后沿直线飞行，无法调整航向。此外，叛军的基地坐标已经通过侦察卫星获取，你需要计算出一条最优航线，使得你的轰炸能覆盖最多的目标。
给定n个叛军基地的坐标（保证无重复），你需要找到一条直线，使得这条直线能经过最多的基地。
输入格式
·第一行一个整数n,表示基地数量。
·接下来n行，每行两个整数xi,yi，表示第i个基地的坐标。
输出格式
·一个整数，表示一条直线能覆盖的最多基地数。
样例数据
输入
5
1 1
2 2
3 3
9 10
10 11
输出
3
备注
解释：直线y=x可以覆盖前三个基地(1,1),(2,2),(3,3)，因此最优解是3.
数据范围
·1≤n≤700
·坐标在[-10^9,10^9]范围内。
使用C++编程，先分析题目，再编写程序。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
};

// 判断三个点是否共线
bool isCollinear(const Point &a, const Point &b, const Point &c) {
    // 使用叉积判断共线：(b-a) × (c-a) = 0
    // (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) = 0
    return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // 特殊情况：只有1个或2个点
    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    int maxCount = 2; // 至少有2个点在一条直线上

    // 枚举所有点对
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 2; // 包含点i和点j

            // 检查其他点是否在通过点i和点j的直线上
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    if (isCollinear(points[i], points[j], points[k])) {
                        count++;
                    }
                }
            }

            maxCount = max(maxCount, count);
        }
    }

    cout << maxCount << endl;
    return 0;
}