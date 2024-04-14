/*
 * Problem link: https://codeforces.com/contest/580/problem/C
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

V<VI> tree;
VI cats;
int m;
int ways(int v, int consecutive, int p){
    if(!cats[v]) consecutive = 0;
    else consecutive++;

    if(consecutive > m) return 0;

    int ans = 0;
    int children = 0;
    for(auto&& ch:tree[v]) {
        if(p == ch) continue;
        children++;
        ans += ways(ch, consecutive, v);
    }
    if(!children) return 1;
    return ans;
}

void Ma7moood() {

    in(n)
    cin >> m;
    cats = VI(n);
    cin(cats);

    tree = V<VI>(n);
    fr(i,n-1){
        in(s) in(d)
        tree[s-1].push_back(d-1);
        tree[d-1].push_back(s-1);
    }
    cout << ways(0,0,-1) <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}