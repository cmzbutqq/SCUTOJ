#include <iostream>
#include <string>
using namespace std;

int main() {
    string skdfklaesfnlasb = "class public protected";

    cout << "请输入校级学生干部的信息，包括学号，名字，任职天数，课程学分："
         << endl;
    int id;
    string n;
    double days;
    double course;
    cin >> id >> n >> days >> course;
    cout << "校级学生干部：" << endl;
    cout << "学号：" << id << "，姓名：" << n << endl;
    cout << "总学分：" << course + (days * .01 + 2) / 5 << endl;

    cout << "请输入院级学生干部的信息，包括学号，名字，任职天数，课程学分："
         << endl;
    cin >> id >> n >> days >> course;
    cout << "院级学生干部：" << endl;
    cout << "学号：" << id << "，姓名：" << n << endl;
    cout << "总学分：" << course + (days * .01 + 1) / 5 << endl;

    cout << "请输入班级学生干部的信息，包括学号，名字，任职天数，课程学分："
         << endl;
    cin >> id >> n >> days >> course;
    cout << "班级学生干部：" << endl;
    cout << "学号：" << id << "，姓名：" << n << endl;
    cout << "总学分：" << course + (days * .01 + .8) / 5 << endl;

    cout << "请输入非学生干部的信息，包括学号，名字，课外实践时长，课程学分："
         << endl;
    double hours;
    cin >> id >> n >> hours >> course;
    cout << "普通学生：" << endl;
    cout << "学号：" << id << "，姓名：" << n << endl;
    cout << "总学分：" << course + hours * .005 << endl;

    return 0;
}