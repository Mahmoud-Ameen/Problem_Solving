/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_e
 * */

#include <iostream>
#include <vector>
#include <algorithm>

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
#define in(i) int i;cin>>i;
#define inl(i) ll i;cin>>i;
#define ins(i) string i;cin>>i;
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

// Matrix graph traversals
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

#define int ll

void Ma7moood() {
    in(n)
    in(capacity)

    VI weight(n), value(n);
    fr(i,n) cin >> weight[i] >> value[i];

    const int mxValue = 1e5+5;

    V<VI> dp(n+1,VI(mxValue,capacity+10));

    dp[0][value[0]] = weight[0];
    fr(i,n) dp[i][0] = 0;

    frr(i,1,n){
        frr(j,0,mxValue){
            if(j >= value[i])
                dp[i][j] = min(dp[i-1][j],
                           dp[i-1][j-value[i]] + weight[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    ll ans = 0;
    fr(i,mxValue) if(dp[n-1][i] <= capacity) ans = i;
    cout << ans <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    //    cin >> t;
    while (t--) {
        Ma7moood();
    }
}