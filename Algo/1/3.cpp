#include <iostream>
#define ll long long
using namespace std;
ll a[300010], b[300010];
ll n, m;

ll ceil(ll x, ll y) {
    if (y == 0)
        return 0; // 避免除以0，实际不会发生
    return (x + y - 1) / y;
}

bool check(ll k) {
    ll total = 0; // 已用课时
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {// 优先上课
            if (a[i] * m >= k) { // 仅上课
                ll x = ceil(k, a[i]);
                total += x;
            } else {          // 上课+自学
                total += m; // 上课
                ll y = ceil(k - a[i] * m, b[i]);
                total += y;// 自学
            } 
        }else{// 优先自学
        ll y = ceil(k, b[i]);
        total += y;// 自学
        }
        if (total > m * n) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    ll left = 0, right = 1e18 + 1000;
    while (left + 1 < right) {
        ll mid = left + right >> 1;
        if (check(mid))
            left = mid; // 课时数够，提高要求
        else
            right = mid;
    }
    // [[[[[[ ))))) 满足课时数"[" 的最大值答案在left
    cout << left;
    return 0;
}
