/*
 * Problem link: https://codeforces.com/contest/1966/problem/A
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
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

void Ma7moood() {
    in(n)
    in(m)
    V<string> g(n);cin(g);


    bool wa = false;
    bool wb = false;
    bool ba = false;
    bool bb = false;
    fr(i,n){
        if(g[i][0] == 'W') wa = true;
        if(g[i][0] == 'B') ba = true;
    }
    fr(i,m){
        if(g[0][i] == 'W') wb = true;
        if(g[0][i] == 'B') bb = true;
    }

    bool wc = false;
    bool wd = false;
    bool bc = false;
    bool bd = false;
    fr(i,n){
        if(g[i][m-1] == 'W') wc = true;
        if(g[i][m-1] == 'B') bc = true;
    }
    fr(i,m){
        if(g[n-1][i] == 'W') wd = true;
        if(g[n-1][i] == 'B') bd = true;
    }
    if(wa&& wb && wc&&wd) cyes;
    else if(ba&& bb && bc&&bd) cyes;
    else cno;


//    cout << ans <<endl;
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