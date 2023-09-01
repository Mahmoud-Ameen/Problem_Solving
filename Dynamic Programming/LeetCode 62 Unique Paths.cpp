/*
 * Problem Link: https://leetcode.com/problems/unique-paths/
 * */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int rows, int cols) {
        vector<vector<int>> dp (rows, vector<int>(cols));

        dp[rows - 1][cols - 1] = 1;
        for (int row = rows - 1; row >= 0 ; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                // Number of paths if decided to move Right
                if(col + 1 < cols)  dp[row][col] += dp[row][col+1];

                // Number of paths if decided to move Down
                if(row + 1 < rows) dp[row][col] += dp[row+1][col];
            }
        }

        return dp[0][0];
    }
};
