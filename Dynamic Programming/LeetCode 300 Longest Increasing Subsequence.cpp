#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return bottomUp(nums);
    }

    // Not needed for this problem
    void printLIS(const vector<int>& nums){
        int n = int(nums.size());
        vector<int> dp(n,1);

        vector<int> path(n,-1);
        for (int index = 1; index < n; ++index) {
            for (int prev = 0; prev < index; ++prev)
                if (nums[index] > nums[prev] && dp[prev] + 1 > dp[index]) {
                    dp[index] = dp[prev] + 1;
                    path[index] = prev;
                }
        }
        int maxElementIndex = 0;
        for (int i = 0; i < n; ++i) {
            if(dp[i] > dp[maxElementIndex])
                maxElementIndex = i;
        }

        vector<int> LIS;
        while(maxElementIndex!=-1){
            LIS.push_back(nums[maxElementIndex]);
            maxElementIndex = path[maxElementIndex];
        }

        reverse(LIS.begin(),LIS.end());

        for(auto& i: LIS)
            cout << i <<" ";

        cout <<endl;
    }

private:
    int bottomUp(const vector<int>& nums){
        int n = int(nums.size());
        vector<int> dp(n,1);

        for (int index = 1; index < n; ++index) {
            for (int prev = 0; prev < index; ++prev) {
                if(nums[index] > nums[prev])
                    dp[index] = max(dp[prev] + 1,dp[index]);
            }
        }

        return *max_element(dp.begin(),dp.end());
    }

};

int main(){
    Solution s;
    vector<int>v{10,9,2,5,3,7,101,18};
    s.printLIS(v);
}
