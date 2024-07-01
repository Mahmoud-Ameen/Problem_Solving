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

void Ma7moud() {
    in(n);
    in(m);
    VI clr(n);cin(clr);
    map<int,set<int>> clrGraph;
    fr(i,m){
        in(u);
        in(v);
        u--;v--;
        if(clr[v] != clr[u]) {
            clrGraph[clr[v]].insert(clr[u]);
            clrGraph[clr[u]].insert(clr[v]);
        }
    }
    sort(all(clr));
    int mx = clr[0];
    for(auto&& p:clrGraph)
        if(p.second.size() > clrGraph[mx].size()) mx = p.first;

    cout << mx <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

//    in(t);
//    while(t--)
        Ma7moud();
}