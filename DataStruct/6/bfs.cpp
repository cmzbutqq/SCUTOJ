#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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
    void addEdge(int u, int v) {
        G[u][v] = 1;
        G[v][u] = 1;
    }
    void bfs(int s) {
        bool *visited = new bool[N];
        for (int i = 0; i < N; i++)
            visited[i] = false;

        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for (int v = 0; v < N; v++) {
                if (G[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    int T, N, E, S;
    cin >> T;
    while (T--) {
        cin >> N >> E >> S;
        Graph g(N);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        g.bfs(S);
    }
}