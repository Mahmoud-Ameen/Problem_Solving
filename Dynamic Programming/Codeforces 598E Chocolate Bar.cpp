
/*
 * Problem link: https://codeforces.com/problemset/problem/598/E
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>

// Data types/structures
#define ll long long
#define ull unsigned long long
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int,int>
#define PLL pair<ll,ll>

// Loops/ iterators
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frl(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

// input/output
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

int oo = 1e8;
const int N = 31,K=51;
int dp[N][N][K];

int solve(int n, int m, int k){
    if(n*m < k) return oo;
    if(n*m == k) return 0;
    if(k==0) return 0;

    if(dp[n][m][k] != -1) return dp[n][m][k];

    int sol = oo;
    for (int i = 1; i < n; ++i) {
        for (int t1 = 0; t1 <= k; ++t1) {
            sol = min(sol,m*m + solve(i,m,t1) + solve(n-i,m,k-t1));
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int t1 = 0; t1 <= k; ++t1) {
            sol = min(sol,n*n + solve(n,i,t1) + solve(n,m-i,k-t1));
        }
    }

    return dp[n][m][k] = sol;
}

void Ma7moud() {
    in(n);
    in(m);
    in(k);

    cout << solve(n,m,k) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp,-1,sizeof (dp));
    in(t);
    while(t--)
    Ma7moud();
}