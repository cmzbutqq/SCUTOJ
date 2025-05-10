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
Python 性能要好
'''
n = int(input())
s = input().strip()

def count_moves(s):
    n = len(s)
    moves = 0
    i = 0
    while i < n:
        if i <= n - 4 and s[i] == '1' and s[i+1] == '0' and s[i+2] == '1' and s[i+3] == '0':
            moves += 1
            i += 4
        elif i <= n - 3 and s[i] == '1' and s[i+1] == '1' and s[i+2] == '0':
            moves += 1
            i += 3
        elif i <= n - 3 and s[i] == '1' and s[i+1] == '0' and s[i+2] == '0':
            moves += 1
            i += 3
        elif i <= n - 2 and s[i] == '1' and s[i+1] == '0':
            moves += 1
            i += 2
        else:
            i += 1
    return moves

total_moves = count_moves(s)

if total_moves % 2 == 1:
    print("Alice")
else:
    print("Bob")