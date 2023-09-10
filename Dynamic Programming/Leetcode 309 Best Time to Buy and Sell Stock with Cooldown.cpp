/*
 * Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * */

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        vector<vector<int>> dp (2, vector<int>(n + 2, 0));

        for (int i = n-1; i >= 0; --i) {
            // Max profit if reached here with a stock bought
            {
                int c1 = prices[i] + dp[false][i+2];
                int c2 = dp[true][i+1];
                dp[true][i] = max(c2, c1);
            }
            // Max profit if reached here without owning a stock
            {
                int c1 = -prices[i] +  dp[true][i+1];
                int c2 = dp[false][i+1];
                dp[false][i] = max(c2, c1);
            }

        }
        return dp[0][0];
    }
};
