/*
 * Problem link: https://codeforces.com/contest/490/problem/B
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
    in(n)
    map<int,int> ind;
    map<int,int> m1,m2;
    ind[0] = -1;
    fr(i,n){
        int a,b;
        cin >> a >> b;
        m1[a] = b;
        m2[b] = a;
    }
    VI ans(n);
    int cur = 0;
    int i = 1;
    for (; i < n; i+=2) {
        ans[i] = m1[cur];
        cur = m1[cur];
        if (m1.find(cur) == m1.end() || cur == 0) break;
    }

    for(auto&& p:m2){
        if(m2.find(p.second) == m2.end()) cur = p.second;
    }
    i = 0;

    for (; i < n; i+=2) {
        ans[i] = cur;
        cur = m1[cur];
    }
    cout(ans);
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