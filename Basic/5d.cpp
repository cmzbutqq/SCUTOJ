#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stepPattern
{
    int di;
    int dj;
} Pattern[8];
void init_stepPatterns();

int calc_step(int m, int n, int a, int b, int c, int d)
{
    int stepArray[m][n]; // 存放步骤数->0为起点 -1为未达 1为第一步终点...
    a -= 1;
    b -= 1;
    c -= 1;
    d -= 1; // 坐标->索引
    for (int i = 0; i < m; ++i)
    { // 填充-1
        for (int j = 0; j < n; ++j)
        {
            stepArray[i][j] = -1;
        }
    }
    stepArray[a][b] = 0; // 设置起点

    for (int step = 0; step < 400; ++step)
    { // 步骤推进
        vector<int> lastStep_i, lastStep_j;
        if (stepArray[c][d] >= 0)
        {
            return stepArray[c][d];
        } // 已达到终点

        for (int checker_i = 0; checker_i < m; ++checker_i)
        { // 行遍历
            for (int checker_j = 0; checker_j < n; ++checker_j)
            { // 列遍历
                if (stepArray[checker_i][checker_j] == step)
                { // 如果这里是最新一步，则录入向量
                    lastStep_i.push_back(checker_i);
                    lastStep_j.push_back(checker_j);
                }
            }
        }
        for (int lastStepCounter = 0; lastStepCounter < lastStep_i.size(); ++lastStepCounter)
        {
            for (int stepType = 0; stepType < 8; ++stepType)
            {
                int new_i = lastStep_i[lastStepCounter] + Pattern[stepType].di;
                int new_j = lastStep_j[lastStepCounter] + Pattern[stepType].dj;
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n)
                {
                    if (stepArray[new_i][new_j] == -1)
                    {
                        stepArray[new_i][new_j] = step + 1;
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{

    init_stepPatterns();

    int k;
    while (cin >> k)
    { // 输入数据中第一行为一个整数k（0到50），表示后面测试用例的数目
        int Ans[k];
        for (int testCount = 0; testCount < k; ++testCount)
        {
            int m, n;
            cin >> m >> n;
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << calc_step(m, n, a, b, c, d) << endl;
        }
    }
    return 0;
}

void init_stepPatterns()
{
    int Pattern_init_counter = 0;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int v = 0; v < 2; ++v)
            {
                if (v)
                {
                    Pattern[Pattern_init_counter].di = 1;
                    Pattern[Pattern_init_counter].dj = 2;
                }
                else
                {
                    Pattern[Pattern_init_counter].di = 2;
                    Pattern[Pattern_init_counter].dj = 1;
                }

                if (j)
                {
                    Pattern[Pattern_init_counter].dj *= -1;
                }
                if (i)
                {
                    Pattern[Pattern_init_counter].di *= -1;
                }
                ++Pattern_init_counter;
            }
        }
    }
    return;
}