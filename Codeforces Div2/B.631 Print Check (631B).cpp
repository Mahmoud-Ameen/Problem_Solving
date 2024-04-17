/*
 * Problem link: https://codeforces.com/contest/631/problem/B
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

void Ma7moood() {
    inl(n)
    inl(m)
    inl(k)
    V<VI> ops(k,VI(3));
    fr(i,k) cin(ops[i]);

    V<bool> rows(n);
    V<bool> cols(m);

    V<VI> g(n,VI(m));

    reverse(all(ops));
    fr(i,k){
        ops[i][1]--;
        if(ops[i][0] == 1 && rows[ops[i][1]]) continue;
        if(ops[i][0] == 2 && cols[ops[i][1]]) continue;
        if(ops[i][0] == 1) {
            rows[ops[i][1] ] = true;
            fr(j,m)
                if(!g[ops[i][1]][j])
                    g[ops[i][1]][j] = ops[i][2];
        }
        if(ops[i][0] == 2) {
            cols[ops[i][1]] = ops[i][2];
            fr(j,n)
                if(!g[j][ops[i][1]])
                    g[j][ops[i][1]] = ops[i][2];
        }
    }
    for(auto&& v:g) { cout (v); cout <<endl; }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}