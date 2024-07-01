/*
 * Problem link: https://codeforces.com/problemset/problem/29/C
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
    map<int,VI> g;
    fr(i,n)
    {
        in(u);
        in(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st = -1;
    for (auto& p:g) {
        if(p.second.size() == 1) st = p.first;
    }

    int v = st;
    int p = -1;
    while(g[v].size() == 2 || v==st){
        cout << v <<" ";
        for (int& ch:g[v]) {
            if(ch!=p) { p = v; v = ch;break; }
        }
    }
    cout << v <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

//    in(t);
//    while(t--)
    Ma7moud();
}