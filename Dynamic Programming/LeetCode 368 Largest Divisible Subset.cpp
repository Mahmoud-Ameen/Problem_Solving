#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = static_cast<int>(nums.size());
        vector<int> dp(n,1);
        vector<int> prevTable(n,-1);

        for (int index = 1; index < n; ++index) {
            for (int prev = index-1; prev >= 0; --prev) {
                if(nums[index] % nums[prev] == 0 && dp[prev] + 1 > dp[index] ) {
                    dp[index] = dp[prev] + 1;
                    prevTable[index] = prev;
                }
            }
        }

        int maxSize = 0;
        int mxIndex = 0;
        for (int i = 0; i < n; ++i) {
            if(dp[i] > maxSize){
                maxSize = dp[i];
                mxIndex = i;
            }
        }

        vector<int> ans;
        auto current = mxIndex;
        while(prevTable[current]!=-1){
            ans.push_back(nums[current]);
            current = prevTable[current];
        }
        ans.push_back(nums[current]);

        return ans;
    }
};