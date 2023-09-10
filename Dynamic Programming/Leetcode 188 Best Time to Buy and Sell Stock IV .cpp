/*
 * Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 * */

#include <vector>
using namespace std;

// For Recursive approach, refer to Leetcode 123 Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = static_cast<int>(prices.size());

        int dp[2*k+2][n+1];
        for(int i = 0; i < 2*k+2; i++)
            for(int j =0; j <=n; j++)
                dp[i][j] = 0;

        for (int state = 1; state <= 2*k; ++state) {
            for (int i = n-1; i >= 0; --i) {
                if(state % 2 == 0){
                    int c1 = dp[state][i+1];
                    int c2 = -prices[i] + dp[state-1][i];
                    dp[state][i] = max(c1,c2);
                }

                if(state % 2){
                    int c1 = dp[state][i+1];
                    int c2 = +prices[i] + dp[state - 1][i];
                    dp[state][i] = max(c1,c2);
                }
            }
        }

        return dp[2*k][0];
    }
};
