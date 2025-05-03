'''
题目描述
N(1≤ N≤2500)个花园宝宝们出来旅游，游玩途中他们遇到了一条大河，但是并没有桥，只有一艘船，还有船夫，想要过河就只能搭船。当船夫一个人在船上，他把船渡到对岸需要 M(1≤ M≤1000)分钟。当木筏搭载的花园宝宝数数目从i-1增加到i时，渡船得多花 Mi(1≤Mi≤1000)分钟才能把木
筏划过河（也就是说，船上有1个花园宝宝时，得花 M＋M1分钟渡河；船上有2个花园宝宝时，时间
就变成 M十 M1十M2分钟。后面的以此类推）。那么，最少要花多少时间，才能把所有花园宝宝带到对岸呢？当然，这个时间得包括船夫一个人把船从对岸渡回来接下一批的花园宝宝的时间。
输入格式
第一行包含 2个整数 N和 M.
接下来一共 N行，第i行一个整数 Mi.
输出格式
输出共一行，为渡河的最短时间。
样例数据
输入
5 10
3
4
6
100
1
输出
50
备注
最后一批花园宝宝渡河成功后，船夫不需要返回对岸。
'''
import sys

def min_ferry_time(N, M, Mi):
    # 预处理：计算船上有 i 个花园宝宝时一次渡河的总时间（包含船夫和花园宝宝）
    cost = [0] * (N + 1)
    cost[0] = M  # 只有船夫
    for i in range(1, N + 1):
        cost[i] = cost[i - 1] + Mi[i - 1]

    # dp[i] 表示运送前 i 个花园宝宝到对岸的最短时间
    dp = [float('inf')] * (N + 1)
    dp[0] = 0

    for i in range(1, N + 1):
        for j in range(1, i + 1):
            current_cost = cost[j]
            if i != N:
                current_cost += M  # 如果不是最后一批，还需要船夫返回
            dp[i] = min(dp[i], dp[i - j] + current_cost)

    return dp[N]

# 输入读取
if __name__ == "__main__":
    N_M = input().split()
    N = int(N_M[0])
    M = int(N_M[1])
    Mi = [int(input()) for _ in range(N)]
    print(min_ferry_time(N, M, Mi))

