/*
 * problem link: https://codeforces.com/contest/296/problem/C
 * */

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frll(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)
#define PII pair<int,int>
#define PLL pair<ll,ll>

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

long long c(ll n, ll m) {
    long long result(1);
    for (int i = 0; i < m; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

void Ma7moood(){
    ll n,m,t;
    cin >> n >> m >> t;

    ll ans = 0;
    for (int i = 4; i < t; ++i) {
        ans += c(n,i) * c(m,t-i);
    }
    cout << ans <<"\n";
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        Ma7moood();
    }
}