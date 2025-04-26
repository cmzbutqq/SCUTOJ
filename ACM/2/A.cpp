#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size + 1);
        for (int i = 1; i <= size; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
    
    bool isConnected() {
        int root = find(1);
        for (int i = 2; i < parent.size(); ++i) {
            if (find(i) != root) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    UnionFind uf(n);
    int result = -1;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        uf.unite(u, v);
        if (uf.isConnected()) {
            result = i + 1;
            break;
        }
    }
    
    cout << result << endl;
    return 0;
}
