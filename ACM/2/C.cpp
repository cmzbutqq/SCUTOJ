#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    long long x, y, z;
};

bool isConnected(const Point &a, const Point &b, long long r) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;
    long long distSquared = dx * dx + dy * dy + dz * dz;
    return distSquared <= 4 * r * r;
}

bool canReachTop(int n, long long h, long long r, const vector<Point> &holes) {
    vector<bool> visited(n, false);
    queue<int> q;

    // Find all holes connected to the bottom surface (z <= r)
    for (int i = 0; i < n; ++i) {
        if (holes[i].z <= r) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Check if current hole is connected to the top surface (z >= h - r)
        if (holes[current].z >= h - r) {
            return true;
        }

        // Explore all connected holes
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && isConnected(holes[current], holes[i], r)) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long h, r;
        cin >> n >> h >> r;
        vector<Point> holes(n);
        for (int i = 0; i < n; ++i) {
            cin >> holes[i].x >> holes[i].y >> holes[i].z;
        }

        if (canReachTop(n, h, r, holes)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
