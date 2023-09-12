/*
 * Problem link: https://codeforces.com/contest/711/problem/C
 * */

#include <bits/stdc++.h>
using namespace std;

int n,m;
long long oo = 1e15;
vector<int> trees;
vector<vector<int>> costs;

vector<vector<vector<long long>>> dp;
long long f(int i, int groups, int prevColor){
    if(i >= n){
        if(groups == 1) return 0;
        else return oo;
    }
    if(groups < 0) return oo;

    if(prevColor >= 0 && (dp[i][groups][prevColor] != -1)) return dp[i][groups][prevColor];

    // Tree to color
    long long mn = oo;
    if(trees[i] == 0){
        for (int color = 1; color <= m; ++color) {
            if(color == prevColor || prevColor == -1)
                mn = min(mn,costs[i][color] + f(i+1,groups, color));
            else
                mn = min(mn,costs[i][color] + f(i+1,groups-1, color));
        }
    }
    // Group continues
    else if(trees[i] == prevColor || (prevColor == -1))
        mn = min(mn,f(i+1,groups,trees[i]));
    // Group Ended
    else
        mn = min(mn,f(i+1,groups-1,trees[i]));

    return (prevColor >= 0 ? dp[i][groups][prevColor] = mn : mn);
}

int main(){
    int k;
    cin >> n>>m>>k;

    trees.resize(n+2);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
    }

    costs.resize(n+1,vector<int>(m+2));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> costs[i][j];
        }
    }

    dp = vector<vector<vector<long long>>> (n+1,vector<vector<long long>>(k+1,vector<long long>(m+5,-1)));

    long long ans = f(0,k,-1);
    if(ans >= oo) cout << -1 << endl;
    else cout << ans<<endl;

    return 0;
}