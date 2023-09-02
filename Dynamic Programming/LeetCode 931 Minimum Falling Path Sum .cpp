/*
 * Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/submissions/
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows;

        /*
         * Space optimized DP solution
         * */

        vector<int> currRowDp(cols);
        vector<int> nextRowDp(cols);

        for (int row = rows-1; row >= 0; --row) {
            for (int col = 0; col < cols; ++col) {

                int choice1 = INT_MAX, choice2 = INT_MAX, choice3 = INT_MAX;


                if(col > 0) choice1 = nextRowDp[col-1];
                choice2 = nextRowDp[col];
                if(col < cols-1) choice3 = nextRowDp[col+1];

                currRowDp[col] = matrix[row][col] + min(choice1, min(choice2,choice3));
            }

            /*
             * next row won't be useful after this point,
             * and current row would be the next row for the next iteration.
             * swap them and let content of nextRow be overwritten as current row.
             * */
            std::swap(currRowDp,nextRowDp);
        }

        int mn = INT_MAX;
        for(int i = 0; i < rows; i++) {
            if (nextRowDp[i] < mn) mn = nextRowDp[i];
        }

        return mn;
    }
};
