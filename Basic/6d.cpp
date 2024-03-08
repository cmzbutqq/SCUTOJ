#include <iostream>
#include <string>
using namespace std;

string func(string &str) {
    int size = str.size();
    string reversedStr = "";
    for (int i = size - 1; i >= 0; --i) {
        reversedStr += str[i];
    }

    size = reversedStr.size();
    static string ans = "";
    for (int i = 0; i < size; ++i) {
        int dymanic_size = ans.size();
        for (int j = 0; j < dymanic_size; ++j) {
            if (ans[j] == reversedStr[i]) {
                goto break_point;
            }
        }
        ans += reversedStr[i];
    break_point:;
    }
    return ans;
}
int main() {
    int m;
    while (cin >> m) {
        string str = to_string(m);
        string ans = func(str);
        cout << ans << endl;
    }
    return 0;
}