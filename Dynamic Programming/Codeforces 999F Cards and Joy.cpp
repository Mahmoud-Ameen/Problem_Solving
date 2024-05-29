/*
 * Problem link: https://codeforces.com/problemset/problem/999/F
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

#define int ll

int noo = 1e12;
V<int> gain(12);

const int N = 10 * 500 + 5;
int k;
int dp[N][N];

// distribute [cards] over [x] players to get max gain
int solve(int cards, int fans){
    if(cards == 0 || fans == 0) return 0;
    if(cards < 0) return noo;

    int& ret = dp[cards][fans];
    if(~ret) return ret;

    ret = 0;
    for (int i = 0; i <= min(cards, k); ++i) {
        ret = max(ret, gain[i] + solve(cards-i, fans - 1));
    }
    return ret;
}

void Ma7moud() {
    in(n);
    cin >> k;

    memset(dp,-1,sizeof(dp));

    map<int,int> fans;
    map<int,int> cards;

    for (int i = 0; i < k*n; ++i) {
        in(num);
        cards[num]++;
    }
    for (int i = 0; i < n; ++i) {
        in(num);
        fans[num]++;
    }
    for (int i = 1; i <= k; ++i) {
        cin >> gain[i];
    }

    int ans = 0;
    for(auto&& p:fans){
        ans+=solve(cards[p.first],p.second);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    Ma7moud();
}