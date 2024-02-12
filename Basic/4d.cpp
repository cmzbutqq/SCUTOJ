
#include <iostream>
#include <string>
using namespace std;
string theString;
void add(string s1, int x);
void del(int x, int n);
void ser(string s1);
void cha(string s1, int x);
void printS()
{
    cout << theString << endl;
    return;
}

int main()
{
    cin >> theString;
    string command, s1;
    int x, n;
    while (cin >> command)
    {
        switch (command[0])
        {
        case 'A':
            cin >> s1 >> x;
            add(s1, x);
            break;
        case 'D':
            cin >> x >> n;
            del(x, n);
            break;
        case 'S':
            cin >> s1;
            ser(s1);
            break;
        case 'C':
            cin >> s1 >> x;
            cha(s1, x);
            break;
        }
    }
    return 0;
}
void add(string s1, int x)
{
    // 1.ADD：接收一个新字符串和一个int类型数x，将接收到的字符串插入到原字符串【下标为x的字符的后面】（字符的位置从0开始），并打印出新字符串。
    theString.insert(x + 1, s1);
    printS();
    return;
}
void del(int x, int n)
{
    // 2.DEL：接收两个int类型数x,n，从原字符串中删除【下标为x的字符开始】的n个字符，并打印出新字符串。
    theString.erase(x, n);
    printS();
    return;
}
void ser(string s1)
{
    // 3.SER：接收一个字符串，寻找原字符串中否有和新字符串相等的部分，并打印出相等部分的【第一个字母的位置】标号,若有多个匹配部分，只输出第一个匹配部分的标号。（结果一定存在）
    int pos = theString.find(s1);
    cout << pos << endl;
    return;
}
void cha(string s1, int x)
{
    // 4.CHA：接收一个新字符串和一个int类型数x，用接收到的字符串覆盖掉原字符串对应长度的内容，从【下标为x的字符开始】。
    theString.replace(x, s1.size(), s1);
    printS();
    return;
}