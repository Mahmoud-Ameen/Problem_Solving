//
// Problem link: https://codeforces.com/contest/456/problem/C
//

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> points;

int main(){
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i)
        cin>>points[i];

    sort(points.begin(),points.end());

    vector<vector<long long>> dp(2,vector<long long>(n+1));
    dp[0][0] = 0;
    dp[1][0] = points[0];
    for (int i = 1; i < n; ++i) {
        // TAKE:
        //      Take previous as well (if difference between both not equal 1)
        //          dp[points[i] - points[i-1] != 1][i - 1]
        //      Do not take previous  (if previous not equal this)
        //          points[i-1] != points[i] ?  dp[0][i-1] : 0
        dp[1][i] = points[i] + max(dp[points[i] - points[i-1] != 1][i - 1],
                                   points[i-1] != points[i] ?  dp[0][i-1] : 0);

        // DO NOT TAKE this:
        //      Take previous if previous not equal this
        //            dp[points[i] != points[i-1]][i-1]
        //       Do not take previous as well:
        //            dp[0][i-1]
        dp[0][i] = max(dp[points[i] != points[i-1]][i-1],dp[0][i-1]);
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
}