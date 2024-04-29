/*
 * Problem link: https://codeforces.com/problemset/problem/534/B
 * Rate: 1400
 * */

#include<bits/stdc++.h>
using namespace std;

int vf,d;
const int noo = -1e8;
vector<vector<int>> dp(1105,vector<int>(105,-1));
int solve(int v, int t){
    if(v < 0) return noo;
    if(t == 1 && v == vf) return v;
    if(t == 1 && v != vf) return noo;

    int& ret = dp[v][t];
    if(~ret) return ret;

    int ans = noo;
    for (int i = -d; i <= d; ++i) {
        ans = max(ans, v + solve(v+i,t-1));
    }

    return ret = ans;
}

int main(){
    int vi,t;
    cin >> vi >> vf >> t >> d;
    cout << solve(vi,t) <<endl;
}