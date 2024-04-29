/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_g
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

const int N = 1e5 + 5;
VI dp(N, -1);

int dfs(int v, V<VI>& g) {
    if (dp[v] != -1) return dp[v];

    int ans = 0;
    for (int a : g[v])
        ans = max(ans,1 + dfs(a, g));

    return dp[v] = ans;
}

void Ma7moud() {

    in(n);
    in(m);

    V<VI> g(n+1);
    fr(i, m) {
        in(s);
        in(d);
        g[s].push_back(d);
    }

    frr(i,1, n + 1) dfs(i, g);
    cout << *max_element(all(dp)) <<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}