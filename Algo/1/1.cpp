#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int d = y - x;
        int b = max(0, (-d + 1) / 2); // ceil(-d/2) 写成 (-d + 1) / 2
        int ans = 3 * b + d;
        printf("%d\n", ans);
    }
    return 0;
}
