/*
 * Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int dp[2][n+1];
        for(auto& d: dp)
            for(auto& i : d)
                i = 0;

        for (int i = n-1; i >= 0; --i) {
            //                sell today                  ,Sell another day
            dp[true][i] = max(prices[i] + dp[0][i+1] - fee, dp[1][i+1]);
            //                buy today,                buy another day
            dp[false][i] = max(-prices[i] + dp[1][i+1], dp[0][i+1]);
        }

        return dp[false][0];
    }
};