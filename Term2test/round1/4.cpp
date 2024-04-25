#include <iostream>
#include <string>
using namespace std;

class Student {
  private:
    int id;
    string name;
    double hw;
    double midterm;
    double final;

  public:
    Student() {}
    Student(int id, string name, double hw, double midterm, double final)
        : id(id), name(name), hw(hw), midterm(midterm), final(final) {}
    void couscore() {
        cout << "总成绩: " << .2 * hw + .3 * midterm + .5 * final << endl;
    }
    void disp() {
        cout << "学生姓名: " << name << endl;
        cout << "学生学号: " << id << endl;
        cout << "平时作业成绩: " << hw << endl;
        cout << "期中考试成绩: " << midterm << endl;
        cout << "期末考试成绩: " << final << "\n\n";
    }
};

int main() {
    int id;
    string name;
    double hw, midterm, final;
    char continue_input = 'y'; // 控制是否继续输入的标志

    while (continue_input == 'y') {
        cout << "请输入学生学号: ";
        cin >> id;
        cout << "请输入学生姓名: ";
        cin >> name;
        cout << "请输入平时作业成绩: ";
        cin >> hw;
        cout << "请输入期中考试成绩: ";
        cin >> midterm;
        cout << "请输入期末考试成绩: ";
        cin >> final;

        Student student(id, name, hw, midterm, final);
        student.couscore();
        student.disp();

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}