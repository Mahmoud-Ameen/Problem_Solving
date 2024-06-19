/*
 * Problem link: https://codeforces.com/problemset/problem/1625/C
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

const int oo = 1e12;
const int N = 505;

int n, l, k;
int coords[N], limits[N];
int dp[N][N];

// i starts at 1
int solve(int i, int ki){
    if(i > n || ki < 0) return oo;
    if(i == n) return 0;

    int&ret = dp[i][ki];
    if(~ret) return ret;

    ret = oo;
    frr(j,0,ki+1){
        if(i+1+j > n) break;

        int gain = (coords[i+1+j]-coords[i]) * limits[i];
        ret = min(ret,  gain + solve(i+1+j,ki-j));
    }

    return ret;
}

void Ma7moud() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> l >> k;
    fr(i,n) cin >> coords[i];
    fr(i,n) cin >> limits[i];
    coords[n] = l;

    cout << solve(0,k) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}