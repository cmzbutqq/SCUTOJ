"""
题目描述
在皇家花园中，园丁长需要为即将到来的庆典布置一排花坛。每朵花都有其独特的高度，但为了美观，花坛的排列必须形成一个先严格递增再严格递减的波浪形。具体来说，设剩下的k朵花从左到右编号为1 到k，它们的高度必须满足 h[1]< h[2] <.… <h【i】 >h[i＋ 1] >.… >h[K](1 ≤i≤k)。园丁长可以移除多余的花朵，但希望尽可能保留更多的花朵。请问，最少需要移除多少朵花，才能满足这一要求？
给定n 朵花，每朵花的高度为h[i]。请计算最少需要移除多少朵花，使得剩下的花朵排列成先严格递增后严格递减的波浪形。
输入格式
·第一行包含一个整数n(2≤n≤100)，表示花朵的数量。
·第二行有 n个整数，用空格分隔，第i个整数 h; 是(130≤ hi≤230)第i朵花的高度。
输出格式
一个整数，表示最少需要移除的花朵数量。
样例数据
输入
8
186 186 150 200 160 130 197 220
输出
4
备注
"""
def min_removals_to_wave(n, h):
    up = [1] * n
    down = [1] * n

    # 计算以每个点为结尾的最长严格递增子序列长度
    for i in range(n):
        for j in range(i):
            if h[j] < h[i]:
                up[i] = max(up[i], up[j] + 1)

    # 计算以每个点为起点的最长严格递减子序列长度
    for i in reversed(range(n)):
        for j in range(i+1, n):
            if h[j] < h[i]:
                down[i] = max(down[i], down[j] + 1)

    # 枚举每个山峰点，求最长山形子序列
    max_len = 0
    for i in range(n):
        if up[i] > 1 and down[i] > 1:
            max_len = max(max_len, up[i] + down[i] - 1)

    return n - max_len
# 输入处理
n = int(input())
h = list(map(int, input().split()))

# 输出结果
print(min_removals_to_wave(n, h))