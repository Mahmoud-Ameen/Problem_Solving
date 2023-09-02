/*
 * Problem Link: https://leetcode.com/problems/minimum-path-sum/
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp (rows,vector<int>(cols));

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                dp[row][col] = grid[row][col];

                int rightPath = INT_MAX, downPath = INT_MAX;

                // Minimum path length from right cell to end  (if exists)
                if(col + 1 < cols) rightPath = dp[row][col+1];
                // Minimum path length from bottom cell to end (if exists)
                if(row + 1 < rows) downPath = dp[row+1][col];

                if(rightPath == INT_MAX && downPath == INT_MAX) continue;

                dp[row][col] += min(rightPath,downPath);
            }
        }

        return dp[0][0];
    }
};