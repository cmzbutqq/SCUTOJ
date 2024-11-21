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
    bool *visited;
    Graph(int n) : N(n) {
        G = new int *[N];
        visited = new bool[N];
        for (int i = 0; i < N; i++) {
            G[i] = new int[N];
            visited[i] = false;
            for (int j = 0; j < N; j++) {
                G[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v) {
        G[u][v] = 1;
        G[v][u] = 1;
    }
    void dfs(int s) {
        visited[s] = true;
        cout << s << " ";
        for (int i = 0; i < N; i++) {
            if (G[s][i] == 1 && !visited[i]) {
                dfs(i);
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
        g.dfs(S);
    }
}