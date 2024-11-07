#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void placeholder_fill(int *tree, int N, int at) {
    int left = 2 * at + 1;
    int right = 2 * at + 2;
    if (left < N && tree[left] == -2) {
        tree[left] = -1;
        placeholder_fill(tree, N, left);
    }
    if (right < N && tree[right] == -2) {
        tree[right] = -1;
        placeholder_fill(tree, N, right);
    }
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string node;
    int tree[1023];
    int i = 0;
    for (int j = 0; j < 1023; j++)
        tree[j] = -2; // undefined
    while (ss >> node) {
        if (node == "#") {
            tree[i] = -1; // placeholder
            placeholder_fill(tree, 1023, i);
        } else
            tree[i] = stoi(node);
        while (tree[i] != -2 && i < 1023)
            i++;
    }
    // for (int i = 0; i < 1023; i++) {
    //     cout<<tree[i]<<" ";
    // }
    for (int h = 1; h <= 10; h++) {
        int l = pow(2, h - 1) - 1;
        int r = pow(2, h) - 2;
        bool eol = false;
        if (h % 2) {
            for (int i = l; i <= r; i++) {
                if (tree[i] >= 0) {
                    cout << tree[i] << " ";
                    eol = true;
                }
            }
        } else {
            for (int i = r; i >= l; i--) {
                if (tree[i] >= 0) {
                    cout << tree[i] << " ";
                    eol = true;
                }
            }
        }
        if (eol)
            cout << endl;
    }
}