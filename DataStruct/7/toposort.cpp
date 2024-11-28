#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Graph {
    int N;
    vector<int> *G; // adjacency list
    int *ind;       // indegree

    Graph(int n) : N(n) {
        ind = new int[N];
        G = new vector<int>[N];
        for (int i = 0; i < N; i++)
            ind[i] = 0;
    }
    void addEdge(int u, int v) {
        G[u].push_back(v);
        ind[v]++;
    }
    bool toposort() { // return true if there is a topological sort
        queue<int> q;
        for (int i = 0; i < N; i++)
            if (ind[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }
        return cnt == N;
    }
};

int main() {
    int T, N, C;
    cin >> T;
    while (T--) {
        cin >> N >> C;
        Graph g(N);
        for (int i = 0; i < C; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u - 1, v - 1);
        }
        if (g.toposort())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}