/*
 * Problem link: https://vjudge.net/problem/UVA-10036
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
    in(k)

    VI a(n);
    cin(a);

    fr(i,n) a[i] = abs(a[i]) % k;

    V<V<bool>> dp(n,V<bool>(k));
    dp[0][a[0]] = true;
    /* 17, 5, -21, 15
     *   3 5 0 1
     *   0 1 2 3
     * 0       1
     * 1   1 1
     * 2   1 1 1
     * 3 1     1
     * 4
     * 5
     * 6
     * */
    frr(i,1,n){
        fr(j,k){
            dp[i][j] = dp[i-1][(j-a[i]+k)%k]
                    || dp[i-1][abs(j+a[i])%k];
        }
    }
    if(dp[n-1][0]) cout << "Divisible\n";
    else cout << "Not divisible\n";
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