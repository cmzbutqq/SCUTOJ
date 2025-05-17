#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {

    int N, M;
    cin >> N >> M;

    vector<string> maze(N);
    pair<int, int> start, end;
    unordered_map<char, vector<pair<int, int>>> portal;

    for (int i = 0; i < N; ++i) {
        cin >> maze[i];
        for (int j = 0; j < M; ++j) {
            if (maze[i][j] == '@') {
                start = {i, j};
            } else if (maze[i][j] == '=') {
                end = {i, j};
            } else if (isupper(maze[i][j])) {
                portal[maze[i][j]].emplace_back(i, j);
            }
        }
    }

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == end.first && y == end.second) {
            cout << dist[x][y] << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || maze[nx][ny] == '#') {
                continue;
            }

            if (isupper(maze[nx][ny])) {
                char c = maze[nx][ny];
                for (auto &pos : portal[c]) {
                    if (pos.first != nx || pos.second != ny) {
                        nx = pos.first;
                        ny = pos.second;
                        break;
                    }
                }
            }

            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}