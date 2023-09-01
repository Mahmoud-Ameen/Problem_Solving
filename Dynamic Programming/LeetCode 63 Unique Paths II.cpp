/*
 * Problem Link: https://leetcode.com/problems/unique-paths-ii/
 * */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<unsigned int>> dp(rows,vector<unsigned int>(cols));

        if(obstacleGrid[rows-1][cols-1] == 1)
            return 0;

        dp[rows-1][cols-1] = 1;
        for (int row = rows - 1; row >= 0 ; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                if(obstacleGrid[row][col] == 1)
                    continue;

                // Number of paths if decided to move Down
                if(row + 1 < rows)
                    dp[row][col] += dp[row+1][col];

                // Number of paths if decided to move Right
                if(col + 1 < cols)
                    dp[row][col] += dp[row][col+1];
            }
        }

        return dp[0][0];
    }
};