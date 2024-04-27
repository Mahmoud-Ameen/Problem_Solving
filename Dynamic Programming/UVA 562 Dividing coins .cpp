/*
 * Problem link: https://vjudge.net/problem/UVA-562
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
    VI coins(n);
    cin(coins);

    int N = 500 * 100 + 5;

    V<bool> dp(N),prev(N);

    dp[0] = true;
    prev[0] = true;
    int sum = 0;
    fr(i,n){
        sum+=coins[i];
        fr(val,N)
            if(coins[i]<=val) {
                dp[val] = prev[val] || prev[val - coins[i]];
            }
        swap(dp,prev);
    }

    if(!n) return void(cout << 0 <<"\n");
    int ans = 1e7;
    fr(i,N) if(prev[i]) ans = min(ans, abs(i - (sum-i)));

    cout << ans << "\n";
}

signed main() {

    int t = 1;
    cin >> t;
    while (t--) {
        Ma7moood();
    }
}