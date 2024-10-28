#include <iostream>
#include <string>
using namespace std;
void solve(int num) {
    string str = to_string(num);
    bool hash[10] = {0};
    for (int i = str.length() - 1; i >= 0; i--) {
        int index= str[i] - '0';
        if (hash[index])
            continue;
        hash[index] = 1;
        cout << str[i];
    }
    cout << endl;
}
int main() {
    int num;
    while (cin >> num) {
        solve(num);
    }
    return 0;
}