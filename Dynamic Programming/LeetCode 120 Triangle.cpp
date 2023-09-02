/*
 * Problem Link: https://leetcode.com/problems/minimum-path-sum/
 * */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int rows = triangle.size();

        /*
         * Note that on each row to calculate find path to bottom
         * we only need to know minimum path lengths from the next
         * row to the end.
         * Furthermore, When processing cells in a row we don't need the values
         * of indexes before this cell in the next row.
         *
         * So we can use a 1D dp array.
         * */
        vector<int> dp(rows+1);

        for (int row = rows-1; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                int choice1 = dp[col];
                int choice2 = dp[col+1];

                dp[col] = triangle[row][col] + min(choice1,choice2);
            }
        }

        return dp[0];
    }
};
