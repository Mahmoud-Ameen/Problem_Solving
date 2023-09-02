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
         * So no need to use a 2D dp matrix.
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

int main(){
    Solution s;
    vector<vector<int>> v{
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
    };

    cout << s.minimumTotal(v);
}