/*
题目描述
对于一个n个顶点的凸多边形，它的任何三条对角线都不会交于一点。请求出图形中对角线交点的个数。
输入格式
输入只有一行一个整数n,代表边数。
输出格式
输出一行一个整数代表答案。
样例数据
输入
6
输出
15
备注
数据范围
保证3≤n≤10^5。
使用C++编程，先分析题目，再编写程序。考虑边界情况与溢出
*/
#include <iostream>

using namespace std;

unsigned long long calculateIntersections(int n) {
    if (n < 4)
        return 0;
    unsigned long long res = 1;
    // Calculate n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4
    res *= n;
    res *= (n - 1);
    res /= 2;
    res *= (n - 2);
    res /= 3;
    res *= (n - 3);
    res /= 4;
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << calculateIntersections(n) << endl;
    return 0;
}