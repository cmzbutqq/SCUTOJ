#include <iostream>
#include <string>
using namespace std;
struct Graph {
    int N;
    int *visited;
    int **mat;
    Graph(int n) : N(n) {
        mat = new int *[n];
        visited = new int[n];
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            mat[i] = new int[n];
            for (int j = 0; j < n; j++) {
                mat[i][j] = 0;
            }
        }
    }
    void dfs(int v) {
        visited[v] = 1;
        for (int i = 0; i < N; i++)
            if (mat[v][i] == 1 && visited[i] == 0)
                dfs(i);
    }
    int components() {
        int count = 0;
        for (int i = 0; i < N; i++)
            if (visited[i] == 0) {
                dfs(i);
                count++;
            }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g.mat[i][j];
        }
    }
    cout<< g.components()<<endl;
}
