/*
 * Problem Link: https://leetcode.com/problems/house-robber/
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = static_cast<int> (nums.size());

        int beforePrev = nums[0]; // number before the previous
        int prev = 0; // for previous

        if(n > 1)
            prev = max(nums[1],nums[0]);

        int current = max(prev, beforePrev);

        for (int index = 2; index < n; ++index) {
            int take = beforePrev + nums[index];
            current = max(take,prev);

            beforePrev = prev;
            prev = current;
        }

        return current;
    }
};