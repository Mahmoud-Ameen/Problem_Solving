/*
 * Problem link: https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885
 *
 * This file includes a recursive implementation and a space-optimized tabulation approach.
 * Note that the recursive implementation is faster than the Bottom-Up approach as the Bottom-Up
 * can solve some unneeded sub-problems.
 * */

#include <bits/stdc++.h>

using namespace std;

/* recursive + Memoization */
int solveRecursive(int row, int c1, int c2, int rows, int cols, vector<vector<int>>& grid,
                   vector<vector<vector<int>>>&dp) {

    if(c1 < 0 || c2 < 0 || c1 >= cols || c2 >= cols || row >= rows) return 0;

    if(dp[row][c1][c2] != -1) return dp[row][c1][c2];

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int val = solveRecursive(row + 1, c1 + i, c2 + j, rows, cols, grid, dp) + grid[row][c1];
            if(c1!=c2) val += grid[row][c2];

            dp[row][c1][c2] = max(dp[row][c1][c2],val);
        }
    }

    return dp[row][c1][c2];
}

// Tabulation
int solveTabulation(int r, int c, vector<vector<int>> &grid) {

    // alice,bob
    vector<vector<int>> nextRowDp(c,vector<int>(c));
    for (int row = r-1; row >= 0; --row) {
        vector<vector<int>> currRowDp(c,vector<int>(c));
        for (int aliceCol = 0; aliceCol < c; ++aliceCol) {
            for (int bobCol = 0; bobCol < c; ++bobCol) {
                if(currRowDp[aliceCol][bobCol]!=0) continue;

                int bestPath = 0;
                for (int aliceChange = -1; aliceChange <= 1; ++aliceChange) {
                    for (int bobChange = -1; bobChange <= 1; ++bobChange) {
                        if(aliceCol + aliceChange < 0 || bobCol + bobChange < 0 ||
                           bobCol + bobChange >= c || aliceCol + aliceChange >= c) continue;

                        int val = nextRowDp[aliceCol + aliceChange][bobCol + bobChange] ;
                        if(val > bestPath) bestPath = val;
                    }
                }

                if(aliceCol!=bobCol) bestPath += grid[row][bobCol];

                currRowDp[aliceCol][bobCol] = bestPath + grid[row][aliceCol];

            }
        }
        std::swap(nextRowDp,currRowDp);
    }

    return nextRowDp[0][c-1];
}


int maximumChocolates(int r,int c, vector<vector<int>>& grid){
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

    // Recursive Solution
    return solveRecursive(0,0,c-1,r,c,grid,dp);

    // Tabulation Solution
    return solveTabulation(r,c,grid);
}
