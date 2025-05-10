'''
题目描述
给出 N 个整数，求包含这 N 个整数的最短的等差数列有几项？
要求 N 个整数必须都在该等差数列中出现，并且保证至少存在一个等差数列包含这 N 个整数。


输入格式
第一行一个整数 N。

第二行包含 N 个整数，第 i 个整数为 Ai


输出格式
一行一个整数表示答案。


样例数据
输入

5
4 8 10 2 16
输出

8

备注
2≤N≤10 ^5 ,0≤Ai ≤10^9
Python 性能要好
'''
import math
import sys

def solve():
    N = int(sys.stdin.readline())
    a_values = list(map(int, sys.stdin.readline().split()))

    a = sorted(list(set(a_values)))
    
    m = len(a)

    min_val = a[0]
    max_val = a[-1]


    common_difference = 0 
    
    for i in range(1, m):

        diff = a[i] - a[i-1] 
        common_difference = math.gcd(common_difference, diff)

    num_terms = (max_val - min_val) / common_difference + 1
    print(int(num_terms))

if __name__ == '__main__':
    solve()