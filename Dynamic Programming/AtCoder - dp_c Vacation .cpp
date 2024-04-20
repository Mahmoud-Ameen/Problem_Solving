/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_c
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
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

void Ma7moood() {
    in(n)
    VI a(n), b(n), c(n);

    fr(i,n) cin>>a[i] >> b[i] >> c[i];

    V<VI> dp(n+1,VI(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    frr(i,1,n){
        dp[i][0] = a[i] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][1],dp[i-1][0]);
    }
    cout << *max_element(all(dp[n-1])) <<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}