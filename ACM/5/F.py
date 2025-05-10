'''
题目描述
Hiraethsoul最近沉迷于一款网游，但其中的装备强化系统令他崩溃。每次强化，装备有概率升一级，但不同等级的装备强化成功的概率并不相同。具体来说，当装备处于i级时，强化成功的概率为1/pi，强化失败则会直接跌落到1级。现在Hiraethsoul有一件1级装备，他想要知道他将其强化到n级需要的期望强化次数。
输入格式
第一行一个整数n.
第二行共n-1个整数，第i个数pi表示i级装备强化后变成计i+1级的概率为1/pi
输出格式
一个整数，表示答案对10^9+7取模后的结果。
样例数据
输入
2
2
输出
2
备注
·样例需要次数为1*1/2+2*1/4+3*1/8+...=2次，取模后结果为2
·如果答案为一个分数a/b，则输出a*b^-1mod(10^9+7),b^-1表示在模10^9+7
下的逆元
Python 性能要好
'''

import sys

MOD = 10**9 + 7

def solve():
    n = int(sys.stdin.readline())
    p = list(map(int, sys.stdin.readline().split()))
    
    inv_p = [0] * (n)
    for i in range(n-1):
        inv_p[i+1] = pow(p[i], MOD-2, MOD)
    
    E = [0] * (n + 2)  # 1-based to n
    E[n] = 0
    
    # We'll compute S and T such that E[i] = S[i] + T[i] * E[1]
    S = [0] * (n + 2)
    T = [0] * (n + 2)
    S[n] = 0
    T[n] = 0
    
    for i in range(n-1, 0, -1):
        # E[i] = 1 + (inv_p[i] * E[i+1] + (1 - inv_p[i]) * E[1])
        # But E[i+1] is S[i+1] + T[i+1]*E[1]
        part_success = inv_p[i] * S[i+1] % MOD
        part_fail = (1 - inv_p[i]) % MOD
        total = (1 + part_success) % MOD
        coeff = (inv_p[i] * T[i+1] % MOD + part_fail) % MOD
        S[i] = total
        T[i] = coeff
    
    # E[1] = S[1] + T[1] * E[1]
    # => E[1] - T[1]*E[1] = S[1]
    # => E[1]*(1 - T[1]) = S[1]
    # => E[1] = S[1] / (1 - T[1])
    denom = (1 - T[1]) % MOD
    inv_denom = pow(denom, MOD-2, MOD)
    E1 = (S[1] * inv_denom) % MOD
    print(E1)

solve()