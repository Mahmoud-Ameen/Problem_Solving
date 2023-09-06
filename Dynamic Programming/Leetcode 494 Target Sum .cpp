/*
 * Problem Link: https://leetcode.com/problems/target-sum/
 * */

#include <bits/stdc++.h>
using namespace std;

/*
 * This problem is the same as Partitions With Given Difference
 * Where one subset contains the numbers to have + sign,
 * and the other contains numbers to have - sign;
 * */
// Beats 100%
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
    /*
     * Partitions With Given Difference Code
     * */
    int countPartitions(int n, int d, vector<int> &arr) {
        sort (arr.begin(),arr.end());
        int totalSum = 0;

        for(int i=0;i<n;i++)
            totalSum+=arr[i];

        // Let sum of partition 1 be X and sum of partition 2 be y;
        // i)  X+Y = totalSum
        // ii) X-Y = d -> X = Y+d
        // By substituting with (ii) in (i) :
        // => Y + (Y+d) = totalSum
        // => 2Y = totalSum - d
        // => Y = (totalSum - d)/2
        int partitionSum = (totalSum - d) / 2;

        // Sum cant be divided to two partitions / target greater than sum
        if((totalSum - d) % 2 || partitionSum < 0) return 0;

        vector<int> prevDp(partitionSum+1);
        vector<int> currDp(partitionSum+1);

        prevDp[0] = 1;
        for (int index = 0; index < n; ++index) {
            int num = arr[index];
            for (int sum = 0; sum <= partitionSum; ++sum) {
                currDp[sum] = prevDp[sum];

                if(sum - num >= 0) {
                    currDp[sum] += prevDp[sum-num];
                    currDp[sum] %= int(1e9+7);
                }
            }
            swap(prevDp,currDp);
        }

        // Note that if there exists n subsets of sum [PartitionSum]
        // then there exists n subsets of sum [PartitionSum+d]
        return prevDp[partitionSum];
    }

};

// Much Slower
class RecursiveSolution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> memo(nums.size());
        return f(nums,0,target,nums.size(),memo);
    }

    int f(vector<int>& nums,int index,int target, int n,vector<unordered_map<int,int>>& memo){
        if(index == n) return target == 0;
        if(memo[index].find(target) != memo[index].end()) return memo[index][target];

        int minus = f(nums,index+1,target+nums[index],n,memo);
        int plus = f(nums,index+1,target-nums[index],n,memo);

        return memo[index][target] = minus + plus;
    }
};
