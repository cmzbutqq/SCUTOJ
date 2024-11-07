#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    int h = -1;
    Node *left;
    Node *right;
    Node *parent;
    Node(string data) : left(nullptr), right(nullptr), parent(nullptr) {
        if (data == "-")
            this->data = -1;
        else
            this->data = stoi(data);
    }
    bool placeholder() { return data == -1; }
    int height() {
        if (h != -1)
            return h;
        if (placeholder())
            return h = 0;
        return h = 1 + max(left->height(), right->height());
    }
    int leaf_count() {
        if (placeholder())
            return 0;
        else if (left->placeholder() && right->placeholder())
            return 1;
        return left->leaf_count() + right->leaf_count();
    }
};

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string node;
    int count = 0;
    ss >> node;
    Node *root = new Node(node);
    Node *curr = root;
    while (ss >> node) {
        // cout << node << endl;
        if (curr->left == nullptr) {
            curr->left = new Node(node);
            curr->left->parent = curr;
            if (node != "-") {
                // cout << "goto left\n";
                curr = curr->left;
                count++;
            }
        } else if (curr->right == nullptr) {
            curr->right = new Node(node);
            curr->right->parent = curr;
            if (node != "-") {
                // cout << "goto right\n";
                curr = curr->right;
                count++;
            }
        } else {
            throw "error";
        }

        if (curr->left != nullptr) {
            while (curr->right != nullptr) {
                if (curr == root)
                    break;
                curr = curr->parent;
            }
        }
    }
    cout << root->height() << " " << root->leaf_count() << endl;
}