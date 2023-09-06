#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &prices, int totalLength)
{
    int n = int(prices.size());

    vector<int> dp(totalLength + 1);
    for (int index = 1; index < n; ++index) {
        for (int length = index; length <= totalLength; ++length) {
            int notCut = dp[length];
            int cut = prices[index-1] + dp[length-(index)];
            dp[length] = max(cut, notCut);
        }
    }

    return dp[totalLength];
}
