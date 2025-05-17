/*
题目描述
给定一张包含n个节点和m条边的无向图。图中可能存在自环（节点连接到自身）和重边（多条相同的边）。对于每个节点u，定义其邻近点为u本身以及所有与u直接相连的节点（无需考虑边数，仅判断是否存在边相连）。请计算每个节点的邻近点数量，并按顺序输出。
输入格式
第一行输入两个整数n和m,表示节点数和边数。
接下来m行，每行输入两个整数u和v,表示节点u和v之间有一条边。节点编号为1到n.
输出格式
输出1行n个数，第i个数表示节点i的邻近点数量。
样例数据
输入
3 3
1 2
1 2
2 3
输出
2 3 2
备注
·1≤n≤2*10^5
·0≤m≤10^6
使用C++编程，先分析题目，再编写程序。
*/
#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n + 1);
    for (int i = 1; i < n + 1; ++i)
        adj[i].insert(i);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int u = 1; u <= n; ++u) {
        cout << adj[u].size() << (u == n ? "\n" : " ");
    }

    return 0;
}