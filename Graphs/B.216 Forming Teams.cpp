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

int n,m;
VI graph[105];
bool vis[105] = {false};
bool stVis[105] = {false};

bool hasOddCycle(int v, int par, int count){
    if(stVis[v]) return count&1;
    vis[v] = true;
    stVis[v] = true;
    fr(i,graph[v].size()){
        if(graph[v][i] != par && hasOddCycle(graph[v][i],v,count+1)) { stVis[v] = false;return true; }
    }
    stVis[v] = false;
    return false;
}

void Ma7moud() {
    cin >> n >> m;
    fr(i,m){
        in(u);
        in(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    frr(i,1,n+1) if(!vis[i]) ans+= hasOddCycle(i,-1,0);
    if((n-ans)&1) ans++;
    cout << ans <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

//    in(t);
//    while(t--)
        Ma7moud();
}