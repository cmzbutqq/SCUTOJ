'''
题目描述
作为星际采矿飞船的指挥官，你发现了小行星带中分布着多种稀有晶体矿。每种矿物单位重量能量密度不同，且受采集设备限制，每种最多开采固定次数。飞船货舱最大载重为M，如何在保证不超载的前提下，组合采集不同矿物获得最大总能量？
给定n 种矿物，第i种矿物单块重量为 w[i]，能量值为v[i]，最大可采集块数s[i]。飞船货舱最大载重为M。求在总重量不超过 M 的前提下，可装载矿物的最大总能量。
输入格式
第一行两个整数n（矿物种类）和M（货舱容量）
接下来n 行，每行三个整数 w[i]、v[i]、s[i]，描述一种矿物的属性
输出格式
单个整数表示最大总能量
样例数据
输入
3 15
4 20 2
3 15 3
7 50 1
输出
90
备注
1≤n≤100
1≤M≤20000
1≤w[i]≤M
0≤v[i]≤1000000
1 ≤ s[i] ≤ 1000
'''

n, M = map(int, input().split())
w = []
v = []
s = []
for _ in range(n):
    wi, vi, si = map(int, input().split())
    w.append(wi)
    v.append(vi)
    s.append(si)

items = []
for i in range(n):
    k = 1
    while k <= s[i]:
        items.append((w[i] * k, v[i] * k))
        s[i] -= k
        k *= 2
    if s[i] > 0:
        items.append((w[i] * s[i], v[i] * s[i]))

dp = [0] * (M + 1)
for weight, value in items:
    for j in range(M, weight - 1, -1):
        if dp[j - weight] + value > dp[j]:
            dp[j] = dp[j - weight] + value

print(dp[M])