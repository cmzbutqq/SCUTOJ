#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Student {
    int score;
    static int total;
    static int count;
  public:
    void scoretotalcount(int s) {
        score = s;
        total += score;
        ++count;
    }
    static int sum() { return total; }
    static int average() { return total / count; }
    static void init() {
        total = 0;
        count = 0;
    }
};
int Student::total = 0;
int Student::count = 0;
int main() {
    int input[5];
    while (cin >> input[0]) {
        Student::init();
        for (int i = 1; i < 5; ++i) {
            cin >> input[i];
        }
        Student stu[5];
        for (int i = 0; i < 5; ++i) {
            stu[i].scoretotalcount(input[i]);
        }
        cout << Student::sum() << ' ' << Student::average() << endl;
    }
    return 0;
}