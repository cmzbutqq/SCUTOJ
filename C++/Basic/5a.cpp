#include <iostream>
using namespace std;

struct Students
{
    string name;
    int score;
};
void find_max(Students stu[10]);

int main()
{
    string name;
    int score;
    Students stu[10];
    int counter = 0;
    while (cin >> name >> score)
    {
        stu[counter].name = name;
        stu[counter].score = score;
        counter++;
        if (counter >= 10)
        {
            find_max(stu);
            counter %= 10;
        }
    }
    return 0;
}

void find_max(Students stu[10])
{
    int index = 0;
    int max = stu[index].score;
    for (int i = 1; i < 10; i++)
    {
        if (stu[i].score > max)
        {
            index = i;
            max = stu[index].score;
        }
    }
    cout << stu[index].name << endl;
    return;
}