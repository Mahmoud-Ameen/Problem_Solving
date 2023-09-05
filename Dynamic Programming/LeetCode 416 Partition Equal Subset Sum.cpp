/*
 * Problem link: https://leetcode.com/problems/partition-equal-subset-sum/
 * */

#include <bits/stdc++.h>

using namespace std;

/*
 * Space Optimized Bottom-Up approach
 * Beats 100% in Time and Space Efficiency.
 * */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        /*
         * In order to partition the array to two equal subsets,
         * There Should exist a subset with sum = half of array total sum.
         * That's the target we will be looking for.
         * */
        int sum = 0;
        for (int num : nums)
            sum+=num;

        // If total sum of array is odd, No partitioning can be done
        if (sum % 2 == 1) return false;

        int target = sum / 2;

        // Note that initially this is a 2d dp array problem [index][target];
        // Trying to optimize the 2d tabulation solution, we find that for each index we only need the
        // Previously computed dp index (subset sums before this index).
        // So we store only that index's dp(prevIndexDp) as well as a dp to store new computed answers in(currIndexDp).
        vector<bool> currIndexDp(target+5);
        vector<bool> prevIndexDp(target+5);

        /*
         * Since the array only contains positive numbers,
         * Any number greater than our target (half of total sum)
         *  would make it impossible to find a subset with sum = target.
         * Therefore, we can sort the array and return false once found an element greater than target.
         * */
        sort(nums.begin(),nums.end());

        if(nums[0] <= target) prevIndexDp[nums[0]] = true;

        for (int index = 1; index < n; ++index) {
            int element = nums[index];
            // If found a number greater than target
            // There is no way to partition the array
            // return false
            if(element > target) break;
            for (int miniTarget = 0; miniTarget <= target; ++miniTarget) {
                bool sumExisted = prevIndexDp[miniTarget];
                bool complementSumExists = miniTarget - element > 0 && prevIndexDp[miniTarget - element];
                if(element == miniTarget ||
                   sumExisted ||
                   complementSumExists)
                {
                    currIndexDp[miniTarget] = true;
                    if(miniTarget == target) return true; // Target found
                }
            }
            swap(currIndexDp,prevIndexDp);
        }

        return false;
    }

};

int main(){
    Solution s;
    vector<int> v{2,2,3,5};
    cout << s.canPartition(v);
}