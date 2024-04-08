/*
 * Problem link: https://codeforces.com/contest/1945/problem/D
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

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

using namespace std;

ll minimalDestination(VLL& a, VLL& b, int i){
    if(i == 0) return a[0];
    return min(a[i], b[i] + minimalDestination(a, b, i - 1));
}
void Ma7moood(){
    int n,m;
    cin >> n >> m;

    VLL a(n), b(n);
    cin(a);
    cin(b);

    ll ans = 0;
    for (int i = n-1; i >= m; --i) // Cost of all people before first m
        ans += min(a[i],b[i]);

    ans += minimalDestination(a, b, m - 1);

    cout << ans <<endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        Ma7moood();
}