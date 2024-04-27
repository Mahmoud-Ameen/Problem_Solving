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
#define int ll
void Ma7moood() {
    in(n)
    VI a;
    set<int> st;
    fr(i,n){
        in(x);
        if(!st.count(x)) a.push_back(x),st.insert(x);
    }
    sort(all(a));
//    reverse(all(a));
    int m = (int)a.size();

    V<bool> alice(m), bob(m);
    alice[m-1] = bob[m-1] = true;
    for (int i = m-2; i >= 0 ; --i) {
        if((i == 0 && a[i] == 1) || (a[i]-a[i-1] == 1)){
            alice[i] = !bob[i+1];
            bob[i] = !alice[i+1];
        }else{
            alice[i] = alice[i+1] || !bob[i+1];
            bob[i] = bob[i+1] || !alice[i+1];
        }
    }

    if(alice[0]) cout << "Alice\n";
    else cout << "Bob\n";
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