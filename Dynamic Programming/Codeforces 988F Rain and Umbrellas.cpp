/*
 * Problem link: https://codeforces.com/problemset/problem/988/F
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

int oo = 1e12;
const int N = 2000+5;
int dp[N][N];

V<int> rain(N);
V<int> weight(N,-1);

int a;
int solve(int i, int umb){
    if(rain[i] && umb == -1) return oo;
    if(i == a) return 0;

    int& ret = dp[i][umb+1];
    if(~ret) return ret;

    ret = oo;
    // is there umb here?
    if(~weight[i]) ret = min(ret, weight[i] + solve(i+1,i));

    // are we carrying? continue
    if(~umb) ret = min(ret,weight[umb] + solve(i+1,umb));

    // go without umb
    ret = min(ret, solve(i+1,-1));

    return ret;
}

void Ma7moud() {
    cin >> (a);
    in(n);
    in(m);
    memset(dp,-1,sizeof (dp));

    fr(i,n) {
        in(l);in(r);
        frr(j,l+1,r+1) rain[j] = true;
    }
    fr(i,m) {
        in(x); in(p);
        weight[x] = min(~weight[x] ? weight[x]: oo,p);
    }

    int ans = solve(0,-1);
    if(ans >= oo) ans = -1;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    Ma7moud();
}