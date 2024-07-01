/*
 * Problem link: https://codeforces.com/problemset/problem/1154/F
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

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////
#define int ll

int dp[200000+5][4];
string s;
int n;

int solve(int i, int rem){
    if(i == n) return 0;

    int& ret = dp[i][rem];
    if(~ret) return ret;

    int newRem = (rem+(s[i]-'0'))%3;

    if(s[i] == '0' && rem == 0 || newRem == 0)
        return ret = 1 + solve(i+1,0);

    return ret = max(solve(i+1,newRem),solve(i+1,0));
}

void Ma7moud() {
    memset(dp,-1,sizeof(dp));
    cin >> s;
    n = s.size();
    cout<<solve(0,0)<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);;

    Ma7moud();
}