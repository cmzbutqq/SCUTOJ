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
    int *parent;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;

    Graph(int n) : N(n) {
        parent = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = -1;
        }
        pq = priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                            greater<tuple<int, int, int>>>();
    }
    void addEdge(int u, int v, int w) { pq.push(make_tuple(w, u, v)); }
    int find(int x) {
        if (parent[x] < 0)
            return x;
        return parent[x] = find(parent[x]);
    }
    int kruskal() { // MST
        int res = 0;
        while (!pq.empty()) {
            auto [w, u, v] = pq.top();
            pq.pop();
            int up = find(u);
            int vp= find(v);
            if (up!= vp) {
                res += w;
                if (parent[up] < parent[vp]) {
                    parent[up] += parent[vp];
                    parent[vp] = up;
                }else{
                    parent[vp] += parent[up];
                    parent[up] = vp;
                }
            }
        }
        return res;
    }
};

int main() {
    int N, E;
    cin >> N >> E;
    Graph g(N);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w);
    }
    cout << g.kruskal() << endl;
}