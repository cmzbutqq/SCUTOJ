#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long result = 0;

    for (int u = 1; u <= n; ++u) {
        vector<int> dist(n + 1, -1);
        vector<int> parent(n + 1, -1);
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        parent[u] = 0;

        unordered_map<int, unordered_map<int, int>> subtree_counts_by_distance;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int neighbor : adj[v]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[v] + 1;
                    parent[neighbor] = v;
                    q.push(neighbor);

                    int d = dist[neighbor];
                    int p =
                        (parent[neighbor] == u) ? neighbor : parent[neighbor];
                    subtree_counts_by_distance[d][p]++;
                }
            }
        }

        for (const auto &[d, subtree_counts] : subtree_counts_by_distance) {
            if (subtree_counts.size() < 3)
                continue;

            long long sum1 = 0, sum2 = 0, sum3 = 0;
            for (const auto &[p, cnt] : subtree_counts) {
                sum1 += cnt;
                sum2 += cnt * cnt;
                sum3 += cnt * cnt * cnt;
            }
            long long total =
                (sum1 * sum1 * sum1 - 3 * sum1 * sum2 + 2 * sum3) / 6;
            result += total;
        }
    }

    cout << result << endl;

    return 0;
}