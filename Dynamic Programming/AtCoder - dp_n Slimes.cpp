
/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_n
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

int n;
VI arr;
VI sum;
V<VI> dp;
const int oo = 1e16;

int solve(int l,int r){
    if(r-l == 1) return 0;

    int& ret = dp[l][r];
    if(ret != -1) return ret;
    ret = oo;

    frr(i,l+1,r){
        ret = min(ret,sum[r]-sum[l] +  solve(l,i) + solve(i, r));
    }
    return ret;
}

void Ma7moud() {
    cin >> n;
    arr.resize(n,0);
    cin(arr);
    sum = VI(n+1);
    frr(i,1,n+1) sum[i] = sum[i-1] + arr[i-1];
    dp = V<VI> (n+1,VI(n+1,-1));

    cout << solve(0,n) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Ma7moud();
}