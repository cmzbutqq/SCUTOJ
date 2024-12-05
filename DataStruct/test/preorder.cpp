#include <iostream>
#include <string>
using namespace std;

string preorder(string inorder, string postorder) {
    if (inorder.empty())
        return "";
    char root = postorder.back();
    int rootIndex = inorder.find(root);
    string leftInorder = inorder.substr(0, rootIndex);
    string rightInorder =
        inorder.substr(rootIndex + 1, inorder.size() - 1 - rootIndex);
    string leftPostorder = postorder.substr(0, rootIndex);
    string rightPostorder =
        postorder.substr(rootIndex, postorder.size() - 1 - rootIndex);
    return root + preorder(leftInorder, leftPostorder) +
           preorder(rightInorder, rightPostorder);
}

int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;
    cout << preorder(inorder, postorder) << endl;
}