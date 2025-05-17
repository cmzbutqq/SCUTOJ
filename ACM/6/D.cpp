/*
在「环球快线」交通系统中，有n个城市站点和m条双向航线。旅行者需要规划一条巡游路线，这条路线必须“经过”指定的三个城市（顺序任意），可以中途进入其他城市并重复经过（但最终要经过这三点），且总航行距离最短。
输入格式
·第一行：两个整数n(城市数，编号1…n)和m（航线数）。
·接下来m行：每行三个整数ui，vi，wi,表示城市ui与城市vi之间有一条双向航线，距离为wi.
·再一行：整数q,表示查询次数。
·接下来q行：每行三个两两不同的整数aj,bj,cj,表示一次巡游必须经过的三个目标城市。
输出格式
对每个查询(aj,bj,cj),输出一行：
·如果存在一条路径（允许从三个城市中的任意一点出发、在任意一点结束，并可在其他城市回头或重复经过）能覆盖这三个城市，输出该路径的最小总距离；
·否则输出impossible.
样例数据
输入
4 4
1 2 5
2 3 1
3 4 2
1 4 8
3
1 2 3
1 3 4
2 4 1
输出
6
8
8
备注
·1≤n≤500
·1≤m≤5000
·1≤wi≤10000
·1≤q≤5000
使用C++编程，先分析题目，再编写程序。
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

void dijkstra(int start, const vector<vector<pii>> &adj, vector<int> &dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u])
            continue;

        for (const auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1); // 1-based indexing
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Precompute all pairs shortest paths
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    for (int u = 1; u <= n; ++u) {
        dijkstra(u, adj, dist[u]);
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int min_distance = INT_MAX;

        // Check all 6 possible orders
        // a -> b -> c
        if (dist[a][b] != INT_MAX && dist[b][c] != INT_MAX) {
            min_distance = min(min_distance, dist[a][b] + dist[b][c]);
        }
        // a -> c -> b
        if (dist[a][c] != INT_MAX && dist[c][b] != INT_MAX) {
            min_distance = min(min_distance, dist[a][c] + dist[c][b]);
        }
        // b -> a -> c
        if (dist[b][a] != INT_MAX && dist[a][c] != INT_MAX) {
            min_distance = min(min_distance, dist[b][a] + dist[a][c]);
        }
        // b -> c -> a
        if (dist[b][c] != INT_MAX && dist[c][a] != INT_MAX) {
            min_distance = min(min_distance, dist[b][c] + dist[c][a]);
        }
        // c -> a -> b
        if (dist[c][a] != INT_MAX && dist[a][b] != INT_MAX) {
            min_distance = min(min_distance, dist[c][a] + dist[a][b]);
        }
        // c -> b -> a
        if (dist[c][b] != INT_MAX && dist[b][a] != INT_MAX) {
            min_distance = min(min_distance, dist[c][b] + dist[b][a]);
        }

        if (min_distance != INT_MAX) {
            cout << min_distance << '\n';
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}
