/*
 * Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int n = int(nums.size());
       // pair at index "i" stores max LIS length up to index "i"
       // as well as count of different ways to reach a LIS of this length
       // with elements from index 0 to index "i"
        vector<pair<int,int>> dp (n, {1,1});
        dp[0].second = 1;

        int maxSubsequenceLength = 1;
        for (int index = 1; index < n; ++index) {
            // count of LIS with length dp[index] (initially zero)
            int count = 1;
            for (int prev = index-1; prev >= 0; --prev) {
                if(nums[index] > nums[prev] ){
                    // Found a previous element that is the last element of a longer subsequence.
                    // Extend this subsequence to include this element by setting dp[index].first to length of that subsequence + 1
                    // Count of occurrences of a subsequence with this length is the same as the count of occurrences of the subsequence
                    // that we constructed this one by extending (dp[prev].second).
                    if(dp[prev].first + 1 > dp[index].first){
                        dp[index].first = dp[prev].first + 1;
                        count = dp[prev].second;
                        if(dp[index].first > maxSubsequenceLength) {
                            maxSubsequenceLength = dp[index].first;
                        }
                    }
                    // Found another set of sequences that can be of current max length if added this element to.
                    // add count of these new sequences to existing ones.
                    else if(dp[prev].first + 1 == dp[index].first)
                        count+= dp[prev].second;
                }
            }
            // finalize count of occurrences of sequences with length (dp[index].first) up till this index.
            dp[index].second = count;
        }

        if(maxSubsequenceLength == 1) return n;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(dp[i].first == maxSubsequenceLength) ans+=dp[i].second;
        }

        return ans;
    }
};
