/*
 * Problem link: https://codeforces.com/contest/1946/problem/A
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
// O(n)

void Ma7moood() {
    const ll mod = 1e9+7;

    inl(n) inl(k)
    VLL a(n);
    cin(a);


    // largest positive
    ll psum = 0, mxSum = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=a[i];
        psum+=a[i];

        if(psum < 0) psum = 0;

        mxSum = max(psum,mxSum);
    }


    sum -= mxSum;
    sum = sum % mod;
    mxSum = mxSum % mod;
    while(k--) {
        mxSum *= 2; mxSum = mxSum % mod;
    }

    cout << (sum + mxSum + mod) % mod <<endl;
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