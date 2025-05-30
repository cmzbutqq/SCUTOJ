#include <algorithm>  // For std::nth_element
#include <cstdio>     // For getchar, printf
#include <functional> // For std::greater
#include <vector>

// Provided read function
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    int N = read();
    int k = read();

    std::vector<int> a_values(N);
    for (int i = 0; i < N; ++i) {
        a_values[i] = read();
    }

    // b_values vector could be optimized away if memory is extremely tight,
    // by reading B_i and calculating diffs[i] in the same loop.
    // But with N=10^7, 3 vectors of int (A, B, diffs) is ~120MB, which is
    // usually acceptable. The problem description implies reading all A then
    // all B.
    std::vector<int> b_values(N);
    for (int i = 0; i < N; ++i) {
        b_values[i] = read();
    }

    long long sum_A = 0;
    for (int i = 0; i < N; ++i) {
        sum_A += a_values[i];
    }

    if (k == 0) {
        printf("%lld\n", sum_A);
        return 0;
    }

    std::vector<int> diffs(N);
    for (int i = 0; i < N; ++i) {
        diffs[i] = b_values[i] - a_values[i];
    }

    // Find the k largest differences.
    // std::nth_element rearranges elements in [diffs.begin(), diffs.end()) such
    // that:
    // - The element at diffs.begin() + (k-1) is the element that would be at
    // that position
    //   if the range was sorted according to std::greater<int>().
    // - All elements in [diffs.begin(), diffs.begin() + (k-1)) are greater than
    // or equal to
    //   the element at diffs.begin() + (k-1).
    // So, the elements diffs[0]...diffs[k-1] are the k largest elements (in no
    // particular order). This is valid for 1 <= k <= N.
    std::nth_element(diffs.begin(), diffs.begin() + k - 1, diffs.end(),
                     std::greater<int>());

    long long sum_top_k_diffs = 0;
    for (int i = 0; i < k; ++i) {
        sum_top_k_diffs += diffs[i];
    }

    long long total_proficiency = sum_A + sum_top_k_diffs;
    printf("%lld\n", total_proficiency);

    return 0;
}