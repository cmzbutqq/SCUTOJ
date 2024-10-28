#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

int main()
{
    auto p = new Node<int>;
    auto p0 = p;
    while (cin >> p->data)
    {
        for (int i = 1; i < 6; ++i)
        {
            p->next = new Node<int>;
            p = p->next;
            cin >> p->data;
        }
        p->next = nullptr;

        p = p0;
        for (int i = 0; i < 6; ++i)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
        p = p0;
    }

    p = p0;
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            p = p->next;
        }
        delete p;
        p = p0;
    }

    return 0;
}