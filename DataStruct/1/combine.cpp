#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    ListNode *h1 = new ListNode;
    ListNode *h2 = new ListNode;
    ListNode *p1 = h1, *p2 = h2;
    for (int i = 0; i < n1; i++) {
        ListNode *p = new ListNode;
        cin >> p->val;
        p1 = p1->next = p;
    }
    for (int i = 0; i < n2; i++) {
        ListNode *p = new ListNode;
        cin >> p->val;
        p2 = p2->next = p;
    }

    p1 = h1->next;
    p2 = h2->next;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val <= p2->val) {
            cout << p1->val << " ";
            p1 = p1->next;
        } else {
            cout << p2->val << " ";
            p2 = p2->next;
        }
    }
    while (p1 != nullptr) {
        cout << p1->val << " ";
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        cout << p2->val << " ";
        p2 = p2->next;
    }
    if(n1 == 0 && n2 == 0) {
        cout << "NULL";
    }
}