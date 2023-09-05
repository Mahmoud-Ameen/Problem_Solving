/**
 * problem link: https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
 * */

#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{

    int totalSum = 0;
    for (auto& num:nums) {
        totalSum += num;
    }

    vector<int> currIndexDp(totalSum+5,0);
    vector<int> prevIndexDp(totalSum+5,0);

    prevIndexDp[0] = 1;
    currIndexDp[0] = 1;


    prevIndexDp[nums[0]] = 1;

    for (int index = 1; index < n; ++index) {
        int element = nums[index];
        for (int miniTarget = 0; miniTarget <= totalSum; ++miniTarget) {
            if((miniTarget >= element && prevIndexDp[miniTarget - element]) || prevIndexDp[miniTarget])
                currIndexDp[miniTarget] = 1;
        }
        swap(currIndexDp,prevIndexDp);
    }

    for (int i = totalSum/2; i >= 0; --i) {
        if(prevIndexDp[i]) return abs(totalSum - i - i);
    }
}
