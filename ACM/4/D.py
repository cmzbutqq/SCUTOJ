'''
题目描述
给定一个正整数n 和一个正整数q，接下来给出q个v表示询问，对于每个询问计算满足以下条件的序列数目：
1.序列的第一个元素必须是1.
2.序列中的元素严格递增。
3.序列中任意两个相邻元素的差不超过2(即后项减前项的值为1或2)。
4. 序列的每个元素都属于[1,v]
输入格式
一个整数n 和一个整数 q(1≤n,q≤2 *10^5)。
接下来q行，每行一个整数v(1≤v≤n)
输出格式
输出q个整数，表示对每个询问符合条件的序列数目(请将最终答案对10^9＋7取模)
样例数据
输入
3 3
1
2
3
输出
1
2
4
备注
'''
import sys
input = sys.stdin.readline

MOD = 10**9 + 7
MAXN = 2 * 10**5 + 10

# 提前预处理斐波那契数列和前缀和
fib = [0] * MAXN
pre_sum = [0] * MAXN
fib[1] = 1
for i in range(2, MAXN):
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD
for i in range(1, MAXN):
    pre_sum[i] = (pre_sum[i - 1] + fib[i]) % MOD

# 读入 n 和 q
n, q = map(int, input().split())

# 处理 q 个查询
res = []
for _ in range(q):
    v = int(input())
    res.append(str(pre_sum[v]))

# 输出所有答案
print('\n'.join(res))
