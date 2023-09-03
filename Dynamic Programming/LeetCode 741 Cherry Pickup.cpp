/*
 * Problem Link: https://leetcode.com/problems/cherry-pickup
 * */

#include <bits/stdc++.h>

using namespace std;

// Space-Optimized Tabulation Solution
// Uses less time than 78%
// Uses less space than 100%

class TabulationSolution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int answer = tabulation(grid);
        return answer > 0 ? answer : 0;
    }

private:
    int tabulation(vector<vector<int>>& grid) {
        int n = grid.size();

        // Note that initially this is a 4D dp array problem [row1][row2][col1][col2];
        // We notice that if both paths started from the starting point,at any moment,
        // row1 + col1 = row2 + col2, so we can reduce the number of parameters to 3 and deduce the fourth.
        // Now it is a 3d dp problem (Which is what the recursive solution uses).
        // Trying to optimize the 3d tabulation solution, we find that for each row we only need the
        // Previously computed dp row.
        // So we store only this row as well as a row to store new computed answers in.

        int previousRowDp[50][50];
        int currRowDp[50][50];

        // Initialize both arrays with a large negative value indicating that no path was found to from this cell.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                previousRowDp[i][j] = -1e8;
                currRowDp[i][j] = -1e8;
            }
        }

        // Initialize the destination cell with the value from the grid.
        currRowDp[n - 1][n - 1] = grid[n - 1][n - 1];

        // Loop through the grid from the bottom-right corner (Destination) to the top-left corner (Starting Point).
        for (int r1 = n - 1; r1 >= 0; --r1) {
            for (int c1 = n - 1; c1 >= 0; --c1) {
                for (int c2 = n - 1; c2 >= 0; --c2) {
                    // Calculate the corresponding r2 position
                    int r2 = r1 + c1 - c2;

                    // Terminal case: Out of Bound or Cell With Thrones
                    if (r2 >= n || r2 < 0 || grid[r1][c1] == -1 || grid[r2][c2]) continue;

                    // Initialize choices to a large negative value.
                    int choice1 = -1e8, choice2 = -1e8, choice3 = -1e8, choice4 = -1e8;

                    // Calculate values for different move choices.
                    if (r1 + 1 < n) {
                        if (r2 + 1 < n) choice1 = previousRowDp[c1][c2];   // Down, Down
                        if (c2 + 1 < n) choice2 = previousRowDp[c1][c2 + 1]; // Down, Right
                    }
                    if (c1 + 1 < n) {
                        if (r2 + 1 < n) choice3 = currRowDp[c1 + 1][c2];   // Right, Down
                        if (c2 + 1 < n) choice4 = currRowDp[c1 + 1][c2 + 1]; // Right, Right
                    }

                    // Calculate the maximum value among move choices.
                    int value = max({choice1, choice2, choice3, choice4});
                    int cherries = 0;

                    // Add cherries collected at the current positions.
                    if (r1 == r2 && c1 == c2)
                        cherries += grid[r1][c1];
                    else
                        cherries += grid[r1][c1] + grid[r2][c2];
                    value += cherries;


                    // Update the DP table for the current cell.
                    currRowDp[c1][c2] = max(currRowDp[c1][c2], value);
                }
            }

            // Swap the current and previous row DP tables so that the current row will be the previously computed row for the next one.
            swap(currRowDp, previousRowDp);

            // Reset the current row DP table to -1e8.
            for (int i = 0; i < n; i++) {
                fill(currRowDp[i], currRowDp[i] + n, -1e8);
            }
        }

        return previousRowDp[0][0];
    }

};

// Recursive Solution
// Uses less time than 96%
// Uses less space than 75%
class RecursiveSolution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    memo[i][j][k] = -1;
                }
            }
        }
        int answer = solveRecursive(n,0,0,0,grid);
        return answer > 0 ? answer : 0;
    }

private:
    int memo[51][51][51];
    int solveRecursive(int& n, int r1, int c1, int c2, vector<vector<int>>& grid){
        int r2 = r1 + c1 - c2;
        if(c1 == n || c2 == n || r1 == n || r2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e8;

        if(memo[r1][c1][c2] != -1) return memo[r1][c1][c2];

        if(r1 == n-1 && c1 == n-1) return memo[r1][c1][c2] = grid[r1][c1];

        int p1 = solveRecursive(n,r1+1,c1,c2,grid);
        int p2 = solveRecursive(n,r1+1,c1,c2+1,grid);
        int p3 = solveRecursive(n,r1,c1+1,c2,grid);
        int p4 = solveRecursive(n,r1,c1+1,c2+1,grid);

        int maxPath = max({p1,p2,p3,p4});

        // Add cherries
        if(c1 == c2)
            maxPath += grid[r2][c2];
        else
            maxPath += grid[r2][c2] + grid[r1][c1];

        return memo[r1][c1][c2] = maxPath;
    }};
