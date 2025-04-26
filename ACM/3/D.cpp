/*
题目描述
给定n个目标数字和m个禁止数字。初始数字为1，每次操作可将当前数字的二进制末尾添加0或1生成新数字。过程中的所有数字（包括初始数字和中间步骤）均不能为禁止数字。求能合法到达的目标数字数量。
输入格式
·第一行两个整数n和m(1≤n,m≤10^5)
·第二行n个整数，表示目标数字。
·第三行m个整数，表示禁止数字。
·保证1≤目标数字，禁止数字≤10^9，且所有目标数字两两互不相同
输出格式
输出一个整数，表示能到达的目标数字数量。
样例数据
输入
3 2
5 7 2
3 4
输出
2
备注
·1->2->5
·1->3->7
·1->2
·只有7无法到达
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> tars(n);
    for (int i = 0; i < n; i++) {
        cin >> tars[i];
    }

    unordered_set<int> banned;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        banned.insert(num);
    }

    int reachable = 0;

    for (int target : tars) {
        bool able = true;
        int current = target;

        while (current != 1) {
            if (banned.count(current)) {
                able = false;
                break;
            }
            current >>= 1; 
        }

        if (able && current == 1) {
            reachable++;
        }
    }

    cout << reachable << endl;

    return 0;
}
