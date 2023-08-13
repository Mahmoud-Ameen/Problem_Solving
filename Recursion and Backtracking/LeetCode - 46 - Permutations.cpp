/*
 * problem link: https://leetcode.com/problems/permutations/
 * */

#include <vector>
#include <string>

using namespace std;


class Solution {
public:

    vector<vector<int>> permute(vector<int>& inputNums) {
        vector<int> combination;
        nums = inputNums;

        initUsed(inputNums.size());

        permuteRecursive(combination);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int>nums;

    // create a vector of booleans to keep track of what numbers was selected in eah path
    // by default all elements wasn't selected
    vector<bool>used;
    void initUsed(int size){
        used.reserve(size);
        for(int i = 0; i < size ;i++){
            used[i] = false;
        }
    }


    void permuteRecursive(vector<int>& combination) {
        // terminal condition
        if (combination.size() == nums.size()) {
            result.push_back(combination);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!used[i]) {
                // Mark the current number as used
                used[i] = true;
                combination.push_back(nums[i]);

                // Recurse with the updated combination and used array
                permuteRecursive( combination);

                // Revert the changes for the next iteration
                combination.pop_back();
                used[i] = false;
            }
        }
    }
};