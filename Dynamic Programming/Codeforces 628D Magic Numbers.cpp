/*
 * Problem link: https://codeforces.com/problemset/problem/1036/C
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
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;
#define int ll

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

string s;
int dp[5][2];
int solve(int idx, bool tight){
    if(idx == s.size()) return 1;

    int& ans = dp[idx][tight][rem];
    if(~ans) return ans;
    ans = 0;

    int end = 9;
    if(tight) end = s[idx]-'0';
    for (int i = 0; i <= end ; ++i)
        ans+=solve(idx+1, tight && (i == end), rem - (i != 0));

    return ans;
}

void Ma7moud() {
    ll l,r;
    cin >> l >> r;

    memset(dp,-1,sizeof(dp));
    s = to_string(r);
    int a = solve(0,true , 3);
    memset(dp, -1 , sizeof(dp));
    s = to_string(l-1);
    int b = solve(0,true,3);
    cout << a - b << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    in(t);
    while(t--)
        Ma7moud();
}