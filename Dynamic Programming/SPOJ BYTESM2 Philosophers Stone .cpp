/*
 * Problem link: https://vjudge.net/problem/SPOJ-BYTESM2
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

void Ma7moood() {
    in(n)
    in(m)

    V<VI> g(n,VI(m));
    for(auto&& i:g) cin(i);

    V<VI> dp(n,VI(m));
    fr(i,m) dp[0][i] = g[0][i];

    frr(row,1,n){
        fr(col,m){
            if(col > 0)
                dp[row][col] = dp[row-1][col-1];
            if(col < m-1)
                dp[row][col] = max(dp[row][col], dp[row-1][col+1]);

            dp[row][col] = max(dp[row][col], dp[row-1][col]);

            dp[row][col] += g[row][col];
        }
    }

    cout << *max_element(all(dp[n-1])) <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    cin >> t;
    while (t--) {
        Ma7moood();
    }
}