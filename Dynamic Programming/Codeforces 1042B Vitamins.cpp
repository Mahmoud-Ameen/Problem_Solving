/*
 * Problem link: https://codeforces.com/problemset/problem/1042/B
 * Rate: 1200
 * Category: Bitmasks
 * */

#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e15;

int n;
vector<int> prices;
vector<int> vitamins;

vector<vector<long long>> dp(1005,vector<long long>(9,-1));
long long solve(int index, int mask){
    if(index == n) {
        // Already got all vitamins
        if(__builtin_popcount(mask) == 3) return 0;
        return oo;
    }

    if(dp[index][mask] != -1)
        return dp[index][mask];

    long long leave = solve(index+1,mask);
    for (int i = 0; i < 3; ++i) {
        // If this juice has at least one vitamin that we haven't already got
        if((mask & (1 << i)) == 0 && (((vitamins[index] & (1 << i))!=0))) {
            return dp[index][mask] = min(leave,prices[index] + solve(index,mask | vitamins[index]));
        }
    }

    return dp[index][mask] = leave;
}

int main(){
    cin>> n;

    vitamins.resize(n+1);
    prices.resize(n+1);

    for (int i = 0; i < n; ++i) {
        cin>>prices[i];
        string s;
        cin >> s;
        for (char& ch: s) {
            vitamins[i] |= (1 << (ch-'A'));
        }
    }

    long long ans = solve(0,0);
    if(ans >= oo) cout << -1;
    else cout << ans;
}