/*
 * Problem Link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
 * */

#include <bits/stdc++.h>

using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    points.emplace_back(3);
    vector<vector<int>> dp(n+1,vector<int>(3));
    for (int day = n-1; day >= 0; --day) {

        dp[day][0] = max(points[day][1] + dp[day+1][1], points[day][2] + dp[day+1][2]);
        dp[day][1] = max(points[day][0] + dp[day+1][0], points[day][2] + dp[day+1][2]);
        dp[day][2] = max(points[day][0] + dp[day+1][0], points[day][1] + dp[day+1][1]);

    }
    return max(dp[0][0],max(dp[0][1],dp[0][2]));
}
