/*
 * Problem link: https://vjudge.net/problem/UVA-10534
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

void solveLIS(VI & a, VI & dp) {
    int n = a.size();

    int r = 0;
    VI seq(n,1e8);
    fr(i, n) {
        auto idx = lower_bound(seq.begin(), seq.begin() + r, a[i]) - seq.begin();

        seq[idx] = min(a[i],seq[idx]);
        if (idx == r) r++;
        dp[i] = r;
    }
}

void Ma7moood(int n) {
    VI a(n);
    cin(a);

    VI LIS(n,1);
    VI LDS(n, 1);
   
   
    solveLIS(a, LIS);
    
    reverse(all(a));
    solveLIS(a, LDS);
    reverse(all(LDS));

    int ans = 0;
    fr(i, n) if (LIS[i] == LDS[i]) ans = max(LIS[i], ans);

    //cout(LIS); cout << endl;
    //cout(LDS); cout << endl;
    cout << 2 * ans - 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    int n;
    while (cin >> n) {
        Ma7moood(n);
    }
}