/*
 * Problem link: https://codeforces.com/contest/230/problem/B
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

int n,m,k;
bool valid(int i,int j){
    return i < n && j < m && i >= 0 && j >= 0;
}

void dfs(int i, int j,V<string>& g, V<V<bool>>&vis){
    if(!valid(i,j) || '#' == g[i][j] || vis[i][j]) return;

    vis[i][j] = true;
    fr(x, 4){
        dfs(i+dx[x], j+dy[x], g, vis);
        if(!k) return;
    }
    g[i][j] = 'X';
    k--;
}

void Ma7moood() {
    cin >> (n)>> m >> k;

    V<string> a(n);
    cin(a);

    V<V<bool>> vis(n,V<bool>(m));

    for (int i = 0; i < n; ++i) {
        bool done = false;
        for (int j = 0; j < m; ++j) {
            if(a[i][j] == '.'){
                dfs(i,j,a,vis);
                for(auto&& s:a) cout<<s << endl;
                return;
            }
        }
    }

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