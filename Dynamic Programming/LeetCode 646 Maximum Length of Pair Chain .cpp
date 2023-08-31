#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());

        int n = int(pairs.size());
        vector<int> dp(n,1);

        for (int index = 1; index < n; ++index) {
            for (int prev = index-1; prev >= 0; --prev) {
                if(pairs[prev][1]  < pairs[index][0] && dp[prev] + 1 > dp[index])
                    dp[index] = dp[prev] + 1;
            }
        }

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if(mx < dp[i]) mx = dp[i];
        }

        return mx;
    }
};