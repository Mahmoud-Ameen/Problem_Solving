/*
 * Problem link: https://codeforces.com/problemset/problem/1176/E
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

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

const int N = 2e5+5;
V<VI>g;
bool vis[N] = {false};
VI a,b;

void dfs(int v, bool aa){
    vis[v] = true;

    if(aa) a.push_back(v);
    else b.push_back(v);

    for (int& i:g[v])
        if(!vis[i])
            dfs(i,!aa);
}

void Ma7moud() {
    g.clear();
    a.clear();
    b.clear();
    memset(vis,false,sizeof(vis));

    in(n);
    in(m);
    g.resize(n+1);

    fr(i,m){
        in(u);
        in(v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,false);
    if(a.size() <= b.size()){
        cout << a.size() <<endl;
        cout(a);
        cout << endl;
    }else {
        cout << b.size() <<endl;
        cout(b);
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    in(t);
    while(t--)
    Ma7moud();
}