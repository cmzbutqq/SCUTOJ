#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    void insert(int x) {
        if (x < data) {
            if (left == nullptr)
                left = new Node(x);
            else
                left->insert(x);
        } else {
            if (right == nullptr)
                right = new Node(x);
            else
                right->insert(x);
        }
    }
    int getHeight() {
        if (left == nullptr && right == nullptr)
            return 1;
        if (left == nullptr)
            return right->getHeight() + 1;
        if (right == nullptr)
            return left->getHeight() + 1;
        return max(left->getHeight(), right->getHeight()) + 1;
    }
};

int main() {
    int T, t;
    cin >> T;
    string s;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        stringstream ss(s);
        ss >> t;
        Node *root = new Node(t);
        while (ss >> t)
            root->insert(t);
        cout << root->getHeight() << endl;
    }
    return 0;
}