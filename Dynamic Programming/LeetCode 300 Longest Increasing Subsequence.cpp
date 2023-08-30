#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        return bottomUp(nums);
    }

private:
    int n;
    int bottomUp(const vector<int>& nums){
        vector<int> dp(n,1);

        for (int index = 1; index < n; ++index) {
            for (int prev = 0; prev < index; ++prev) {
                if(nums[index] > nums[prev])
                    dp[index] = max(dp[prev] + 1,dp[index]);
            }
        }

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx,dp[i]);
        }
        return mx;
    }

};
