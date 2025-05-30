/*
在一次突发灾害中，政府在若干城市设立了紧急避难所。为了迅速将全体市民转移到最近的避难所，需要计算每个城市到最近避难所的最短疏散距离。
给定一个包含n个城市和m条双向道路的加权图；同时有k个城市已设立为避难所（多个避难所可以在图中任意位置）。现有q位市民分别位于某些城市，需要求出每位市民到最近避难所的最短路径距离。
如果某个市民所在城市无法到达任何避难所，则输出-1.
输入格式
·第一行：两个整数n,m（城市数和道路数），编号均为1到n.
·接下来m行：每行三个整数ui,vi,wi表示城市ui与vi之间有一条双向道路，路长为wi.
·第m+2行：整数k,表示避难所数量。
·第m+3行：k个两两可能相同的整数s1,s2...sk,表示设立避难所的城市编号。
·接着一行整数q,表示要查询的市民数量。
·接下来q行：每行一个整数xj,表示第j位市民所在的城市编号。
输出格式
输出q行，第j行输出市民j到最近避难所的最短距离；若其城市无法连通到任何避难所，则输出-1.
样例数据
输入
7 8
1 2 4
1 3 2
2 4 7
3 5 3
4 5 1
5 6 5
4 7 6
6 7 2
2
4 6
5
1
2
3
7
5
输出
6
7
4
2
1
备注
·1≤n≤10^5
·1≤m≤2×10^5
·1≤wi≤10^4
·1≤k≤n
·1≤q≤10^5
图可能不连通，避难所城市可以重复给出（视同一个避难所）。
使用C++编程，先分析题目，再编写程序。
*/

#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1); // adjacency list: (node, weight)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int k;
    cin >> k;
    vector<int> shelters(k);
    for (int i = 0; i < k; ++i) {
        cin >> shelters[i];
    }

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>>
        pq; // min-heap: (distance, node)

    for (int s : shelters) {
        dist[s] = 0;
        pq.emplace(0, s);
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue; // skip outdated entries
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (dist[x] == INT_MAX) {
            cout << "-1\n";
        } else {
            cout << dist[x] << '\n';
        }
    }

    return 0;
}