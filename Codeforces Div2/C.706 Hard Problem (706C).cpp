/*
 * Problem link: https://codeforces.com/contest/706/problem/C
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

int n;
VLL cost;
V<string> strings;
V<VLL> dp; // [index][prevReversed?]

void Ma7moood() {
    cin >> n;

    cost = VLL(n);
    cin(cost);

    strings = V<string>(n);
    cin(strings);

    dp =  V<VLL>(n+1,VLL(2,1e15));
    dp[n-1][0] = 0;
    dp[n-1][1] = cost[n-1];
    for (int i = n-2; i >= 0 ; --i) {
        string nextRev = strings[i+1];
        string currRev = strings[i];
        reverse(all(nextRev));
        reverse(all(currRev));

        if(strings[i] <= strings[i+1])
            dp[i][0] = dp[i+1][0];
        if(strings[i] <= nextRev)
            dp[i][0] = min(dp[i][0],dp[i+1][1]);
        if(currRev <= strings[i+1])
            dp[i][1] = cost[i] + dp[i+1][0];
        if(currRev <= nextRev)
            dp[i][1] = min(dp[i][1], cost[i] + dp[i+1][1]);
    }
    ll ans = min(dp[0][0],dp[0][1]);
    if(ans >= (ll)1e15) cout << -1;
    else cout << ans <<endl;
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