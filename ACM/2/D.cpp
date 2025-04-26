#include <iostream>
#include <vector>
using namespace std;

struct SegmentTreeNode {
    int left, right;
    int count; // Number of lights turned on
    bool lazy; // Lazy tag for flip operation
};

class SegmentTree {
  private:
    vector<SegmentTreeNode> tree;

    void build(int node, int left, int right) {
        tree[node].left = left;
        tree[node].right = right;
        tree[node].count = 0;
        tree[node].lazy = false;
        if (left == right) {
            return;
        }
        int mid = (left + right) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
    }

    void pushDown(int node) {
        if (tree[node].lazy) {
            tree[node * 2].lazy = !tree[node * 2].lazy;
            tree[node * 2].count =
                (tree[node * 2].right - tree[node * 2].left + 1) -
                tree[node * 2].count;
            tree[node * 2 + 1].lazy = !tree[node * 2 + 1].lazy;
            tree[node * 2 + 1].count =
                (tree[node * 2 + 1].right - tree[node * 2 + 1].left + 1) -
                tree[node * 2 + 1].count;
            tree[node].lazy = false;
        }
    }

    void flipRange(int node, int left, int right) {
        if (tree[node].left > right || tree[node].right < left) {
            return;
        }
        if (left <= tree[node].left && tree[node].right <= right) {
            tree[node].count =
                (tree[node].right - tree[node].left + 1) - tree[node].count;
            tree[node].lazy = !tree[node].lazy;
            return;
        }
        pushDown(node);
        flipRange(node * 2, left, right);
        flipRange(node * 2 + 1, left, right);
        tree[node].count = tree[node * 2].count + tree[node * 2 + 1].count;
    }

    int queryRange(int node, int left, int right) {
        if (tree[node].left > right || tree[node].right < left) {
            return 0;
        }
        if (left <= tree[node].left && tree[node].right <= right) {
            return tree[node].count;
        }
        pushDown(node);
        return queryRange(node * 2, left, right) +
               queryRange(node * 2 + 1, left, right);
    }

  public:
    SegmentTree(int n) {
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void flip(int left, int right) { flipRange(1, left, right); }

    int query(int left, int right) { return queryRange(1, left, right); }
};

int main() {

    int n, m;
    cin >> n >> m;
    SegmentTree st(n);

    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            st.flip(a, b);
        } else {
            cout << st.query(a, b) << '\n';
        }
    }

    return 0;
}
