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
const int MOD = 1e8;

int dp[205][205][2];
int k1,k2;
int solve(int n, int m, bool turn){
    if(n == 0 && m == 0) return 1;
    if(n < 0 || m < 0 ) return 0;
    if(turn && !n || (!turn && !m)) return 0;

    int& ret = dp[n][m][turn];
    if(~ret) return ret;

    ret = 0;
    if(turn) frr(i,1,k1+1)
                ret+=solve(n-i,m,false), ret%=MOD;
    else frr(i,1,k2+1)
            ret+=solve(n,m-i, true), ret%=MOD;


    return ret;
}

void Ma7moud() {
    memset(dp,-1,sizeof(dp));

    int n1,n2;
    cin>>n1>>n2>>k1>>k2;
    cout << solve(n1,n2,0) +  solve(n1,n2,1)<< endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}