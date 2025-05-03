'''
题目描述
给定n个宝物，每个宝物的重量为w[i]，价值为v[i](1≤i≤n)，以及一个最大承重为C的背包。请计算在不超出背包承重的情况下，能够携带的宝物的最大总价值
输入格式
·第一行包含两个整数n 和C，分别表示宝物数量和背包容量。
·接下来n 行，每行包含两个整数w[i] 和v[i]，表示第i个宝物的重量和价值。
输出格式
一个整数，表示最大总价值
样例数据
输入
4 10
2 3
3 5
5 8
7 9
输出
16
备注
数据范围
1≤n≤1000
1≤C≤10000
1≤w[i] ≤ C
0 ≤v[i] ≤10^6
'''
n, C = map(int, input().split())
w = []
v = []
for _ in range(n):
    wi, vi = map(int, input().split())
    w.append(wi)
    v.append(vi)

dp = [0] * (C + 1)

for i in range(n):
    for j in range(C, w[i] - 1, -1):
        if dp[j - w[i]] + v[i] > dp[j]:
            dp[j] = dp[j - w[i]] + v[i]

print(dp[C])