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

void sieve(ll n, set<ll>& primes) {
    std::vector<bool> v(n+1);
    v[0] = v[1] = true;
    for (ll i = 2; i * i <= n; i++) {
        if (!v[i])
            for (ll j = i * i; j <= n; j += i)
                v[j] = true;
    }

    for (ll i = 2; i <= n; ++i) {
        if(!v[i]) primes.insert(i*i);
    }
}

void Ma7moood() {
    inl(n)
    VLL a(n);
    cin(a);
    set<ll> st;
    sieve(1e6,st);
    fr(i,n){
        if(st.count(a[i])) cyes;
        else cno;
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