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
    void operator*() {}

    friend ostream &operator<<(ostream &, const Student &);
};

ostream &operator<<(ostream &output, const Student &in) {
    cout << "学生姓名: " << in.name << "\n学生学号: " << in.id
         << "\n平时作业成绩加权: " << .2 * in.hw
         << "\n期中考试成绩加权: " << .3 * in.midterm
         << "\n期末考试成绩加权: " << .5 * in.final
         << "\n总成绩: " << .2 * in.hw + .3 * in.midterm + .5 * in.final
         << endl;
    return output;
}

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

        // 调用重载的乘法运算符进行加权成绩的计算
        student.operator*();

        cout << "学生信息及成绩单：" << endl;
        cout << student << endl;

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}