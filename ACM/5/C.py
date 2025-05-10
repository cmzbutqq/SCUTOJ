'''
题目描述
给定一个由 n 个随机正整数组成的序列a。你的任务是计算以下和：
,sum_{i=1}^{n} ,sum_{j=1}^{n}(a_i,, mod ,, a_j)
输入格式
第一行一个整数 n (1≤n≤200000)
第二行给出 n 个以空格分隔的正整数，保证每个整数都是在 
[1,10 ^12 ] 范围内随机生成
输出格式
输出一个整数，表示和取模 998244353 后的结果


样例数据
输入

2
3 5
输出

5

备注
1、 如果不会的话，可以对调和级数稍加思考哦：
1+1/2+1/3+1/4+...+1/n=ln(n+1)+r (r 为常量，约为 0.5772156649。ln 是底为自然常数 e 的对数函数)。
2、数据是随机生成的,可以认为其在取值区间内均匀分布
Python 性能要好
'''
from bisect import bisect_left, bisect_right

MOD = 998244353


import sys
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
a.sort()

# 前缀和
pre = [0] * (n + 1)
for i in range(n):
    pre[i + 1] = (pre[i] + a[i]) % MOD

ans = 0

for i in range(n):
    x = a[i]
    # 对每个 x 枚举商 k
    k = 1
    while k * k <= x:
        lval = x // (k + 1) + 1
        rval = x // k
        l = bisect_left(a, lval)
        r = bisect_right(a, rval)
        cnt = r - l
        if cnt > 0:
            seg = (pre[r] - pre[l]) % MOD
            ans = (ans + (x - k * seg) % MOD) % MOD
        k += 1
    # 处理 a_j > x 的部分（商为0）
    r = bisect_right(a, x)
    seg = (pre[n] - pre[r]) % MOD
    ans = (ans + n * x - x * r - 0 * seg) % MOD
print(ans)

