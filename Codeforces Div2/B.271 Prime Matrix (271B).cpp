/*
 * Problem link: https://codeforces.com/contest/271/problem/B
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

void Ma7moood() {
    in(n)
    in(m)
    V<VI> g(n,VI(m));
    for(auto&& i:g) cin(i);

    VI primes;
    const int N = 2e5;
    V<bool> v(N+1);
    v[0] = v[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!v[i])
            for (int j = i * i; j <= N; j += i)
                v[j] = true;
    }

    for (int i = 2; i <= N; ++i) {
        if(!v[i]) primes.push_back(i);
    }

    ll ans = 1e9;
    for (int row = 0; row < n; ++row) {
        ll cost = 0;
        for (int col = 0; col < m; ++col) {
            cost += *lower_bound(all(primes),g[row][col]) - g[row][col];
        }
        ans = min(ans,cost);
    }
    for (int col = 0; col < m; ++col) {
        ll cost = 0;
        for (int row = 0; row < n; ++row) {
            cost += *lower_bound(all(primes),g[row][col]) - g[row][col];
        }
        ans = min(ans,cost);
    }
    cout << ans <<endl;
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