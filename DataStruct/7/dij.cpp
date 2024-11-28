#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

struct Graph {
    int N;
    int **G;

    Graph(int n) : N(n) {
        G = new int *[N];
        for (int i = 0; i < N; i++) {
            G[i] = new int[N];
            for (int j = 0; j < N; j++) {
                G[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v, int w) {
        w = G[u][v] != 0 ? min(w, G[u][v]) : w;
        G[u][v] = w;
        G[v][u] = w;
    }
    int dijstra(int s, int e) {
        vector<int> dist(N, INT_MAX);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (int v = 0; v < N; v++) {
                if (G[u][v] && dist[u] + G[u][v] < dist[v]) {
                    dist[v] = dist[u] + G[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[e];
    }
};

int main() {
    int N, C, S, T;
    cin >> N >> C >> S >> T;
    Graph g(N);
    for (int i = 0; i < C; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w);
    }
    cout << g.dijstra(S - 1, T - 1) << endl;
}