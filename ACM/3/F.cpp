/*
题目描述
给你一个字符串 s1，它是由某个字符串
s2不断自我连接形成的（至少重复2次）。但是字符串s2
是不确定的，现在想知道它的最短长度是多少。 输入格式
第一行一个整数L，表示给出字符串的长度。
第二行给出字符串 s1 的一个子串，全由小写字母组成。
输出格式
仅一行一个整数，表示 s2的最短长度。
样例数据
输入
8
cabcabca
输出
3
备注
对于样例，可以使用 bca 不断自我连接得到 bcabcabcabca，而读入的 cabcabca,
是它的子串。
1≤L≤10^6
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int L;
    cin >> L;
    string s;
    cin >> s;

    vector<int> next(L + 1, 0); // next[0]不用，next[1~L]有意义
    int j = 0;
    for (int i = 1; i < L; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i + 1] = j;
    }

    int len = L - next[L];
    cout << len << endl;

    return 0;
}
