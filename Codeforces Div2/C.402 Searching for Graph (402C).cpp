/*
 * problem link: https://codeforces.com/contest/479/problem/B
 * */

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frl(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)
#define PII pair<int,int>
#define PLL pair<ll,ll>

#define in(i) int i;cin>>i;
#define inl(i) ll i;cin>>i;
#define ins(i) string i;cin>>i;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;


void Ma7moood() {
    in(n) in(p)

    V<V<bool>> g(n,V<bool>(n));
    int edges = 2*n+p;
    int perV = edges/n;
    int rem = edges - perV * n;

    set<PII> st;
    fr(i,n) {
        int e = perV, j = 0;
        while(e){
            if(i!=j && !g[i][j]) {
                g[i][j] = true;
                g[j][i] = true;
                st.insert({i+1,j+1});
                e--;
            }
            j++;
        }
    }
    fr(i,n){
        if(!rem) break;
        fr(j,n){
            if(!rem) break;
            if(!g[i][j] && i != j) {
                g[i][j] = g[j][i] = true;
                st.insert({i+1,j+1});
                rem--;
            }
        }
    }
    for(auto&& pair:st){
        cout << pair.first << " " << pair.second <<"\n";
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}