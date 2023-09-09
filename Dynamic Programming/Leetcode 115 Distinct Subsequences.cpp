//
// Problem link: https://leetcode.com/problems/distinct-subsequences/
//

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int numDistinct(string s, string t) {
        double dp[s.size()+1][t.size()+1];

        // Initialize dp table with base cases and initial values
        for(auto& row: dp)
            for(auto& e:row)
                e = 0;

        for (int i = 0; i <= s.size(); ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[s.size()][t.size()];
    }
};


class SolutionRecursive {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(),vector<int>(t.size(),-1));

        return solveRecursive(s.size()-1, t.size(), s, t, memo);
    }

private:

    int solveRecursive(int i, int j, string &s, string &t, vector<vector<int>> &memo) {

        if(j < 0) return 1;
        if(i < 0) return 0;

        if(memo[i][j]!=-1) return memo[i][j];

        if(s[i] == t[j]) {
            int c1 = solveRecursive(i - 1, j, s, t, memo);
            int c2 = solveRecursive(i - 1, j - 1, s, t, memo);
            return memo[i][j] = c2 + c1;
        }

        return memo[i][j] = solveRecursive(i - 1, j, s, t, memo) ;
    }
};

