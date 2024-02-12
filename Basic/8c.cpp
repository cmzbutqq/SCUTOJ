#include <iostream>
using namespace std;

class Integer
{
protected:
    int n;

public:
    Integer() {}
    int getn() { return n; }
};

class Vector : public Integer
{
protected:
    int *v;

public:
    Vector(int Num) : v(new int[Num]) { n = Num; }
    ~Vector() { delete v; }
    int *getv() { return v; }
    void printv()
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }

    Vector operator+(Vector &v2)
    {
        Vector ansVector(this->n);
        int *p1 = this->getv();
        int *p2 = v2.getv();
        int *p3 = ansVector.getv();
        for (int i = 0; i < n; i++)
        {
            *(p3 + i) = *(p1 + i) + *(p2 + i);
        }
        return ansVector;
    }

    Vector operator-(Vector &v2)
    {
        Vector ansVector(this->n);
        int *p1 = this->getv();
        int *p2 = v2.getv();
        int *p3 = ansVector.getv();
        for (int i = 0; i < n; i++)
        {
            *(p3 + i) = *(p1 + i) - *(p2 + i);
        }
        return ansVector;
    }

    int operator*(Vector &v2)
    {
        int ans = 0;
        int *p1 = this->getv();
        int *p2 = v2.getv();
        for (int i = 0; i < n; i++)
        {
            ans += *(p1 + i) * *(p2 + i);
        }
        return ans;
    }
};

int main()
{
    int length;
    while (cin >> length)
    {
        Vector vector1(length), vector2(length);
        int *p1 = vector1.getv();
        int *p2 = vector2.getv();

        for (int i = 0; i < length; i++)
        {
            cin >> *(p1 + i);
        }
        for (int i = 0; i < length; i++)
        {
            cin >> *(p2 + i);
        }

        (vector1 + vector2).printv();
        (vector1 - vector2).printv();
        cout << (vector1 * vector2) << endl;
    }
}