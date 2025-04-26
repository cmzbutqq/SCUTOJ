# 题目描述
# 给出两个字符串 s1 和 s2，若 s1 的区间[1,r] 子串与 s2 完全相同，则称 s2 在 s1
# 中出现了，其出现位置为1. 现在请你求出 s2 在 s1 中所有出现的位置。 输入格式
# ·第一行为一个字符串，即为 s1
# ·第二行为一个字符串，即为 s2
# 输出格式
# 输出一行，按从小到大的顺序输出 s2 在 s1 中出现的位置。
# 样例数据
# 输入
# abababc
# aba
# 输出
# １3
# 备注
# 对于全部的测试点，保证 1≤|s1|,|s2|≤2＊10^6
# 且 s1,s2 中均只含小写英文字母。

def get_next(s):
    n = len(s)
    nxt = [0] * n
    j = 0
    for i in range(1, n):
        while j > 0 and s[i] != s[j]:
            j = nxt[j - 1]
        if s[i] == s[j]:
            j += 1
        nxt[i] = j
    return nxt

def kmp_search(s1, s2):
    n, m = len(s1), len(s2)
    nxt = get_next(s2)
    res = []
    j = 0
    for i in range(n):
        while j > 0 and s1[i] != s2[j]:
            j = nxt[j - 1]
        if s1[i] == s2[j]:
            j += 1
        if j == m:
            res.append(i - m + 2)  # 注意位置是从1开始的
            j = nxt[j - 1]
    return res

def main():
    import sys
    input = sys.stdin.read
    s1, s2 = input().split()
    ans = kmp_search(s1, s2)
    print(' '.join(map(str, ans)))

if __name__ == "__main__":
    main()
