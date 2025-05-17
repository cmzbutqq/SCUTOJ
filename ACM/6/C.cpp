/*
在电商巨头「喵星科技」的物流系统中，有个城市仓库和m条单向运输路线。某些路线因促销活动带有「运费补贴」（表现为负权值），而多次经过这些路线可能导致总运费无限降低。但当运输路径形成负权环时，理论上可通过无限绕行使运费趋近于负无穷一这被称为「无限折扣陷阱」。
现需为物流算法设计核心模块：给定起点和终点，判断最低运费是否为确定值、不可达或存在无限折扣可能。
给定带权有向图(允许重边，无自环)，对从起点s到终点t的最短路径做出如下判断：
1.不可达：输出impossible
2.存在无限折扣陷阱（路径中或可通过绕行负权环使运费无限降低）：输出-INF
3.存在确定最短路：输出具体数值
输入格式
·第一行两个整数n,m,表示仓库数和路线数
·接下来m行，每行三个整数u,v,w,表示从仓库u到v的单向路线运费（可为负）
·最后一行两个整数s,t,表示起点和终点
输出格式
根据上述规则输出一行结果
样例数据
输入
4 5
1 2 10
2 3 -20
3 4 5
3 2 15
4 1 -8
1 4
输出
-INF
备注
·样例，路径1→2→3→2→3→4中绕行负权环2→3→2(总运费20+15=-5)，运费可无限降低
数据范围
·1≤n≤1000
·0≤m≤10^5
·-10^4≤w≤10^4
·保证所有边的u!=v
使用C++编程，先分析题目，再编写程序。
*/
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

const int INF = INT_MAX / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int s, t;
    cin >> s >> t;

    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    // Bellman-Ford algorithm
    for (int i = 1; i <= n - 1; ++i) {
        bool updated = false;
        for (const auto &e : edges) {
            if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    // Check for negative cycles that can affect the path to t
    vector<bool> in_negative_cycle(n + 1, false);
    bool has_affecting_negative_cycle = false;

    // Perform one more relaxation to find nodes that can be updated (in
    // negative cycles)
    for (const auto &e : edges) {
        if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
            in_negative_cycle[e.v] = true;
        }
    }

    // Now check if any node in a negative cycle can reach t
    if (!has_affecting_negative_cycle) {
        // Build reverse graph for BFS
        vector<vector<int>> reverse_adj(n + 1);
        for (const auto &e : edges) {
            reverse_adj[e.v].push_back(e.u);
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        // Start BFS from t to see if it's reachable from any negative cycle
        // node
        q.push(t);
        visited[t] = true;

        while (!q.empty() && !has_affecting_negative_cycle) {
            int u = q.front();
            q.pop();

            if (in_negative_cycle[u]) {
                has_affecting_negative_cycle = true;
                break;
            }

            for (int v : reverse_adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (dist[t] == INF) {
        cout << "impossible" << endl;
    } else if (has_affecting_negative_cycle) {
        cout << "-INF" << endl;
    } else {
        cout << dist[t] << endl;
    }

    return 0;
}