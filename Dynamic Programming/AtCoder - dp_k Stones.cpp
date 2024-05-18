
/*
 * Problem link: https://vjudge.net/problem/AtCoder-dp_k
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

int n,k;
void Ma7moud() {
    cin >> n >> k;

    VI choices(n);
    cin(choices);

    V<bool>dp(k+1,false);
    dp[0] = false;
    frr(pile,1,k+1){
        frr(j,0,n){
            if(pile - choices[j] >= 0)
                dp[pile] = dp[pile] || !dp[pile-choices[j]];
        }
    }

    if(dp[k]) cout << "First\n";
    else cout << "Second\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Ma7moud();
}