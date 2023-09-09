/*
 * Problem link: https://leetcode.com/problems/edit-distance/
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = int(word1.size());
        int m = int(word2.size());

        int dp[n+1][m+1];

        for (int i = 0; i <= n; ++i)
            dp[i][0] = i ;

        for (int i = 0; i <= m; ++i)
            dp[0][i] = i ;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = min(dp[i-1][j-1],1 + dp[i-1][j]);
                else
                    dp[i][j] = 1 + min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] });
            }
        }
        return dp[n][m];
    }
};

class SolutionRecursive {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo (word1.size()+1,vector<int>(word2.size()+1,-1));
        return solveRecursive(word1.size()-1,word2.size()-1,word1,word2,memo);
    }

private:
    int solveRecursive(int i,int j, string& s, string& t,vector<vector<int>>& memo){
        if(i < 0) return j + 1 ;
        if(j < 0) return i + 1;

        if(memo[i][j] != -1) return memo[i][j];

        if(s[i] == t[j]){
            int c1 = solveRecursive(i-1,j-1,s,t,memo);
            int c2 = 1 + solveRecursive(i-1,j,s,t,memo);
            return memo[i][j] = min(c1,c2);
        }

        int c1 = 1 + solveRecursive(i-1,j,s,t,memo);
        int c2 = 1 + solveRecursive(i-1,j-1,s,t,memo);
        int c3 = 1 + solveRecursive(i,j-1,s,t,memo);

        return memo[i][j] = min({c1,c2,c3});
    }
};
