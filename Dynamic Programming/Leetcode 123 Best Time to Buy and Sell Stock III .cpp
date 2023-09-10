/*
 * Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(5,vector<int>(prices.size(),-1));
        return recursive(0,4,prices);
    }
private:
    vector<vector<int>> dp;
    int recursive(int i, int state, vector<int>&prices){
        if(i == prices.size() || state == 0) return 0;

        if(dp[state][i] != -1) return dp[state][i];

        if(state == 4 || state == 2){
            int c1 = recursive(i+1, state,prices);
            int c2 = -prices[i] + recursive(i,state-1,prices);
            return dp[state][i] = max(c1,c2);
        }

        if(state == 3 || state == 1){
            int c1 = recursive(i+1,state,prices);
            int c2 = prices[i] + recursive(i,state - 1,prices);
            return dp[state][i] = max(c1,c2);
        }

        return 1e8;
    }
};
