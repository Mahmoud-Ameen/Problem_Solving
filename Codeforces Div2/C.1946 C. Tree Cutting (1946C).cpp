/*
 * Problem link: https://codeforces.com/contest/1946/problem/C
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
#define cyes cout << "YES\n";
#define cno cout << "NO\n";

// Matrix graph traversals
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

V<VI> tree;
int cuts;
int dfs(int v, int p, int x){
    int size = 1;
    for(auto&& ch: tree[v]){
        if(ch == p) continue;
        size += max(0, dfs(ch,v,x));
    }
    if(size >= x && p != -1 ) cuts++,size = 0;
    return size;
}

void Ma7moood() {

    in(n) in(k)
    tree = V<VI>(n);
    fr(i,n-1){
        in(s) in (d);
        tree[s-1].push_back(d-1);
        tree[d-1].push_back(s-1);
    }

    int st = 1, end = n;
    int ans = 0;
    while(st <= end){
        cuts = 0;
        int cc = (st+end)/2;
        int sz = dfs(0,-1,cc);
        if(sz < cc) cuts--;
        if(cuts >= k) ans = cc, st = cc + 1;
        else end = cc - 1;
    }
    cout << ans <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}