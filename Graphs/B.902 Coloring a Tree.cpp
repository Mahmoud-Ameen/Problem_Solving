/*
 * Problem link: https://codeforces.com/problemset/problem/1036/C
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
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;
#define int ll

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

VI clr(1e4+5);
int dfs(int v,int p, V<VI>&g){
    int ans = clr[v] != clr[p];
    for (int& nei:g[v]) {
        if(nei != p){
            ans += dfs(nei,v,g);
        }
    }
    return ans;
}

void Ma7moud() {
    in(n);
    V<VI> g(n+1);

    frr(i,2,n+1){
        in(u);
        g[i].push_back(u);
        g[u].push_back(i);
    }

    fr(i,n) cin >> clr[i+1];
    clr[0] = -1;

    cout<< dfs(1,0,g);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

//    in(t);
//    while(t--)
    Ma7moud();
}