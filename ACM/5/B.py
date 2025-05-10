'''
题目描述
Alice 和 Bob 在玩一个回合制游戏,游戏规则如下：
1、游戏开始时给出一个二进制字符串s。
2、在一个玩家的回合,他必须选择 s 的一个子串 t,要求t 等于 10,110,100,1010 中的任意一个,然后将其翻转。例如,如果 s=010101,玩家可以选择子串 t=1010 并将其倒转,得到 s=001011。
3、无法选择合适的子串 t 的玩家输棋。
4、玩家不可以跳过一个回合。

如果 Alice 先下,双方都采取最优策略,哪个玩家可以获胜？


输入格式
一个数 n,表示输入字符串 s 的长度；(1≤n≤10^6)
一个二进制字符串 s


输出格式
如果 Alice 获胜,则输出 Alice。否则,输出 Bob。


样例数据
输入

3
010
输出

Alice

备注
如果从 b 中删除开头的几个 (可能是零个或全部) 字符和结尾的几个 (可能是零个或全部) 字符可以得到 a,那么字符串 a 是字符串 b 的子串
'''
n = int(input())
s = input().strip()

total_inversions = 0
ones_count = 0

for c in s:
    if c == '1':
        ones_count += 1
    else:  # c == '0'
        total_inversions += ones_count

if total_inversions % 3 == 0:
    print("Bob")
else:
    print("Alice")
