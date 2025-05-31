#include <bits/stdc++.h>
using namespace std;

struct Task {
    int a, b, id;
};

int N;
Task tasks[205];
int sumA = 0;
const int INF = 1e9;

// Johnson 排序规则
bool johnson_cmp(const Task &x, const Task &y) {
    if (min(x.a, x.b) == x.a)
        return x.a < y.a; // a_i <= b_i 按 a_i 升序
    else
        return x.b > y.b; // a_i > b_i 按 b_i 降序
}

// 计算单组任务完成时间
int calcCompletionTime(vector<Task> &group) {
    if (group.empty())
        return 0;
    // 先根据 Johnson 规则排序
    vector<Task> left, right;
    for (auto &t : group) {
        if (t.a <= t.b)
            left.push_back(t);
        else
            right.push_back(t);
    }
    sort(left.begin(), left.end(),
         [](const Task &x, const Task &y) { return x.a < y.a; });
    sort(right.begin(), right.end(),
         [](const Task &x, const Task &y) { return x.b > y.b; });
    vector<Task> ordered;
    ordered.insert(ordered.end(), left.begin(), left.end());
    ordered.insert(ordered.end(), right.begin(), right.end());

    // 计算完成时间
    int timeA = 0; // 点餐结束时间累计
    int maxCompletion = 0;
    for (auto &t : ordered) {
        timeA += t.a;                 // 点餐时间累积
        int finishTime = timeA + t.b; // 该队员吃完时间
        if (finishTime > maxCompletion)
            maxCompletion = finishTime;
    }
    return maxCompletion;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> tasks[i].a >> tasks[i].b;
        tasks[i].id = i;
        sumA += tasks[i].a;
    }

    // DP数组，存储最小最大完成时间
    // 为节省内存，只保留上一行状态
    vector<int> dp_prev(sumA + 1, INF);
    vector<int> dp_curr(sumA + 1, INF);
    // 记录任务分配方案，用位掩码或者类似结构，这里为了节省内存只记录可行性即可，方案恢复可另写
    // 由于N=200，存储方案需优化或者后续回溯

    dp_prev[0] = 0;

    // 用于回溯分组（存放第一组任务的集合）
    vector<bitset<205>> group_mask_prev(sumA + 1);
    vector<bitset<205>> group_mask_curr(sumA + 1);

    for (int i = 1; i <= N; i++) {
        fill(dp_curr.begin(), dp_curr.end(), INF);
        for (int t = 0; t <= sumA; t++) {
            if (dp_prev[t] == INF)
                continue;

            // 放第一个窗口
            int t1 = t + tasks[i].a;
            if (t1 <= sumA) {
                // 构建两组任务
                vector<Task> group1, group2;
                bitset<205> mask = group_mask_prev[t];
                mask.set(i);

                for (int j = 1; j <= N; j++) {
                    if (j < i) {
                        if (group_mask_prev[t].test(j))
                            group1.push_back(tasks[j]);
                        else
                            group2.push_back(tasks[j]);
                    }
                }
                group1.push_back(tasks[i]);

                int c1 = calcCompletionTime(group1);
                int c2 = calcCompletionTime(group2);
                int val = max(c1, c2);
                if (val < dp_curr[t1]) {
                    dp_curr[t1] = val;
                    group_mask_curr[t1] = mask;
                }
            }

            // 放第二个窗口
            // t 不变
            {
                vector<Task> group1, group2;
                bitset<205> mask = group_mask_prev[t];
                // 不set i, i 放第二组
                for (int j = 1; j <= N; j++) {
                    if (j < i) {
                        if (group_mask_prev[t].test(j))
                            group1.push_back(tasks[j]);
                        else
                            group2.push_back(tasks[j]);
                    }
                }
                group2.push_back(tasks[i]);

                int c1 = calcCompletionTime(group1);
                int c2 = calcCompletionTime(group2);
                int val = max(c1, c2);
                if (val < dp_curr[t]) {
                    dp_curr[t] = val;
                    group_mask_curr[t] = mask;
                }
            }
        }
        swap(dp_prev, dp_curr);
        swap(group_mask_prev, group_mask_curr);
    }

    int ans = INF;
    for (int t = 0; t <= sumA; t++) {
        if (dp_prev[t] < ans)
            ans = dp_prev[t];
    }
    cout << ans << "\n";
    return 0;
}
