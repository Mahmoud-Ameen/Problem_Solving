/*
 * Problem link: https://vjudge.net/problem/UVA-12346
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
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

// Matrix graph traversals
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

#define int ll
VI cost, rate;
int t;
int solve(int i, int vol) {
    if (i == cost.size() && vol > 0) return 1e14;
    if (vol <= 0) return 0;
    return min(cost[i] + solve(i+1, vol - (rate[i] * t)), solve(i + 1, vol));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    in(n);
    cost.resize(n);
    rate.resize(n);
    fr(i, n) {
        cin >> rate[i] >> cost[i];
    }
    in(m);
    fr(test, m) {
        in(vol);
        cin >> (t);

        int ans = solve(0, vol);

        cout << "Case " << test + 1 << ": ";
        if (ans >= 1e14)
        {
            cout << "IMPOSSIBLE\n";
        }
        
        else cout << ans << "\n";
    }
}