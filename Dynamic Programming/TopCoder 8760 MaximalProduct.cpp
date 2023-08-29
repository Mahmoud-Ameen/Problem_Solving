/*
 * Problem Link: https://community.topcoder.com/stat?c=problem_statement&pm=8760
 *
 * Note: This class contains two acceptable DP solutions: one with the bottom-up technique and the other using memoization.
 * */

#include <bits/stdc++.h>

using namespace std;

class MaximalProduct{

public:
    long long maximalProduct(int s,int k){
        /* memo approach */
        memo.assign(k + 1, vector<long long>(s + 1, -1));
        return maximalProductMemo(s,k);

        /* bottom up approach */
//        return maximalProductBottomUp(s,k);
    }

private:

    vector<vector<long long>> memo;
    long long maximalProductMemo(int s, int k){
        if(memo[k][s] != -1)
            return memo[k][s];

        if(k == 1) return memo[k][s] = s;

        long long maxProduct = 0;

        for (int i = 1; i < s; ++i) {
            maxProduct = max(maxProduct, maximalProductMemo(s-i,k-1) * i);
        }
        return memo[k][s] = maxProduct;
    }

    long long maximalProductBottomUp(int s,int k){
        vector<vector<long long>> dp(k + 1, vector<long long>(s + 1, 0));

        for (int i = 0; i <= s; ++i) {
            dp[1][i] = i;
        }

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= s; ++j) {
                for (int l = 1; l < j; ++l) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-l] * l);
                }
            }
        }

        return dp[k][s];
    }

};

