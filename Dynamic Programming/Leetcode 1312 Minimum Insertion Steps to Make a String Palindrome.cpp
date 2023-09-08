/*
 * Problem link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = int(s.size());

        // STEP1:
        // Identify State: startIndex , endIndex
        int dp[n+1][n+1];

        // Fill table with base-case:
        // Base case: single elements need 0 insertions
        for(auto& d: dp)
            for(auto& e : d)
                e = 0;

        // STEP 3:
        // Start by solving smallest sub-problems that only depends on the base case
        //      (sub-problems with size 2)
        // and then the ones depending only on them (sub-problems with size 3)
        // and go upwards toward the initial big problem (size n)
        for (int len = 2; len <= n; ++len) {
            for (int start = 0; len + start - 1 < n; ++start) {
                int end = len + start - 1;
                if(s[start] == s[end])
                    dp[start][end] = dp[start+1][end-1];
                else
                    dp[start][end] = 1 + min(dp[start+1][end],dp[start][end-1]);
            }
        }


        return dp[0][n-1];
    }

};

class SolutionRecursive {
public:
    int minInsertions(string s) {
        memo = vector<vector<int>>(s.size(),vector<int>(s.size(),-1));
        return solveRecursive(s, 0, s.size() - 1);
    }

private:
    vector<vector<int>> memo;
    int solveRecursive(string& s, int i , int j){
        if(i>=j) return 0;

        if(memo[i][j]!=-1) return memo[i][j];

        if(s[j] == s[i])
            return memo[i][j] = solveRecursive(s, i + 1, j - 1);

        return memo[i][j] = 1 + min(solveRecursive(s, i + 1, j), solveRecursive(s, i, j - 1));
    }
};
