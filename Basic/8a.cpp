#include <iostream>
#include <string>
using namespace std;

class Worker
{
protected:
    int number;
    string name;
    int basicSalary;
    double salary;

public:
    Worker() { basicSalary = 2000; }
    virtual void pay() { salary = basicSalary; }
    void input(int num, string nm)
    {
        number = num;
        name = nm;
    }
    void print()
    {
        pay();
        cout << name << " " << number << " " << salary << endl;
    }
} emp;

class Teacher : public Worker
{
protected:
    int sales;
    double commrate;

public:
    Teacher() { commrate = 5.0 / 1000.0; }
    virtual void pay() override { salary = basicSalary + sales * commrate; }
    void input(int num, string nm, int sls)
    {
        number = num;
        name = nm;
        sales = sls;
    }
} slm;

class Manager : public Teacher
{
    int jobSalary;

public:
    Manager() { jobSalary = 3000; }
    virtual void pay() override { salary = basicSalary + jobSalary + sales * commrate; }
} mgr;

int main()
{
    int inNum[3];
    string inNm[3];
    int inSales[2];
    while (cin >> inNum[0] >> inNm[0] >> inNum[1] >> inNm[1] >> inSales[0] >> inNum[2] >> inNm[2] >> inSales[1])
    {
        emp.input(inNum[0], inNm[0]);
        slm.input(inNum[1], inNm[1], inSales[0]);
        mgr.input(inNum[2], inNm[2], inSales[1]);

        emp.print();
        slm.print();
        mgr.print();
    }
    return 0;
}