/*
题目描述
在神秘的符文大陆上，法师们正在筹备一场古老的「元素共鸣」仪式。符文石上刻有1至n的古老符文，但当两颗符文存在「禁忌之链」（即某一符文的编号是另一符文的x倍）时，会引发元素乱流摧毁祭坛。求法师们最多能选用多少符文石，使仪式安全进行。
给定符文的最大编号n
和禁忌倍数，计算在不触发禁忌之链的前提下，最多可激活的符文数量。 输入格式
两个正整数n和x(1≤x≤n≤10^9)
输出格式
一个整数，表示安全激活的最大符文数
样例数据
输入
10 2
输出
6
备注
可以选择1,3,5,7,8,9使得数量最多
思路：每个数都能表示成a=b*x^v,其中b不是x的倍数,v>=0
根据b的值给这些数分组，每个组中v为偶数的通过，奇数的排除
当b>n/x且不是x的倍数时，可以直接通过
你需要尽量优化时间和空间
C++回答
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ll n, x;
    cin >> n >> x;

    if (x == 1) {
        cout << n << endl;
        return 0;
    }

    ll ret = 0;
    ll v = 0;
    ll x_v = 1;

    while (true) {
        ll r = n / x_v;
        ll next_xv = x_v * x;
        ll l = (n / next_xv) + 1;

        if (l <= r) {
            ll total = r - l + 1;
            ll rb = r / x;
            ll lb = (l - 1) / x;
            ll multible = rb - lb;
            ll unmultible = total - multible;
            ret += unmultible * ((v + 2) / 2);
        }

        if (x_v > n / x) {
            break;
        }

        x_v *= x;
        v++;
    }

    cout << ret << endl;
    return 0;
}