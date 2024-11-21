#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node {
    int data;
    node *next;
    node(int d) : data(d), next(nullptr) {}
};
int main() { 
    int in; 
    cin >> in;

    node *head = new node(in);
    node *curr = head;
    node *max= head;
    node *prev_max = head;

    while (cin >> in) {
        curr->next = new node(in);
        if (in > max->data) {
            max = curr->next;
            prev_max = curr;
        }
        curr = curr->next;
    }
    prev_max->next = max->next;
    if (max == head) 
        head = head->next;
    max->next = nullptr;
    curr->next = max;
    curr= head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    }