def solve(n, p, d):
    visited = [False] * (n + 1)
    belong = [0] * (n + 1)
    ring_size = []
    
    # 找出所有环，并为每个位置标记它属于哪个环
    ring_id = 0
    for i in range(1, n + 1):
        if not visited[i]:
            ring_id += 1
            curr = i
            size = 0
            while not visited[curr]:
                visited[curr] = True
                belong[curr] = ring_id
                curr = p[curr - 1]
                size += 1
            ring_size.append(size)

    broken = [False] * (ring_id + 1)
    res = []
    total_ops = 0

    for i in d:
        r_id = belong[i]
        if not broken[r_id]:
            broken[r_id] = True
            total_ops += ring_size[r_id - 1]
        res.append(total_ops)

    return res

if __name__ == "__main__":
    import sys
    input = sys.stdin.readline

    n = int(input())
    p = list(map(int, input().split()))
    d = list(map(int, input().split()))

    result = solve(n, p, d)
    print(" ".join(map(str, result)))
