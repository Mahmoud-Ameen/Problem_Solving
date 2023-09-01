/*
 * Problem Link: https://leetcode.com/problems/house-robber-ii/
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = (int) nums.size();
        vector<int> choice1Vec,choice2Vec;

        choice1Vec.push_back(nums[0]);
        for (int i = 1; i < n-1; ++i) {
            choice1Vec.push_back(nums[i]);
            choice2Vec.push_back(nums[i]);
        }
        choice2Vec.push_back(nums[n-1]);

        return max(houseRobber1(choice1Vec), houseRobber1(choice2Vec));
    }

private:
    int houseRobber1(vector<int>& nums) {
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
