#include <algorithm> // For std::min if needed elsewhere
#include <iostream>
#include <numeric> // Potentially for std::accumulate, though a loop is fine
#include <string>
#include <vector>

// Helper function to convert card string to integer value
int card_str_to_int(const std::string &s) {
    if (s == "A")
        return 1;
    if (s == "J")
        return 11;
    if (s == "Q")
        return 12;
    if (s == "K")
        return 13;
    try {
        return std::stoi(s); // For "2" through "10"
    } catch (const std::invalid_argument &ia) {
        // Handle error or assume valid input as per problem constraints
        // For competitive programming, often inputs are guaranteed to be valid
        return 0; // Should not happen with valid inputs
    }
}

const int MAX_SINGLE_CARD_VAL = 13;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int m;
    std::cin >> n >> m;

    std::vector<int> card_values(n);
    long long total_card_sum = 0;

    for (int i = 0; i < n; ++i) {
        std::string card_str;
        std::cin >> card_str;
        card_values[i] = card_str_to_int(card_str);
        total_card_sum += card_values[i];
    }

    // dp[j] is true if a sum of j can be achieved using a subset of cards.
    // The maximum sum we might need to check is M + MAX_SINGLE_CARD_VAL - 1.
    // So, the size of dp array needs to be M + MAX_SINGLE_CARD_VAL.
    int dp_size = m + MAX_SINGLE_CARD_VAL;
    std::vector<bool> dp(dp_size, false);
    dp[0] = true;

    for (int card_val : card_values) {
        // Iterate downwards to ensure each card is used at most once for a
        // given sum calculation
        for (int j = dp_size - 1; j >= card_val; --j) {
            if (dp[j - card_val]) {
                dp[j] = true;
            }
        }
    }

    int min_sum_used = -1;
    // Find the smallest sum >= m that is achievable
    // We only need to check up to m + MAX_SINGLE_CARD_VAL - 1
    for (int s = m; s < dp_size; ++s) {
        if (dp[s]) {
            min_sum_used = s;
            break;
        }
    }

    if (min_sum_used == -1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << total_card_sum - min_sum_used << std::endl;
    }

    return 0;
}