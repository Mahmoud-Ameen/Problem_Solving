/**
 * Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
 * Subset problem
 * */

#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {

    bool dp[n][k+5];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = false;
        }
    }

    if(arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int index = 1; index < n; ++index) {
        for (int target = 0; target <= k; ++target) {
            // target = current element
            // or target already found in a smaller subarray
            // or target - current element already found
            if(arr[index] == target ||
                dp[index-1][target] || (target - arr[index] >= 0 &&
                dp[index-1][target - arr[index]]))
                    dp[index][target] = true;
        }
    }

    return dp[n-1][k];
}

