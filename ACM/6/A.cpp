/*
题目描述
某大学的校园由n 个建筑物和m 条长度相同的双向走廊连接。为优化导航服务，需统计从 1号主楼出发，到其他每个建筑物的最短路线数量。若存在多条最短路线，需将所有可能纳入统计。


输入格式
第 1 行：n m （建筑物编号 1~n）
后续 m 行：u v （表示建筑物 u 与 v 间有一条走廊，长度视为 1 单位）

输出格式
输出一行，包含 n 个整数，第 i 个整数表示从 1 号到 i 号建筑物的最短路线总数（mod 10^9 +7）。


样例数据
输入

5 6
1 2
1 3
2 4
3 4
4 5
4 5
输出

1 1 1 2 4

备注
1 ≤ n ≤ 1e5
0 ≤ m ≤ 5e5
可能存在重复走廊（如两条 u-v 走廊视为独立路线）
使用C++编程，先分析题目，再编写程序。
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // 邻接表（节点编号从1开始）

    // 构建图
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 无向图
    }

    vector<int> dist(n + 1, -1); // 最短距离
    vector<int> count(n + 1, 0); // 路径数量
    queue<int> q;

    dist[1] = 0;
    count[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                count[v] = count[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                count[v] = (count[v] + count[u]) % MOD;
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        cout << count[i];
        if (i < n)
            cout << " ";
    }
    cout << endl;

    return 0;
}
