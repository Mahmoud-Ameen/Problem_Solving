/*
 * Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n = int(nums.size());

        unordered_map<int,int> sums;
        sums[0] = 1;

        int prefixSum[int(2e4)+5]{0};

        int count = 0;
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i-1];

            if(sums.find(prefixSum[i] - target) != sums.end()){
                count+=sums[prefixSum[i] - target];
            }

            sums[prefixSum[i]]++;
        }

        return count;
    }
};
