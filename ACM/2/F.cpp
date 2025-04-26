/*
题目描述
在银河通信中心的深空监听站，科学家们接收到来自猎户座旋臂的神秘量子信号流。每个信号由离散的脉冲单元（小写字母表示）构成，但信号在传输中会经历诡异的中继增强
—— 某些区间的脉冲会被复制一次（如脉冲序列 aab 增强后变为 aaaabb）。 任务
处理两类指令：

中继增强指令：选定信号段 [l, r]，当前字符串中该段所有脉冲单元重复一次（如 x y z
→ x x y y z z），用于放大潜在的外星文明讯息。 即时解码指令：定位当前信号流中第 i
个脉冲单元，防止信息过载导致星际通信延迟。

输入格式
首行：n（初始脉冲数）、q（指令数） (保证 1≤n,q≤10^5 )
第二行：初始脉冲序列 s
后续 q 行：1 l r（中继增强）或 2 i（即时解码）b（保证 1≤r−l+1≤1000，1≤l,r,i≤len,
len 表示当前脉冲长度 ）

输出格式
对每个解码指令，输出对应脉冲单元


样例数据
输入

5 4
abcde
1 2 4
2 3
1 2 3
2 5
输出

b
b

备注
初始信号流：a b c d e
增强区间 [2,4] 后变为 a b b c c d d e
解码第 3 个脉冲 → b，
增强区间 [2,3] 后变为 a b b b b c c d d e
解码第 5 个脉冲 → b
C++回答，使用线段树
思路：
对字符串里的每个字符可以看做一个初始长度为1的块，修改操作就是修改部分块的长度，查询操作就是
询问操作位置位于哪一个块里
建立一棵树维护，树的节点只记录对应区间当前的长度，节点数不会变，因此可用数组存储；
对于一个查询操作，直接线段树上二分出其位于哪一个块即可；
对于一个修改操作，二分出其l，r位于哪个两个块，然后对于边缘的两个块做加法修改，中间的块*2即可。
可以不用lazy标记，注意修改操作是在当前字符串而非原始字符串上进行，因此可能只会扩增叶节点块中的一部分。

*/

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int len;       // 当前区间字符的个数
    char c = '\0'; // 只有叶子结点的该值有效
    Node *left = nullptr, *right = nullptr;

    Node(const string &s) {
        len = s.size();
        if (len == 1) {
            c = s[0];
            return;
        }
        int mid = len / 2;
        left = new Node(s.substr(0, mid));
        right = new Node(s.substr(mid));
    }
    bool isLeaf() { return left == nullptr && right == nullptr; }
    char query(int i) {
        if (isLeaf())
            return c;
        if (i < left->len)
            return left->query(i);
        return right->query(i - left->len);
    }
    void duplicate(int l, int r) {
        if (isLeaf()) {
            len += min(r, len - 1) - max(l, 0) + 1;
            return;
        }
        int bound = left->len;
        if (l < bound)
            left->duplicate(l, r);
        if (r >= bound)
            right->duplicate(l - bound, r - bound);
        len = left->len + right->len;
    }
};
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    Node *root = new Node(s);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            root->duplicate(l - 1, r - 1); // 转换为0-based
        } else if (op == 2) {
            int i;
            cin >> i;
            char c = root->query(i - 1);
            cout << c << '\n';
        } else if (op == 3) { // 调试操作：打印所有字符
            int total = root->len;
            for (int i = 1; i <= total; ++i) {
                cout << root->query(i - 1);
            }
            cout << '\n';
        }
    }

    return 0;
}
