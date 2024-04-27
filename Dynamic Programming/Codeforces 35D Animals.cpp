/*
 * Problem link: https://codeforces.com/problemset/problem/35/D
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

void Ma7moud() {
    in(n);
    in(x);

    VI animals(n);
    cin(animals);
    fr(i, n) animals[i] *= (n - i);

    VI dp((x + 1));
    VI prev((x + 1));

    fr(i, n) {
        fr(j, x + 1) {
            if (j >= animals[i])
                dp[j] = max(prev[j], prev[j - animals[i]] + 1);
            else dp[j] = max(dp[j], prev[j]);
        }
        swap(prev, dp);
    }

    cout << prev[x] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Ma7moud();
}