#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

class Student
{
    int score;
    static int total;
    static int count;

public:
    void scoretotalcount(int s)
    { // 用于设置分数、求总分和累计学生人数
        score = s;
        total += score;
        ++count;
    }
    static int sum()
    { // 用于返回总分
        return total;
    }
    static int average()
    { // 用于求平均值
        return total / count;
    }
    static void staticInit()
    {
        total = 0;
        count = 0;
    }
};
int Student::total = 0;
int Student::count = 0;

int main()
{
    int input[5];
    while (cin >> input[0])
    {
        for (int i = 1; i < 5; ++i)
        {
            cin >> input[i];
        }
        Student::staticInit();
        Student stu[5];
        for (int i = 0; i < 5; ++i)
        {
            stu[i].scoretotalcount(input[i]);
        }
        cout << Student::sum() << ' ' << Student::average() << endl;
    }
    return 0;
}