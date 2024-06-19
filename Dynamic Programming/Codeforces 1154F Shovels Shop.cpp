/*
 * Problem link: https://codeforces.com/problemset/problem/1154/F
 * */

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

int n,m,k;
VI sum(2e5+1);
VI offers(2e5+1);

// K = 8
// 1 1 1 1 2 5 6 8 8
// r = 8,ki = 5 => l = (K-ki)

// 1-indexed

int dp[2002][2002];

int solve(int r, int ki){
    if(ki == 0) return 0;
    if(ki < 0 || r > k) return 1e12;

    int& ret = dp[r][ki];
    if(~ret) return ret;

    int l = k - ki + 1;
    int take = sum[r] - sum[l-1 + offers[r - l + 1]] + solve(r+1,ki-(r-l+1));

    return ret = min(take, solve(r+1,ki));
}

void Ma7moud() {
    memset(dp,-1,sizeof(dp));

    cin >> n >> m >> k;
    VI shovels(n);
    fr(i,n) cin >> shovels[i];
    sort(all(shovels));

    fr(i,m){
        in(buy);
        in(off);
        offers[buy] = max(off,offers[buy]);
    }

    frr(i,1,n+1) sum[i] = shovels[i-1] + sum[i-1];
    cout << solve(1,k);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}