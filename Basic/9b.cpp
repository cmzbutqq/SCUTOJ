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
    void out() { cout << name << ' ' << Salary << endl; }
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
        out();
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

class Manager : public Worker
{
protected:
    int jobSalary;

public:
    Manager(string name, int jobSalary)
        : Worker(name), jobSalary(jobSalary)
    {
        setSalary();
        out();
    }
    void setSalary()
    {
        Salary = basicSalary + jobSalary;
        return;
    }
};

class LabWorker : public Worker
{
protected:
    int Workdays;

public:
    LabWorker(string name, int Workdays)
        : Worker(name), Workdays(Workdays)
    {
        setSalary();
        out();
    }
    void setSalary()
    {
        Salary = basicSalary + Workdays * 20;
        return;
    }
};

int main()
{
    string name[3];
    int inN[4];
    while (cin >> name[0] >> inN[0] >> inN[1] >> name[1] >> inN[2] >> name[2] >> inN[3])
    {
        Teacher t1(name[0], inN[0], inN[1]);
        Manager m1(name[1], inN[2]);
        LabWorker l1(name[2], inN[3]);
    }
    return 0;
}