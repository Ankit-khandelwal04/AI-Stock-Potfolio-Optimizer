#include "Optimizer.h"
#include <vector>
#include <algorithm>
#include <cmath>

// Modified 0/1 knapsack: budget is integer. Prices are rounded to nearest int
// to serve as weights for DP. Returns a vector of selected weights (price used)
// for each stock (0 means not selected).
std::vector<double> Optimizer::optimize(const std::vector<Stock>& stocks, int budget, double riskTolerance) {
    int n = static_cast<int>(stocks.size());
    if (budget <= 0 || n == 0) return std::vector<double>();

    // Convert prices to integer units
    std::vector<int> prices(n);
    std::vector<double> values(n);
    for (int i = 0; i < n; ++i) {
        prices[i] = static_cast<int>(std::round(stocks[i].getPrice()));
        values[i] = stocks[i].getExpectedReturn();
    }

    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(budget + 1, 0.0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= budget; ++w) {
            if (stocks[i - 1].getRisk() <= riskTolerance && prices[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - prices[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    std::vector<double> selection(n, 0.0);
    int w = budget;
    for (int i = n; i > 0; --i) {
        if (w >= 0 && dp[i][w] > dp[i - 1][w]) {
            // selected
            selection[i - 1] = static_cast<double>(prices[i - 1]);
            w -= prices[i - 1];
            if (w < 0) break;
        }
    }

    return selection;
}