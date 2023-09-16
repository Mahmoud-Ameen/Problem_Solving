/*
 * Problem link: https://codeforces.com/contest/474/problem/D
 * Rate: 1700
 * Category: Counting Dp + Prefix sum
 * */

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const int maxFlowers = 100000;

int k;
vector<long long> dp(100000+5);

int main(){
    int t;
    cin >>t >> k;

    dp[0] = 1;
    for (int flowers = 1; flowers <= maxFlowers; ++flowers) {
        dp[flowers] = dp[flowers - 1];
        if(flowers >= k) {
            dp[flowers] += dp[flowers - k];
            dp[flowers] %= mod;
        }
    }

    // Cumulative sum
    for (int i = 1; i <= maxFlowers; ++i) {
        dp[i] += dp[i-1];
    }

    while(t--){
        int b,a;
        cin>>a>>b;

        cout << (dp[b] - dp[a-1]) % mod <<endl;
    }
}