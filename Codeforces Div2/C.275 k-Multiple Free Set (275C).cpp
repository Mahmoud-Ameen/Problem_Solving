/*
 * Problem link: https://codeforces.com/contest/275/problem/C
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
    inl(n) inl(k)

    // 1 3 5 10 6 4 12 8 7 14
    // 14: 7
    // 12: 6, 3
    // 10: 5
    // 8:  4, 2, 1
    VLL nums(n);
    cin(nums);

    if(k == 1) return void(cout << n << "\n");

    set<ll> st;
    sort(all(nums));
    for (int i = 0; i < n; ++i) {
        if(nums[i] % k == 0 && st.count(nums[i]/k)) continue;
        st.insert(nums[i]);
    }
    
    cout << st.size() <<endl;
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