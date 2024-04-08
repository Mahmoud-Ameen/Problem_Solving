/*
 * Problem link: https://codeforces.com/contest/1941/problem/D
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
#define frll(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

set<int> st;
int n,m;
vector<vector<bool>> vis;
void f(int i,int p, VI& c,V<char>&d){
    if(i == m) { // Reached the end of the game
        st.insert((p+1));
        return;
    };

    if(vis[i][p]) return; // Avoid redundant computation
    vis[i][p] = true;

    if(d[i] == '0')
        f(i+1, (p+c[i])%n, c,d); // Pass clockwise

    else if(d[i] == '1')
        f(i+1, (p-c[i]+n)%n, c,d); // Pass AntiClockwise

    else { // Do both
        f(i+1, (p+c[i])%n, c,d);
        f(i+1, (p-c[i]+n)%n, c,d);
    }
}

void Ma7moood(){
    ll x;
    cin >> n >> m >>x;
    VI c(m);
    V<char> d(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }

    vis = vector<vector<bool>>(m,vector<bool>(n+1,false));
    st.clear();

    f(0,x-1,c,d);

    cout << st.size() << endl;
    cout(st);
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){

        Ma7moood();
    }
}