/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_d
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

    V<VI> dp(n,VI(capacity+1));
    fr(j,capacity+1){
        if(weight[0] <= j) dp[0][j] = value[0];
    }
    frr(i,1,n){
        fr(j,capacity+1){
            if(weight[i] <= j)
                dp[i][j] = max(dp[i-1][j],
                               dp[i-1][j-weight[i]] + value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n-1][capacity] <<endl;
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