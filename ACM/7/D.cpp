/*
题目描述
给出多次询问，每次询问给出三个二维平面上的点p0,p1,p2,你需要判断三个点的位置关系是以下五种
的哪一种：
(1)p2在p1绕点p0的逆时针方向，输出1.
(2)p2在p1绕点p0的顺时针方向，输出22.
(3)p2在p0延p1的反方向，输出3333.
(4)p1在p0延p2的线段上(不包含线段的端点)，输出4444.
(5)p2在p0延p1的线段上，输出55555.
输入格式
第一行一个整数T表示询问次数。
接下来T行，每行六个整数x0,y0,x1,y1,x2,y2,表示p0,p1,p2三个点的二维坐标。
输出格式
输出共T行，每行表示本次询问的答案。
样例数据
输入
5
0 0 2 0 -1 -1
0 0 2 0 4 0
0 0 2 0 -1 1
0 0 2 0 -2 0
0 0 2 0 0 0
输出

22
4444
1
3333
55555

备注
1≤T≤1000
0≤|x|,ly|≤10^5
使用C++编程，先分析题目，再编写程序。考虑边界情况与溢出
*/
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll x0, y0, x1, y1, x2, y2;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

        // 重合情况统一处理
        if ((x0 == x1 && y0 == y1) || (x0 == x2 && y0 == y2) ||
            (x1 == x2 && y1 == y2)) {
            cout << "55555\n";
            continue;
        }

        ll v1x = x1 - x0, v1y = y1 - y0;
        ll v2x = x2 - x0, v2y = y2 - y0;

        ll cross = v1x * v2y - v1y * v2x;

        if (cross > 0) {
            cout << "1\n";
        } else if (cross < 0) {
            cout << "22\n";
        } else {
            // 共线，判断点积和长度
            ll dot = v1x * v2x + v1y * v2y;
            ll len1sq = v1x * v1x + v1y * v1y;
            ll len2sq = v2x * v2x + v2y * v2y;

            if (dot < 0) {
                cout << "3333\n";
            } else if (len2sq < len1sq) {
                cout << "55555\n";
            } else {
                cout << "4444\n";
            }
        }
    }
    return 0;
}
