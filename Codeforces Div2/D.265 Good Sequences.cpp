/*
 * Problem link: https://codeforces.com/problemset/problem/265/D
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

const int N = 1e5+5;
VI dp (N,-1);

int dfs(int v, V<VI>& g) {
    if (dp[v]!=-1) return dp[v];

    int ans = 0;
    for (int a : g[v])
        ans = max(ans, dfs(a, g));

    return dp[v] = 1 + ans;
}

void Ma7moud() {

    in(n);
    VI a(n);
    cin(a);

    set<int> st(all(a));
    V<VI> g(N);

    vector<bool> v (N + 1);
    v[0] = v[1] = true;
    for (ll i = 2; i <= N; i++) {
        if (v[i]) continue;

        int last = -1;
        for (ll j = i; j <= N; j += i) {
            v[j] = true;
            if (st.count(j) && last == -1)
                last = j;
            else if(st.count(j)) {
                g[last].push_back(j);
                last = j;
            }
        }
    }
    int mx = 1;
    fr(i,N+1)
        if(st.count(i))
            mx = max(mx, dfs(i, g));

    cout << mx << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}