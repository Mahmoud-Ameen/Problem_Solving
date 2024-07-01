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
const int MOD = 1e9+7;

int dp[105][105][2];
int n,k,d;

int f(int i,int sum,bool choseD){
    if(sum > n || i > k) return 0;
    if(sum == n) return choseD;

    int& ret = dp[i][sum][choseD];
    if(~ret) return ret;

    return ret = (f(1,sum+i,choseD || (i >= d))
                    + f(i+1, sum, choseD))%MOD;
}

void Ma7moud() {
    memset(dp,-1,sizeof(dp));

    cin>>n>>k>>d;
    cout << f(1,0,0) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}