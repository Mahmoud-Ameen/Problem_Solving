/*
 * Problem link:
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
const int noo = -1e15;

int dp[205][205];
int gain[205];
int n,x,k;

int solve(int i, int xi){
    if(xi < 0 || i > n) return noo;
    if (i == n) return 0;

    int& ret = dp[i][xi];
    if(~ret) return ret;

    ret = noo;
    frr(j, i, i+k) {
        if(j == n) ret = max(0ll,ret);
        ret = max(ret, gain[j] + solve(j + 1, xi - 1));
    }
    return ret;
}

void Ma7moud() {
    memset(dp,-1,sizeof(dp));

    cin>>n>>k>>x;
    fr(i,n)cin>>gain[i];

    int ans = solve(0, x);
    if(ans < 0) ans = -1;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}