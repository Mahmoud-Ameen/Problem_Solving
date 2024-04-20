/*
 * Problem link: https://codeforces.com/contest/1691/problem/C
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
    V<PII> v(n);
    fr(i,n){
        cin>>v[i].first;
        v[i] .second = i+1;
    }

    sort(all(v));

    VI ans (n);
    fr(i,n){
        int d = 0;
        while(i + d < n && v[i+d].first == v[i].first) d++;
        if(d == 1) return void(cout <<"-1" << endl);

        frr(j,0,d){
            ans[v[i+j].second-1] = v[i+(j+1)%(d)].second;
        }
        i = i +d-1;
    }
    cout(ans); cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int t = 1;
    cin >> t;
    while(t--){
        Ma7moood();
    }
}