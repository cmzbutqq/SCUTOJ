#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long result = 0;

    // 遍历每个节点，作为“中心”节点
    for (int center = 1; center <= n; ++center) {
        int degree = (int)adj[center].size();
        if (degree < 3)
            continue;

        vector<int> depth(n + 1, -1);
        vector<int> branchId(n + 1, -1);
        vector<int> directBranch(n + 1, -1);

        // 标记中心节点相邻节点的branch编号
        for (int i = 0; i < degree; ++i) {
            directBranch[adj[center][i]] = i;
        }

        // BFS计算深度和branchId
        queue<int> q;
        depth[center] = 0;
        branchId[center] = -1;
        q.push(center);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto nxt : adj[curr]) {
                if (depth[nxt] == -1) {
                    depth[nxt] = depth[curr] + 1;
                    branchId[nxt] =
                        (curr == center) ? directBranch[nxt] : branchId[curr];
                    q.push(nxt);
                }
            }
        }

        // 按branchId分组节点
        vector<vector<int>> groups(degree);
        for (int node = 1; node <= n; ++node) {
            if (node == center)
                continue;
            groups[branchId[node]].push_back(node);
        }

        vector<long long> countOne(n + 1, 0), countTwo(n + 1, 0),
            countThree(n + 1, 0);
        vector<int> depthCounter(n + 1, 0);

        for (int i = 0; i < degree; ++i) {
            if (groups[i].empty())
                continue;

            vector<int> depthsSeen;
            for (int node : groups[i]) {
                int d = depth[node];
                if (depthCounter[d] == 0)
                    depthsSeen.push_back(d);
                depthCounter[d]++;
            }

            for (int d : depthsSeen) {
                long long c = depthCounter[d];
                countThree[d] += countTwo[d] * c;
                countTwo[d] += countOne[d] * c;
                countOne[d] += c;
                depthCounter[d] = 0;
            }
        }

        for (int d = 1; d <= n; ++d) {
            result += countThree[d];
        }
    }

    cout << result << "\n";
    return 0;
}
