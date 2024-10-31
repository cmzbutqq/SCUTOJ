#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T, M, N;
    cin >> T;
    while (T--) {
        cin >> M >> N;

        vector<string> words(M);
        vector<string> queries(N);
        for (int i = 0; i < M; i++) {
            cin >> words[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> queries[i];
        }

        vector<int> res(N);
        for (int i = 0; i < N; i++) {
            res[i] = 0;
            for (int j = 0; j < M; j++) {
                if (queries[i] == words[j]) {
                    res[i]++;
                }
            }
        }
        for (int i = 0; i < N - 1; i++) {
            cout << res[i] << " ";
        }
        cout << res[N - 1] << endl;
    }
}