#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 600;    // dx and dy range: [-300, 300] -> [0, 600]
const int OFFSET = 300; // offset to make indices non-negative

vector<vector<int>> dist(MAX + 1, vector<int>(MAX + 1, INT_MAX));

// Precompute the minimum steps from (0, 0) to all (dx, dy) within |dx|, |dy| <=
// 300
void precompute() {
    queue<pair<int, int>> q;
    dist[OFFSET][OFFSET] = 0; // (0, 0) maps to (300, 300)
    q.push({OFFSET, OFFSET});

    // All possible moves of the horse
    const int moves[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                             {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto &move : moves) {
            int nx = x + move[0];
            int ny = y + move[1];

            if (nx >= 0 && nx <= MAX && ny >= 0 && ny <= MAX &&
                dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T;
    cin >> T;

    while (T--) {
        int x, y, s, t;
        cin >> x >> y >> s >> t;

        int dx = s - x;
        int dy = t - y;

        if (dx == 0 && dy == 0) {
            cout << "0\n";
        } else {
            // Map dx and dy to non-negative indices
            int nx = dx + OFFSET;
            int ny = dy + OFFSET;

            cout << dist[nx][ny] << '\n';
        }
    }

    return 0;
}
