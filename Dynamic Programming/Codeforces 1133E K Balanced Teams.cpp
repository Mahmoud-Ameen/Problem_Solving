
/*
 * Problem link: https://codeforces.com/problemset/problem/1133/E
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

int n,k;

VI arr;
V<VI> dp;
VI gain;

int solve(int i, int rem){
    if (i == n || rem == 0) return 0;

    if(dp[i][rem] != -1) return dp[i][rem];

    return dp[i][rem] = max(solve(i+1,rem),
                            gain[i] + solve(i + gain[i],rem-1));
}

void Ma7moud() {
    cin >> n >> k;

    arr.resize(n,0);
    cin(arr);
    sort(all(arr));

    gain = VI(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(arr[j] - arr[i] <= 5) gain[i]++;
            else break;
        }
    }

    dp = V<VI>(n+1,VI(k+1,-1));

    cout << solve(0,k) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Ma7moud();
}