#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    auto is_leaf = [](char c) -> bool { return c >= 'A' && c <= 'Z'; };
    auto left = [](int i) -> int { return 2 * i + 1; };
    auto right = [](int i) -> int { return 2 * i + 2; };
    auto parent = [](int i) -> int { return (i - 1) / 2; };
    int t;
    cin >> t;
    while (t--) {
        string preorder;
        cin >> preorder;
        int n = preorder.size(), curr = 0, N = 10000;

        int *tree = new int[N];
        for (int i = 0; i < N; i++)
            tree[i] = -1;
        tree[0] = preorder[0];

        for (int i = 1; i < n; i++) {

            // string out = "";
            // for (int i = 0; i < N; i++) {
            //     if (tree[i] != -1)
            //         out += (char)tree[i];
            // }
            // cout << out << '\n';

            if (is_leaf(preorder[i])) {
                while (tree[left(curr)] != -1 && tree[right(curr)] != -1) {
                    curr = parent(curr);
                }
                if ((tree[left(curr)] == -1)) {
                    tree[left(curr)] = preorder[i];
                } else if ((tree[right(curr)] == -1)) {
                    tree[right(curr)] = preorder[i];
                }
            } else {
                while (tree[left(curr)] != -1 && tree[right(curr)] != -1) {
                    curr = parent(curr);
                }
                if (tree[left(curr)] == -1) {
                    tree[curr = left(curr)] = preorder[i];
                } else {
                    tree[curr = right(curr)] = preorder[i];
                }
            }
        }
        string out = "";
        for (int i = 0; i < N; i++) {
            if (tree[i] != -1)
                out += (char)tree[i];
        }
        cout << out << '\n';
    }
}