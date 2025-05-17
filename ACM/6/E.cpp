/*
题目描述
唔西·迪西和玛卡·巴卡到迷宫里探险，不了他们两错乱中竟然分散了，迷宫的大小为N×M(2≤N≤300,2≤M≤300).
迷宫里有一些传送装置，可以将人从一点到另一点进行瞬间转移。这些装置可以双向使用。
如果莫个人处在这个装置的起点或者终点，那么就必须使用这个装置，在传送过后不会立刻进行第二次传送，即不会卡在传送装置的起点和终点之间来回传送。
现在唔西·迪西想要和玛卡·巴卡会和，他们俩商量好如果分散了，唔西·迪西将会留在原地，玛卡·巴卡会前去寻找她。
迷宫中的每个元素都由以下项目中的一项组成：
死路，由#表示，这些格子是不可以通过的。
空地，由。表示，可以简单的通过。
传送装置，每一对大写字母A到Z表示。
唔西·迪西的位置，由=表示。
玛卡·巴卡的位置，由@表示
玛卡·巴卡能在一格空地上可能存在的四个相邻的格子移动，花费1个单位时间。从装置的一个结点到另一个结点不花时间。
求玛卡·巴卡找到唔西·迪西的最短时间。
输入格式
第一行：两个用空格隔开的整数N和M.
接下来一共N行：第i行描述了迷宫中的第i行的情况(共有M个字符，每个字符中间没有空格)。
输出格式
一行一个整数，表示起点到出口所需的最短时间。
样例数据
输入
5 6
..#=##
#.W.##
.#####
#.@W##
.####.
输出
3

使用C++编程，先分析题目，再编写程序。
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point():x(0),y(0){}
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> maze(N);
    Point start(-1, -1), end(-1, -1);
    unordered_map<char, vector<Point>> teleport;

    for (int i = 0; i < N; ++i) {
        cin >> maze[i];
        for (int j = 0; j < M; ++j) {
            char c = maze[i][j];
            if (c == '@') {
                start.x = i;
                start.y = j;
            } else if (c == '=') {
                end.x = i;
                end.y = j;
            } else if (c >= 'A' && c <= 'Z') {
                teleport[c].emplace_back(i, j);
            }
        }
    }

    // Preprocess teleporters: for each pair, map each point to the other
    unordered_map<int, unordered_map<int, Point>> teleport_map;
    for (auto &entry : teleport) {
        auto &points = entry.second;
        if (points.size() == 2) {
            teleport_map[points[0].x][points[0].y] = points[1];
            teleport_map[points[1].x][points[1].y] = points[0];
        }
    }

    // BFS
    queue<pair<Point, int>> q;
    q.push({start, 0});
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[start.x][start.y] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        Point pos = current.first;
        int time = current.second;

        if (pos.x == end.x && pos.y == end.y) {
            cout << time << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = pos.x + dx[i];
            int ny = pos.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || maze[nx][ny] == '#' ||
                visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            Point next(nx, ny);

            // Check if the next position is a teleporter
            if (teleport_map.count(nx) && teleport_map[nx].count(ny)) {
                auto &teleport_dest = teleport_map[nx][ny];
                if (!visited[teleport_dest.x][teleport_dest.y]) {
                    visited[teleport_dest.x][teleport_dest.y] = true;
                    q.push({teleport_dest, time + 1});
                }
            } else {
                q.push({next, time + 1});
            }
        }
    }

    cout << "impossible"
         << endl; // In case no path found (though problem says it's possible)
    return 0;
}
