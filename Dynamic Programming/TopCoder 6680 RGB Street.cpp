/*
 * Problem Link: https://vjudge.net/problem/TopCoder-6680
 * Note that a brute-force approach will be accepted with this problem's constraints
 * but this solution solves the problem in linear time instead of exponential.
 * */

#include <bits/stdc++.h>

using namespace std;
class RGBStreet {
    const int mx = 21;
    int n;

    int red[21];
    int green[21];
    int blue[21];

    int dp[21][3];
    void bottomUp(){
        for (int i = 0; i < mx; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = n-1; i >= 0 ; --i) {
            dp[i][0] = min(green[i] + dp[i+1][2], blue[i] + dp[i+1][1]);
            dp[i][1] = min(green[i] + dp[i+1][2], red[i] + dp[i+1][0]);
            dp[i][2] = min(blue[i] + dp[i+1][1], red[i] + dp[i+1][0]);
        }
    }

public:
    int estimateCost(vector<string> homes) {
        n = static_cast<int>(homes.size());
        for (int i = 0; i < n; ++i) {
            istringstream stream(homes[i]);
            stream >> red[i] >> green[i] >> blue[i];
        }

        bottomUp();
        return min(dp[0][0],min(dp[0][1],dp[0][2]));
    }
};
