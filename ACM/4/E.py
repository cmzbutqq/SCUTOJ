'''
题目描述
在虚拟世界的某个王国中，树形网络是城市间通信的核心结构。王国的网络安全部门发现，一种特殊的病毒正在网络中传播：一旦某个城市被感染，其管辖下的所有子城市（即该城市所在子树中的所有节点）会立即被强制感染。为了评估潜在风险，国王下令统计所有可能的感染状态，以便制定防御策略。你的任务是计算在遵守病毒传播规则的前提下，合法的感染方案总数。
给定一棵以节点1为根的树，包含n个节点。每个节点可以选择是否被感染，但若节点x被感染，则x的子树中的所有节点必须也被感染。求合法的感染方案数。由于结果可能极大，请将答案对(10^9+7)取模。
输入格式
·第一行包含整数n，表示树的节点数。
·接下来n-1行，每行包含两个整数u和v，表示节点u和v之间有一条边。输入保证构成一棵以1为根的树。
·数据范围(1≤n≤105)
输出格式
·输出一个整数，表示合法感染方案数对(10^9十7)取模后的结果。
样例数据
输入
3
1 2
1 3
输出
5
备注
'''
import sys
from collections import deque

MOD = 10**9 + 7

def main():
    n = int(sys.stdin.readline())
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)
    
    # Build the tree with parent-child relationships
    parent = [0] * (n + 1)
    children = [[] for _ in range(n + 1)]
    stack = [1]
    parent[1] = 0  # 0 means no parent
    while stack:
        u = stack.pop()
        for v in adj[u]:
            if v != parent[u]:
                parent[v] = u
                children[u].append(v)
                stack.append(v)
    
    # Post-order traversal to compute dp
    dp = [1] * (n + 1)
    stack = [(1, False)]
    while stack:
        u, visited = stack.pop()
        if not visited:
            stack.append((u, True))
            # Push children in reverse order to process them in order
            for v in reversed(children[u]):
                stack.append((v, False))
        else:
            product = 1
            for v in children[u]:
                product = (product * dp[v]) % MOD
            dp[u] = (product + 1) % MOD
    
    print(dp[1])

if __name__ == '__main__':
    main()