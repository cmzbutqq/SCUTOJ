#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    char data;
    int h = -1;
    Node *left;
    Node *right;
    Node *parent;
    Node(char data) : data(data), left(nullptr), right(nullptr), parent(nullptr){}
    bool leaf() { return data >= 'A' && data <= 'Z'; }
    int height() {
        if (h != -1)
            return h;
        if (leaf())
            return h = 0;
        return h = 1 + max(left->height(), right->height());
    }
    bool balanced() {
        if (leaf())
            return true;
        if (abs(left->height() - right->height()) <= 1 && left->balanced() &&
            right->balanced())
            return true;
        return false;
    }
};
Node *load(string tree) {// tree size>2
    Node *root = new Node(tree[0]);
    auto curr = root;//curr cannot be leaf, and always have empty slot
    for(unsigned i = 1; i < tree.size(); i ++) {
        Node *node= new Node(tree[i]);

        node->parent = curr;
        if (curr->left == nullptr)
            curr->left = node;
        else
            curr->right = node;
        if (node->leaf()) {
            while(curr ->right != nullptr&& curr!= root) {
                curr = curr->parent;
            }
            
        }else{
            curr = node;
        }

    }
    return root;

}

bool balanced(string tree) {
    if (tree.size() <= 2)
        return true;
    Node *root = load(tree);
    return root->balanced();
}

int main() {
    int T;
    string tree;
    cin >> T;
    while (T--) {
        cin >> tree;
        cout << (balanced(tree) ? "B" : "N") << endl;
    }
}