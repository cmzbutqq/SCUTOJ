#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Vector
{
    int len;
    unique_ptr<vector<int>> ptr;

public:
    Vector(int l = 0)
    {
        len = l;
        ptr = make_unique<vector<int>>(len);
    }
    void input()
    {
        for (auto it = ptr->begin(); it != ptr->end(); it++)
        {
            cin >> *it;
        }
        return;
    }
    void output()
    {
        for (auto it = ptr->begin(); it != ptr->end() - 1; it++)
            cout << *it << " ";
        cout << *(ptr->end() - 1) << endl;
        return;
    }

    Vector operator+(const Vector &v)
    {
        Vector ans(this->len);
        for (int i = 0; i < this->len; i++)
            ans.ptr->at(i) = this->ptr->at(i) + v.ptr->at(i);
        return ans;
    }
    Vector operator-(const Vector &v)
    {
        Vector ans(this->len);
        for (int i = 0; i < this->len; i++)
            ans.ptr->at(i) = this->ptr->at(i) - v.ptr->at(i);
        return ans;
    }
    int operator*(const Vector &v)
    {
        int ans = 0;
        for (int i = 0; i < this->len; i++)
            ans += this->ptr->at(i) * v.ptr->at(i);
        return ans;
    }
};
void calc(char op, Vector &v1, Vector &v2)
{
    switch (op)
    {
    case '+':
        (v1 + v2).output();
        break;
    case '-':
        (v1 - v2).output();
        break;
    case '*':
        cout << v1 * v2 << endl;
        break;
    default:
        return;
    }
}
int main()
{
    char op;
    int len;
    while (cin >> op >> len)
    {
        auto pv1 = make_unique<Vector>(len);
        auto pv2 = make_unique<Vector>(len);
        pv1->input();
        pv2->input();
        calc(op, *pv1, *pv2);
    }
    return 0;
}