
/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_I
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

#define int ll

int n,k;
VI arr;
V<VI> dp;
int solve(int l, int r){
    if(l>r) return 0;
    if(dp[l][r] != -1) return dp[l][r];

    return dp[l][r] = max(arr[l] - solve(l+1,r), arr[r] - solve(l,r-1));
}

void Ma7moud() {
    cin >> n;

    arr = VI(n);
    cin(arr);

    dp = V<VI>(n,VI(n,-1));
    cout << solve(0,n-1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Ma7moud();
}