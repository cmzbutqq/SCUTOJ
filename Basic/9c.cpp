#include <iostream>
#include <memory>
using namespace std;

class Worker
{
protected:
    const int basicSalary = 2000;
    int Salary;
    string name;

public:
    Worker(string name = "")
        : name(name) {}
    int getS() { return Salary; }
    // void out() { cout << name << ' ' << Salary << endl; }
};

class Teacher : public Worker
{
protected:
    int level; // 1代表教授，2代表副教授，3代表讲师
    int classCount;

public:
    Teacher(string name, int level, int classCount)
        : Worker(name), level(level), classCount(classCount)
    {
        setSalary();
    }
    void setSalary()
    {
        int per;
        switch (level)
        {
        case 1:
            per = 50;
            break;
        case 2:
            per = 30;
            break;
        case 3:
            per = 20;
            break;
        default:
            per = 0;
        }
        Salary = basicSalary + per * classCount;
        return;
    }
};

struct SalaryList
{
    int salary;
    SalaryList *next;
} SL[4];

int main()
{
    string name[4];
    int inL[4], inN[4];
    while (cin >>
           name[0] >> inL[0] >> inN[0] >>
           name[1] >> inL[1] >> inN[1] >>
           name[2] >> inL[2] >> inN[2] >>
           name[3] >> inL[3] >> inN[3])
    {
        unique_ptr<Teacher> ptr[4];
        for (int i = 0; i < 4; i++)
        {
            ptr[i] = make_unique<Teacher>(name[i], inL[i], inN[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            SL[i].salary = ptr[i]->getS();
            SL[i].next = i < 4 ? &SL[i + 1] : nullptr;
        }
        auto p = &SL[0];
        int thisS = p->salary;
        int sum = 0, max = thisS, min = thisS;
        for (int i = 0; i < 4; i++)
        {
            thisS = p->salary;

            sum += thisS;
            if (thisS > max)
                max = thisS;
            if (thisS < min)
                min = thisS;

            p = p->next;
        }
        cout << sum << endl;
        cout << sum / 4 << endl;
        cout << max << endl;
        cout << min << endl;
    }
    return 0;
}