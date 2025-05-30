#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

vector<int> parent;
vector<int> rank_;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (rank_[u] < rank_[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
        if (rank_[u] == rank_[v]) {
            rank_[u]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    rank_.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    long long total_weight = 0;
    int edges_used = 0;

    for (const Edge &e : edges) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            total_weight += e.w;
            edges_used++;
            if (edges_used == n - 1) {
                break;
            }
        }
    }

    cout << total_weight << endl;

    return 0;
}