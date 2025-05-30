#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// 计算不满度
int get_unhappiness(long long price) {
    string s = to_string(price);
    // 去掉末尾0
    while (!s.empty() && s.back() == '0')
        s.pop_back();
    int a = s.size();
    if (s.back() == '5')
        return 2 * a - 1;
    return 2 * a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long L, R;
        cin >> L >> R;

        long long best_price = -1;
        int best_unhappy = 1e9;

        for (int k = 0; k <= 9; ++k) {
            long long factor = pow(10LL, k);
            long long low = (L + factor - 1) / factor;
            long long high = R / factor;
            if (low > high)
                continue;

            // 枚举个位为 1~9 的 prefix
            for (int d = 1; d <= 9; ++d) {
                long long mod = (d - (low % 10) + 10) % 10;
                long long prefix = low + mod;
                if (prefix > high)
                    continue;

                long long price = prefix * factor;
                int unhappy = get_unhappiness(price);

                if (unhappy < best_unhappy ||
                    (unhappy == best_unhappy && price < best_price)) {
                    best_unhappy = unhappy;
                    best_price = price;
                }
            }
        }

        cout << best_price << '\n';
    }

    return 0;
}
